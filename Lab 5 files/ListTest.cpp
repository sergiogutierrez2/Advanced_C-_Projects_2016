//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* ListTest.cpp

*/
//============================================================================

#include <iostream>
#include "List.h"
#include <assert.h>
#include <cstddef>
using namespace std;

int main()
{

    //*********My Test of Main is Found Below:************
    cout << "*****Student Test Code Begins Here: *****" << endl;
    List<int> ListInts;

    ListInts.add_end(1);
    ListInts.add_end(2);
    ListInts.add_end(3);
    ListInts.add_end(4);
    ListInts.add_end(5);
    ListInts.add_end(10);

    cout << "This will print 1 2 3 4 5 10:\n";
    ListInts.print();

    cout << "Now let's print this sorted list in reverse.\n";
	cout << "So the following should print 10 5 4 3 2 1:\n";
	ListInts.print_reverse();
	cout << endl;

	cout << "Using Linear Search to find 5: " << ListInts.linear_search(5) << endl;
	cout << "The above search resulted in 5 because the value was found." << endl;

	cout << "Using Linear Search to find 8: " << ListInts.linear_search(8) << endl;
	cout << "The above search resulted in -1 because 8 was not found." << endl;

	cout << "Using Binary Search to find 2: " << ListInts.binary_search(1,10,2) << endl;
	cout << "The above search resulted in 2 because 2 was found." << endl;

	cout << "Using Binary Search to find 8: " << ListInts.binary_search(1,6,8) << endl;
	cout << "The above search resulted in -1 because 8 was not found." << endl;


	cout << "The following will get and print the index, which in this case is 2: " << endl;
	cout << ListInts.get_index() << endl;
	cout << "Now we scroll to index 4." << endl;
    ListInts.scroll_to_index(4);
    cout << "Now we will get and print the index, which is now 4:" << endl;
	cout << ListInts.get_index() << endl;

	List<int> ListInts2;
    cout << "All of the following would fail the assertion but will be commented out." << endl;
	//ListInts2.print_reverse();
	//ListInts2.get_index();
	//ListInts2.scroll_to_index(3);
    //ListInts2.linear_search(3);
	//ListInts2.binary_search(1,2,3);
}

/*  OUTPUT:

*****Student Test Code Begins Here: *****
This will print 1 2 3 4 5 6:
1 2 3 4 5 6
Now let's print this sorted list in reverse.
So the following should print 6 5 4 3 2 1:
6 5 4 3 2 1
Using Linear Search to find 5: 5
The above search resulted in 5 because the value was found.
Using Linear Search to find 8: -1
The above search resulted in -1 because 8 was not found.
Using Binary Search to find 2: 2
The above search resulted in 2 because 2 was found.
Using Binary Search to find 8: -1
The above search resulted in -1 because 8 was not found.
The following will get and print the index, which in this case is 2:
2
Now we scroll to index 4.
Now we will get and print the index, which is now 4:
4
All of the following would fail the assertion but will be commented out.


 */
