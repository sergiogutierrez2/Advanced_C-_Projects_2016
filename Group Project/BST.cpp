#ifndef BST_H_
#define BST_H_


#include <cstddef>
#include <string>
#include <assert.h>
#include <iostream>
#include <fstream>


using namespace std;


template <class bstitem>
class BST
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


        void insertHelper(NodePtr root, bstitem value);
        //private helper function for insert
        //recursively inserts a value into the BST


        //regular cout usage
        void inOrderPrintHelper(NodePtr root);
        //private helper function for inOrderPrint
        //recursively prints tree values in order from smallest to largest


        void preOrderPrintHelper(NodePtr root);
        //private helper function for preOrderPrint
        //recursively prints tree values in preorder


        void postOrderPrintHelper(NodePtr root);
        //private helper function for postOrderPrint
        //recursively prints tree values in postorder




        bool downloadHelper_by_title(NodePtr root, string value, ofstream& outfile);
        bool findHelper_by_title(NodePtr root, string value);
        bool findHelper_by_artist(NodePtr root, string value);
        bool findHelper_by_genre(NodePtr root, string value);


        bstitem minimumHelper(NodePtr root);


        bstitem maximumHelper(NodePtr root);


        NodePtr removeHelper(NodePtr root, string value);




        int getSizeHelper(NodePtr root);


        void copyHelperFunction(NodePtr root, NodePtr origin);


        void deconstructorHelper(NodePtr root);
        /**Public functions*/


    public:


        BST();
        //Instantiates a new Binary Search Tree
        //post: a new Binary Search Tree object


        ~BST();
        //destructor


        BST(const BST &BST);


        bool isEmpty();
        //determines whether the Binary Search Tree is empty


        void insert(bstitem value);
        //inserts a new value into the Binary Search Tree
        //post: a new value inserted into the Binary Search Tree


        bstitem getRoot();
        //returns the value stored at the root of the Binary Search Tree
        //pre: the Binary Search Tree is not empty


        //regular cout usage
        void inOrderPrint();
        //calls the inOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing


        void preOrderPrint();
        //calls the preOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing


        void postOrderPrint();
        //calls the postOrderPrintHelper function to print out the values
        //stored in the Binary Search Tree
        //If the tree is empty, prints nothing
        bool download_by_title(string value,ofstream& outfile);
        bool find_by_title(string value);
        bool find_by_artist(string value);
        bool find_by_genre(string value);


        bstitem minimum();


        bstitem maximum();


        void remove(string value);




        int getSize();
};


//default construction


template <class bstitem>
BST<bstitem>::BST():root(NULL) {}


//deconstruction
template <class bstitem>
void BST<bstitem>::deconstructorHelper(NodePtr root)
{
    if(root != NULL)
    {
        deconstructorHelper(root->left);
        deconstructorHelper(root->right);
        delete root;
    }
}
template <class bstitem>
BST<bstitem>::~BST()
{
    deconstructorHelper(root);
}


//copy construction


template <class bstitem>
BST<bstitem>::BST(const BST &BST):root(BST.root)
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
void BST<bstitem>::copyHelperFunction(NodePtr root, NodePtr origin)
{
    if(origin != NULL)
    {
        root = new Node(origin->data);
        copyHelperFunction(root->left, origin->left);
        copyHelperFunction(root->right, origin->right);
    }
    else
    {
        root = NULL;
    }
}




//access functions


template <class bstitem>
bstitem BST<bstitem>::minimum()
{
    assert(!isEmpty());
    return minimumHelper(root);
}


template <class bstitem>
bstitem BST<bstitem>::minimumHelper(NodePtr root)
{
    if(root->left == NULL)
        return root->data;
    else
        minimumHelper(root->left);
}


template <class bstitem>
bstitem BST<bstitem>::maximum()
{
    assert(!isEmpty());
    return maximumHelper(root);
}


template <class bstitem>
bstitem BST<bstitem>::maximumHelper(NodePtr root)
{
    if(root->right == NULL)
        return root->data;
    else
        minimumHelper(root->right);
}


template <class bstitem>
bool BST<bstitem>::isEmpty()
{
    if(root == NULL)
        return true;
    else
        return false;
}


template <class bstitem>
int BST<bstitem>::getSize() //let you know how many elements in the list
{
    return getSizeHelper(root);
}


template <class bstitem>
int BST<bstitem>::getSizeHelper(NodePtr root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return getSizeHelper(root->left)+ 1 + getSizeHelper(root->right);
    }
}


