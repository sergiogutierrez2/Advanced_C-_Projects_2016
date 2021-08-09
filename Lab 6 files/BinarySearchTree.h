//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* BinarySearchTree.h

*/
//============================================================================

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <cstddef>
#include <string>
#include <assert.h>
#include <iostream>
#include <fstream>

using namespace std;

template <class bstitem>
class BinarySearchTree
{
    private:
        struct Node
        {
                bstitem data;
                Node* left;
                Node* right;

                Node(bstitem newdata): data(newdata), left(NULL), right(NULL) {}
        };

        typedef struct Node* NodePtr;
        NodePtr root;
        int size;


        /**Private helper functions*/

        NodePtr removeHelper(NodePtr root, bstitem value);


        bool findHelper(NodePtr root, bstitem value);

        void insertHelper(NodePtr root, bstitem value);
        //private helper function for insert
        //recursively inserts a value into the BST

        /*void inOrderPrintHelper(NodePtr root);
        //private helper function for inOrderPrint
        //recursively prints tree values in order from smallest to largest

        void preOrderPrintHelper(NodePtr root);
        //private helper function for preOrderPrint
        //recursively prints tree values in preorder

        void postOrderPrintHelper(NodePtr root);
        //private helper function for postOrderPrint
        //recursively prints tree values in postorder*/

        void inOrderPrintHelper(NodePtr root, ofstream& file);
        //private helper function for inOrderPrint
        //recursively prints tree values in order from smallest to largest

        void preOrderPrintHelper(NodePtr root, ofstream& file);
        //private helper function for preOrderPrint
        //recursively prints tree values in preorder

        void postOrderPrintHelper(NodePtr root, ofstream& file);
        //private helper function for postOrderPrint
        //recursively prints tree values in postorder

        bstitem minimumHelper(NodePtr root);

        bstitem maximumHelper(NodePtr root);

        void copyHelperFunction(NodePtr root, NodePtr source);

        void destructorHelperFunction(NodePtr root);
        /**Public functions*/

    public:

        BinarySearchTree<bstitem>();
        //initialize variables to null.
        ~BinarySearchTree<bstitem>();
        //delete all nodes that are in BST

        BinarySearchTree<bstitem>(const BinarySearchTree &BinarySearchTree);

        bstitem minimum();
        //finds the minimum value in the Binary Search Tree and returns it
        //pre: !isEmpty()

        bstitem maximum();
        //finds the maximum value in the Binary Search Tree and returns it
        //pre: !isEmpty()

        bool isEmpty();
        //returns whether the tree is empty

        int getSize();
        //returns the size of the tree

        bstitem getRoot();
        //returns the value stored at the root of the tree
        //Pre: !isEmpty()

        int getHeight();
        //recursively finds the height of the tree and returns it
        //Pre: !isEmpty()

        bool find(bstitem value);
        //returns whether the value is in the tree
        //Pre: !isEmpty()

        void insert(bstitem value);
        //adds the specified value to the tree

        void remove(bstitem value);
        //removes the specified value from the tree
        //Pre: !isEmpty()
        //Pre: The value is contained in the Binary Search Tree
        //If the value is not in the Binary Search Tree, the tree is left unchanged

        int getHeightHelper(NodePtr root);


        /*void inOrderPrint();
        // recursively prints the values contained in the Binary Search Tree
        // according to an in order traversal

        void preOrderPrint();
        //recursively prints the values contained in the Binary Search Tree
        // according to a pre order traversal

        void postOrderPrint();
        //recursively prints the values contained in the Binary Search Tree
        // according to a post order traversal*/

        void inOrderPrint(ofstream& file);
        //calls the inOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void preOrderPrint(ofstream& file);
        //calls the preOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void postOrderPrint(ofstream& file);
        //calls the postOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

};

template<class bstitem>
BinarySearchTree<bstitem>::BinarySearchTree(): size(0), root(NULL) {}

//Destructor
template<class bstitem>
BinarySearchTree<bstitem>::~BinarySearchTree()
{
	destructorHelperFunction(root);
}

template <class bstitem>
void BinarySearchTree<bstitem>::destructorHelperFunction(NodePtr root)

