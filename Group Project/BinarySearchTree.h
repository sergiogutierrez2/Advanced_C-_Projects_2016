#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_

#include <cstddef>
#include <string>
#include <assert.h>
#include <iostream>

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


        /**Private helper functions*/
        bstitem minimumHelper(NodePtr root);

        bstitem maximumHelper(NodePtr root);

        NodePtr removeHelper(NodePtr root, bstitem value);

        bool findHelper(NodePtr root, bstitem value);

        int getSizeHelper(NodePtr root);

        int getHeightHelper(NodePtr root);

        void insertHelper(NodePtr root, bstitem value);
        //private helper function for insert
        //recursively inserts a value into the BST

        void inOrderPrintHelper(NodePtr root, ostream& s);
        //private helper function for inOrderPrint
        //recursively prints tree values in order from smallest to largest

        void preOrderPrintHelper(NodePtr root, ostream& s);
        //private helper function for preOrderPrint
        //recursively prints tree values in preorder

        void postOrderPrintHelper(NodePtr root, ostream& s);
        //private helper function for postOrderPrint
        //recursively prints tree values in postorder

        void copyConHelper(NodePtr root, NodePtr origin);

        void deconstructorHelper(NodePtr root);

        /**Public functions*/

    public:
        BinarySearchTree();
        //Instantiates a new Binary Search Tree
        //post: a new Binary Search Tree object

        ~BinarySearchTree();
        //destructor

        BinarySearchTree(const BinarySearchTree &BinarySearchTree);

        bstitem minimum();
        //finds the minimum value in the Binary Search Tree and returns it
        //pre: !isEmpty()

        bstitem maximum();
        //finds the maximum value in the Binary Search Tree and returns it
        //pre: !isEmpty()

        bool isEmpty();
        //determines whether the Binary Search Tree is empty

        int getSize();
        //returns the size of the tree

        bstitem getRoot();
        //returns the value stored at the root of the Binary Search Tree
        //pre: the Binary Search Tree is not empty

        int getHeight();
        //recursively finds the height of the tree and returns it
        //Pre: !isEmpty()

        bool find(bstitem value);
        //returns whether the value is in the tree
        //Pre: !isEmpty()

        void insert(bstitem value);
        //inserts a new value into the Binary Search Tree
        //post: a new value inserted into the Binary Search Tree

        void remove(bstitem value);
        //removes the specified value from the tree
        //Pre: !isEmpty()
        //Pre: The value is contained in the Binary Search tree

        void inOrderPrint(ostream& s);
        //calls the inOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void preOrderPrint(ostream& s);
        //calls the preOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void postOrderPrint(ostream& s);
        //calls the postOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing

        void statistics();
};

#endif /* BINARYSEARCHTREE_H_ */

template<class bstitem>
BinarySearchTree<bstitem>::BinarySearchTree() : root(NULL) {}

//deconstruction
template <class bstitem>
void BinarySearchTree<bstitem>::deconstructorHelper(NodePtr root){
    if(root != NULL) {
        deconstructorHelper(root->left);
        deconstructorHelper(root->right);
        delete root;
    }
}

template <class bstitem>
BinarySearchTree<bstitem>::~BinarySearchTree(){
    deconstructorHelper(root);
}


//copy construction
template <class bstitem>
BinarySearchTree<bstitem>::BinarySearchTree(const BinarySearchTree &BST):root(BST.root){
    if(BST.root == NULL)
    {
        root = NULL;
    }
    else
    {
        copyConHelper(root, BST.root);
    }
}

template <class bstitem>
void BinarySearchTree<bstitem>::copyConHelper(NodePtr root, NodePtr origin)
{
    if (origin == NULL)
    {
        root = NULL;
    }
    else
    {
        root = new Node(origin->data);
        copyConHelper(root->left, origin->left);
        copyConHelper(root->right, origin->right);
    }

}