template <class bstitem>
bstitem BST<bstitem>::getRoot()
{
    assert(!isEmpty());
    return root->data;
}


//manipulation functions


template <class bstitem>
void BST<bstitem>::insert(bstitem value)
{
    if (root == NULL)
    {
        root = new Node(value); //if the tree is empty insert the value at the root
    }
    else
    {
        insertHelper(root, value); //otherwise call the helper function, passing it the root
    }
}


template <class bstitem>
void BST<bstitem>::insertHelper(NodePtr root, bstitem value)
{
    if(root->data.get_title() == value.get_title())
    {
        cout << "no same value allowed"<<endl;
    }


    if(value.get_title() < root->data.get_title())
    {
        if(root->left == NULL)
        {
            root->left = new Node(value);
        }
        else
        {
            insertHelper(root->left, value);
        }
    }
    else
    {
        if(root->right == NULL)
        {
            root->right = new Node(value);
        }
        else
        {
            insertHelper(root->right, value);
        }
    }
}


template <class bstitem>
void BST<bstitem>::remove(string value)
{
    assert(!isEmpty());
    root = removeHelper(root, value);
}


template <class bstitem>
typename BST<bstitem>::NodePtr BST<bstitem>::removeHelper(NodePtr root, string value)
{
    if(root == NULL)
    {
        cout << "Song is not on the list."<< endl;
        return root;
    }
    else if(value < root->data.get_title())
    {
        root->left = removeHelper(root->left, value);
    }
    else if(value > root->data.get_title())
    {
        root->right = removeHelper(root->right, value);
    }
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
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
            root->right = removeHelper(root->right, min.get_title());
        }
    }
    return root;
}




//regular cout usage
template <class bstitem>
void BST<bstitem>::inOrderPrint()
{
    if(root != NULL)
    {
        inOrderPrintHelper(root);
    }
}


template <class bstitem>
void BST<bstitem>::inOrderPrintHelper(NodePtr root)
{
    if(root != NULL)
    {
        inOrderPrintHelper(root->left);
        (root->data).print_song();
        cout << endl;
        inOrderPrintHelper(root->right);
    }
}


template <class bstitem>
void BST<bstitem>::preOrderPrint()
{
    if(root != NULL)
    {
        preOrderPrintHelper(root);
    }
}


template <class bstitem>
void BST<bstitem>::preOrderPrintHelper(NodePtr root)
{
    if(root != NULL)
    {
        (root->data).print_song();
        cout << endl;
        preOrderPrintHelper(root->left);
        preOrderPrintHelper(root->right);
    }
}


template <class bstitem>
void BST<bstitem>::postOrderPrint()
{
    if(root != NULL)
    {
        postOrderPrintHelper(root);
    }
}


template <class bstitem>
void BST<bstitem>::postOrderPrintHelper(NodePtr root)
{
    if(root != NULL)
    {
        postOrderPrintHelper(root->left);
        postOrderPrintHelper(root->right);
        (root->data).print_song();
        cout << endl;
    }
}


template <class bstitem>
bool BST<bstitem>::download_by_title(string value, ofstream& outfile)
{
    assert(!isEmpty());
    if (value == root->data.get_title())
    {
        outfile << root->data.get_title() << " - " << root->data.get_artist()<<endl;
        outfile << "genre : " << root->data.get_genre() << endl;
        outfile << "lyrics :" << endl;
        outfile << root->data.get_lyrics() << endl;
        return true;
    }
    else
        return downloadHelper_by_title(root, value, outfile);
}


template <class bstitem>
bool BST<bstitem>::downloadHelper_by_title(NodePtr root, string value, ofstream& outfile)
{


    if(root->data.get_title() == value)
    {
        outfile << root->data.get_title() << " - " << root->data.get_artist()<<endl;
        outfile << "genre : " << root->data.get_genre() << endl;
        outfile << "lyrics :" << endl;
        outfile << root->data.get_lyrics() << endl;
        return true;
    }
    else if(value < root->data.get_title())
    {
        if(root->left == NULL)
        {
            outfile << " Song not found"<< endl;
            return false;
        }
        else
            downloadHelper_by_title(root->left, value, outfile);
    }
    else if(value > root->data.get_title())
    {
        if(root->right == NULL)
        {
            outfile << " Song not found"<< endl;
                return false;
        }
        else
            downloadHelper_by_title(root->right, value, outfile);
    }
    else
    {
        outfile << " Song not found"<< endl;
        return false;
    }
}