{
      if(root != NULL)
    {
      destructorHelperFunction(root->left);
      destructorHelperFunction(root->right);
      delete root;
     }
}

template <class bstitem>
BinarySearchTree<bstitem>::BinarySearchTree(const BinarySearchTree &BST):root(BST.root)
{
	if(BST.root == NULL)
		{
			root = NULL;
		}
		else
		{
			copyHelperFunction(root, BST.root);
		}
}

template <class bstitem>
void BinarySearchTree<bstitem>::copyHelperFunction(NodePtr root, NodePtr source)
{
	if(source != NULL)
	{
		root = new Node(source->data);
        copyHelperFunction(root->left, source->left);
        copyHelperFunction(root->right, source->right);
	}
	else
	{
		root = NULL;
	}
}

template <class bstitem>
bstitem BinarySearchTree<bstitem>::minimum()
{
	assert(size != 0);
    return minimumHelper(root);

}

template <class bstitem>
bstitem BinarySearchTree<bstitem>::maximum()
{
	assert(size != 0);
     return maximumHelper(root);
}

template <class bstitem>
bool BinarySearchTree<bstitem>::isEmpty()

{
	if(root == NULL)
			{return true;}
		else
			{return false;}
}

template <class bstitem>
int BinarySearchTree<bstitem>::getSize()
{
    return size;
}

template <class bstitem>
bstitem BinarySearchTree<bstitem>::getRoot()
{
	assert(size != 0);
    return root->data;
}

template <class bstitem>
bool BinarySearchTree<bstitem>::find(bstitem value)
{
	assert(!isEmpty());
if (value == root->data)
      {
        return true;
      }

else
   {
    return findHelper(root, value);
  }
}


template <class bstitem>
void BinarySearchTree<bstitem>::insert(bstitem value)
{
    if(root == NULL)
    {
        root = new Node(value); //if the tree is empty insert the value at the root
        size++;
    }
    else
    {
    	insertHelper(root,value); //otherwise call the helper function, passing it the root
    }
}


template <class bstitem>
void BinarySearchTree<bstitem>::insertHelper(NodePtr root, bstitem value)
{
    NodePtr N = new Node(value);
    N->left = N->right = NULL;

    if(root->data != value)
    {

           if(value < root->data)
       {
           if(root->left == NULL)
           {
              root->left = N;
             size++;
           }
           else
           {
        	insertHelper(root->left,value);
           }
      }

         else
        {
           if(root->right == NULL)
          {
            root->right = N;
            size++;
           }
        else
           {
        	insertHelper(root->right,value);
           }
        }

    }

    else
    {
    	return;
    }


}


template <class bstitem>
void BinarySearchTree<bstitem>::remove(bstitem value)

{
	assert(size != 0);
    root = removeHelper(root,value);
    size--;
}


template <class bstitem>
typename BinarySearchTree<bstitem>::NodePtr BinarySearchTree<bstitem>::removeHelper(NodePtr root, bstitem value)
{
    if(root == NULL)
    {
    	return root;
    }
    else if(value < root->data)
    {
    	root->left = removeHelper(root->left, value);
    }
    else if(value > root->data)
    {
    	root->right = removeHelper(root->right, value);
    }
    else
    {
    	if(root->left == NULL && root->right == NULL)
    	{
    		  NodePtr temp = root;
    		  root = NULL;
    		  delete temp;
    	}
    	else if(root->left != NULL && root->right == NULL)
    	{
    		NodePtr temp = root;
    		root = root->left;
    		delete temp;
    	}
    	else if(root->left == NULL && root->right != NULL)
    	{
    		NodePtr temp = root;
    		root = root->right;
    		delete temp;
    	}
    	else
    	{
    		bstitem min = minimum();
    		root->data = min;
    		root->right = removeHelper(root->right, min);
    	}
    }
    return root;
}


template <class bstitem>
bool BinarySearchTree<bstitem>::findHelper(NodePtr root, bstitem value)
{

	if(root->data == value)
	{
       return true;
	}

	else if(value < root->data)
	{
	      if(root->left == NULL)
	    {
	        return false;
	     }

	        else
        {
	    	findHelper(root->left, value);
        }

    }


	   else if(value > root->data)
	{
	    if(root->right == NULL)
	     {
	     	return false;
	      }

	       else
         {
		   findHelper(root->right, value);
          }

	}

	      else
	 {
	   return false;
	 }
}