template<class bstitem>
bstitem BinarySearchTree<bstitem>::minimumHelper(NodePtr root){
    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::minimum(){
    assert(!isEmpty());
    return minimumHelper(root);
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::maximumHelper(NodePtr root){
    while(root->right != NULL){
        root = root->right;
    }
    return root->data;
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::maximum(){
    assert(!isEmpty());
    return maximumHelper(root);
}

template<class bstitem>
bool BinarySearchTree<bstitem>::isEmpty(){
    return (root == NULL);
}

template<class bstitem>
int BinarySearchTree<bstitem>::getSizeHelper(NodePtr root){
    if (root == NULL){
        return 0;
    } else {
        return (getSizeHelper(root->left) + 1 + getSizeHelper(root->right));
    }
}

template<class bstitem>
int BinarySearchTree<bstitem>::getSize(){
   return getSizeHelper(root);
}

template<class bstitem>
bstitem BinarySearchTree<bstitem>::getRoot(){
    assert(!isEmpty());
    return root->data;
}

template<class bstitem>
int BinarySearchTree<bstitem>::getHeightHelper(NodePtr root){
    if(root == NULL){
        return -1;
    } else {
        return (max(getHeightHelper(root->left), getHeightHelper(root->right)) + 1);
    }
}

template<class bstitem>
int BinarySearchTree<bstitem>::getHeight(){
    assert(!isEmpty());
    return getHeightHelper(root);
}

template<class bstitem>
bool BinarySearchTree<bstitem>::findHelper(NodePtr root, bstitem value){
    if(root->data == value){
        return true;
    } else if (value < root->data){
        if (root->left == NULL){
            return false;
        } else {
            return findHelper(root->left, value);
        }
    } else {
        if (root->right == NULL){
            return false;
        } else {
            return findHelper(root->right, value);
        }
    }
    return false;
}

template<class bstitem>
bool BinarySearchTree<bstitem>::find(bstitem value){
    assert(!isEmpty());
    if (value == root->data)
        return true;
    else
        return findHelper(root,value);
}

template <class bstitem>
void BinarySearchTree<bstitem>::insertHelper(NodePtr root, bstitem value){
    if(value == root->data){
        return;
    } else if(value < root->data){
        if(root->left == NULL){
            NodePtr N = new Node(value);
            root->left = N;
        } else {
            insertHelper(root->left, value);
        }
    } else {
        if(root->right == NULL){
            NodePtr N = new Node(value);
            root->right = N;
        } else {
            insertHelper(root->right, value);
        }
    }
}

template<class bstitem>
void BinarySearchTree<bstitem>::insert(bstitem value){
    if(root==NULL){
        root = new Node(value);
    } else {
        insertHelper(root, value);
    }
}

template<class bstitem>
typename BinarySearchTree<bstitem>::NodePtr BinarySearchTree<bstitem>::removeHelper(NodePtr root, bstitem value){
    if(root == NULL){
        return root;
    } else if (value < root->data){
        root->left = removeHelper(root->left, value);
    } else if (value > root->data){
        root->right = removeHelper(root->right, value);
    } else {
        if(root->left == NULL and root->right == NULL){
            delete root;
            root = NULL;
        } else if (root->right == NULL){
            NodePtr temp = root;
            root = root->left;
            delete temp;
        } else if (root->left == NULL){
            NodePtr temp = root;
            root = root->right;
            delete temp;
        } else {
            root->data = minimumHelper(root->right);
            root->right = removeHelper(root->right, minimumHelper(root->right));
        }
    }
    return root;
}

template<class bstitem>
void BinarySearchTree<bstitem>::remove(bstitem value){
    assert(!isEmpty());
    assert(find(value));
    root = removeHelper(root, value);
}

template<class bstitem>
void BinarySearchTree<bstitem>::inOrderPrintHelper(NodePtr root, ostream& s){
    if(root == NULL){
        return;
    } else {
        inOrderPrintHelper(root->left, s);
        (root->data).print_song();
        s << endl;
        inOrderPrintHelper(root->right, s);
    }
}

template<class bstitem>
void BinarySearchTree<bstitem>::inOrderPrint(ostream& s){
   inOrderPrintHelper(root, s);
}

template<class bstitem>
void BinarySearchTree<bstitem>::preOrderPrintHelper(NodePtr root, ostream& s){
    if(root == NULL){
        return;
    } else {
        root->data.print_song();
        s << endl;
        preOrderPrintHelper(root->left, s);
        preOrderPrintHelper(root->right, s);
    }
}

template<class bstitem>
void BinarySearchTree<bstitem>::preOrderPrint(ostream& s){
    preOrderPrintHelper(root, s);
}

template<class bstitem>
void BinarySearchTree<bstitem>::postOrderPrintHelper(NodePtr root, ostream& s){
    if(root == NULL){
        return;
    } else {
        postOrderPrintHelper(root->left, s);
        postOrderPrintHelper(root->right, s);
        root->data.print_song();
        s << endl;
    }
}

template<class bstitem>
void BinarySearchTree<bstitem>::postOrderPrint(ostream& s){
    postOrderPrintHelper(root, s);
}