template <class bstitem>
bool BST<bstitem>::find_by_title(string value)
{
    assert(!isEmpty());
    if (value == root->data.get_title())
    {
        cout << "song found" << endl;
        cout << root->data.get_title() << " - " << root->data.get_artist()<<endl;
        cout << "genre : " << root->data.get_genre() << endl;
        cout << "lyrics :" << endl;
        cout << root->data.get_lyrics() << endl;
        return true;
    }
    else
        return findHelper_by_title(root, value);
}


template <class bstitem>
bool BST<bstitem>::findHelper_by_title(NodePtr root, string value)
{
    if(root->data.get_title() == value)
    {
        cout << "song found" << endl;
        cout << root->data.get_title() << " - " << root->data.get_artist()<<endl;
        cout << "genre : " << root->data.get_genre() << endl;
        cout << "lyrics :" << endl;
        cout << root->data.get_lyrics() << endl;
        return true;
    }
    else if(value < root->data.get_title())
    {
        if(root->left == NULL)
        {
            cout << " Song not found"<< endl;
            return false;
        }
        else
            findHelper_by_title(root->left, value);
    }
    else if(value > root->data.get_title())
    {
        if(root->right == NULL)
        {
                cout << " Song not found"<< endl;
                return false;
        }
        else
            findHelper_by_title(root->right, value);
    }
    else
    {
        cout << " Song not found"<< endl;
        return false;
    }
}
/////////////////////////////////////////////////////
template <class bstitem>
bool BST<bstitem>::find_by_artist(string value)
{
    assert(!isEmpty());
    if (value == root->data.get_artist())
    {
        cout << "song found" << endl;
        cout << root->data.get_title() << " - " << root->data.get_artist()<<endl;
        cout << "genre : " << root->data.get_genre() << endl;
        cout << "lyrics :" << endl;
        cout << root->data.get_lyrics() << endl;
        return true;
    }
    else
        return findHelper_by_artist(root, value);
}


template <class bstitem>
bool BST<bstitem>::findHelper_by_artist(NodePtr root, string value)
{
    if(root->data.get_artist() == value)
    {
        cout << "song found" << endl;
        cout << root->data.get_title() << " - " << root->data.get_artist()<<endl;
        cout << "genre : " << root->data.get_genre() << endl;
        cout << "lyrics :" << endl;
        cout << root->data.get_lyrics() << endl;
        return true;
    }
    else if(value < root->data.get_artist())
    {
        if(root->left == NULL)
        {
            cout << " Song not found"<< endl;
            return false;
        }
        else
            findHelper_by_artist(root->left, value);
    }
    else if(value > root->data.get_artist())
    {
        if(root->right == NULL)
        {
                cout << " Song not found"<< endl;
                return false;
        }
        else
            findHelper_by_artist(root->right, value);
    }
    else
    {
        cout << " Song not found"<< endl;
        return false;
    }
}
/////////////////////////////////////////////////////


template <class bstitem>
bool BST<bstitem>::find_by_genre(string value)
{
    assert(!isEmpty());
    if (value == root->data.get_genre())
    {
        cout << "song found" << endl;
        cout << root->data.get_title() << " - " << root->data.get_artist()<<endl;
        cout << "genre : " << root->data.get_genre() << endl;
        cout << "lyrics :" << endl;
        cout << root->data.get_lyrics() << endl;
        return true;
    }
    else
        return findHelper_by_genre(root, value);
}


template <class bstitem>
bool BST<bstitem>::findHelper_by_genre(NodePtr root, string value)
{
    if(root->data.get_genre() == value)
    {
        cout << "song found" << endl;
        cout << root->data.get_title() << " - " << root->data.get_artist()<<endl;
        cout << "genre : " << root->data.get_genre() << endl;
        cout << "lyrics :" << endl;
        cout << root->data.get_lyrics() << endl;
        return true;
    }
    else if(value < root->data.get_genre())
    {
        if(root->left == NULL)
        {
            cout << " Song not found"<< endl;
            return false;
        }
        else
            findHelper_by_genre(root->left, value);
    }
    else if(value > root->data.get_genre())
    {
        if(root->right == NULL)
        {
                cout << " Song not found"<< endl;
                return false;
        }
        else
            findHelper_by_genre(root->right, value);
    }
    else
    {
        cout << " Song not found"<< endl;
        return false;
    }
}
#endif /* BST_H_ */