template <class bstitem>
bstitem BinarySearchTree<bstitem>::minimumHelper(NodePtr root)
{
	if(root->left == NULL)
		{
		return root->data;
		}
	else
	{
		minimumHelper(root->left);
	}
}

template <class bstitem>
bstitem BinarySearchTree<bstitem>::maximumHelper(NodePtr root)
{
	if(root->right == NULL)
			{
		      return root->data;
			}
		else
			{
			   maximumHelper(root->right);
			}
}

template <class bstitem>
int BinarySearchTree<bstitem>::getHeight()
{
	assert(!isEmpty());
	return getHeightHelper(root);
}

template <class bstitem>
int BinarySearchTree<bstitem>::getHeightHelper(NodePtr root)
{
	 if(root == NULL)
	 {
	 return -1;
	 }

	 else
	 {
	      int left= getHeightHelper(root->left);
	      int right = getHeightHelper(root->right);

	     if(left >right)
	    {
		      return left +1;
	     }

	       else
	     {
	         return right +1;
	      }

	 }
}

template <class bstitem>
void BinarySearchTree<bstitem>::inOrderPrint(ofstream& file)
{
	if(root != NULL)
		{
			inOrderPrintHelper(root, file);
		}
}

template <class bstitem>
void BinarySearchTree<bstitem>::preOrderPrint(ofstream& file)
 {
	 if(root != NULL)
	 	{
	 		preOrderPrintHelper(root, file);
	 	}

}

template <class bstitem>
void BinarySearchTree<bstitem>::postOrderPrint(ofstream& file)
 {
    if (root!=NULL)
         {
          postOrderPrintHelper(root, file);
        }
 }

template<class bstitem>
void BinarySearchTree<bstitem>::inOrderPrintHelper(NodePtr root, ofstream& file)
 {
		if(root != NULL)
		{
			inOrderPrintHelper(root->left, file);
			file << root->data << " ";
			inOrderPrintHelper(root->right, file);
		}

 }

template<class bstitem>
void BinarySearchTree<bstitem>::preOrderPrintHelper(NodePtr root, ofstream& file)
 {
     if(root != NULL)
     	{
    	    file << root->data << " ";
     		preOrderPrintHelper(root->left, file);
     		preOrderPrintHelper(root->right, file);
     	}
 }


template<class bstitem>
void BinarySearchTree<bstitem>::postOrderPrintHelper(NodePtr root, ofstream& file)
 {
	 if(root != NULL)
	 {
	 postOrderPrintHelper(root->left, file);
	 postOrderPrintHelper(root->right, file);
	 file << root->data << " ";
	 }

 }

/*
template <class bstitem>
void BinarySearchTree<bstitem>::inOrderPrint()
{
	if(root != NULL)
		{
			inOrderPrintHelper(root);
		}
}

template <class bstitem>
void BinarySearchTree<bstitem>::preOrderPrint()
 {
	 if(root != NULL)
	 	{
	 		preOrderPrintHelper(root);
	 	}

}

template <class bstitem>
void BinarySearchTree<bstitem>::postOrderPrint()
 {
    if (root!=NULL)
         {
          postOrderPrintHelper(root);
        }
 }

template<class bstitem>
void BinarySearchTree<bstitem>::inOrderPrintHelper(NodePtr root)
 {
		if(root != NULL)
		{
			inOrderPrintHelper(root->left);
			cout << root->data << " ";
			inOrderPrintHelper(root->right);
		}

 }

template<class bstitem>
void BinarySearchTree<bstitem>::preOrderPrintHelper(NodePtr root)
 {
     if(root != NULL)
     	{
     		cout << root->data << " ";
     		preOrderPrintHelper(root->left);
     		preOrderPrintHelper(root->right);
     	}
 }


template<class bstitem>
void BinarySearchTree<bstitem>::postOrderPrintHelper(NodePtr root)
 {
	 if(root != NULL)
	 {
	 postOrderPrintHelper(root->left);
	 postOrderPrintHelper(root->right);
	 cout << root->data << " ";
	 }

 }
*/

#endif /* BINARYSEARCHTREE_H_ */
