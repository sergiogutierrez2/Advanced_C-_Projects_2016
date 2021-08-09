//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* BinarySearchTreeTest.cpp

*/
//============================================================================

/*#include "BinarySearchTree.h"
#include<iostream>
using namespace std;

int main()

{*/

    /* STUDENT TEST BEGINS HERE */


	/*BinarySearchTree<double>Later;
	BinarySearchTree<int> Go;

    cout << "Testing insert." << endl;
    Go.insert(40);
    Go.insert(25);
    Go.insert(78);
    Go.insert(10);
    Go.insert(32);

    cout << "the value of root should be 40: " << Go.getRoot() << endl;
    cout << "The height is: " << Go.getHeight() << endl;

    cout << "inOrderPrint() will print: 10, 25, 32, 40, 78: ";
    Go.inOrderPrint();

    cout << "\npreOrderPrint() will print: 40, 25, 10, 32, 78: ";
    Go.preOrderPrint();

    cout << "\npostOrderPrint() will print: 10 32 25 78 40: ";
    Go.postOrderPrint();

    cout << endl;
    cout << "All printers worked!" << endl;

    cout << endl;
    cout<< "The minimum will print out 10: " << Go.minimum() << endl;
    cout<< "The maximum will print out 78: " << Go.maximum() << endl;

    if (Go.isEmpty())
    {
    	cout << "This is empty." << endl;
    }
    else
    {
    	cout << "This is not empty" << endl;
    }

    if (Later.isEmpty())
    {
       cout << "This is empty." << endl;
    }
        else
    {
        cout << "This is not empty" << endl;
     }

    cout << endl;

    cout << "The size should be 5: " << Go.getSize() << endl;

    cout << "Now let's test Binary Search." << endl;
    if (Go.find(25))
    {
    	cout << "We have found 25!" << endl;
    }
    else
    {
    	cout << "25 wasn't found." << endl;
    }

           if (Go.find(30))
        {
        	cout << "We have found 30!" << endl;
        }
        else
        {
        	cout << "30 wasn't found." << endl;
        }

     cout << endl;
     cout << "Now testing the remove function:" << endl;
     Go.remove(32);
     cout << "After removing 32, inOrderPrint() will print: 10, 25, 40, 78: ";
     Go.inOrderPrint();
}*/

/* OUTPUT:
 *
Testing insert.
the value of root should be 40: 40
The height is: 2
inOrderPrint() will print: 10, 25, 32, 40, 78: 10 25 32 40 78
preOrderPrint() will print: 40, 25, 10, 32, 78: 40 25 10 32 78
postOrderPrint() will print: 10 32 25 78 40: 10 32 25 78 40
All printers worked!

The minimum will print out 10: 10
The maximum will print out 78: 78
This is not empty
This is empty.

The size should be 5: 5
Now let's test Binary Search.
We have found 25!
30 wasn't found.

Now testing the remove function:
After removing 32, inOrderPrint() will print: 10, 25, 40, 78: 10 25 40 78
 */

