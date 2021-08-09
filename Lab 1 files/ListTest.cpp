//============================================================================
/* ListTest.cpp
 * Name        : Sergio Gutierrez
 * Created on: Sept 30, 2016
 * Author: Sergio Gutierrez
 * Class:  22C
 * Fall Quarter 2016
 * Professor: Jennifer Parrish
 */
//============================================================================

#include <iostream>
#include "List.h"
using namespace std;

int main()
{
    //creating a new list object L
    List L;

    L.add_start(5);
    cout << "The start of the List should be 5: " << L.get_start() << endl;
    cout << "The end of the List should be 5: " << L.get_end() << endl;

    cout << "List should contain: 5" << endl;
    L.print();

    L.add_end(10);

    cout << "The start of the List should be 5: " << L.get_start() << endl;
    cout << "The end of the List should be 10: " << L.get_end() << endl;

    cout << "List should contain: 5 10" << endl;
    L.print();

    //YOU MUST ADD MORE TESTS HERE TO RECEIVE CREDIT FOR THIS LAB!!!
    //Here's my code:

    cout << "-----my added code-----" << endl;

    List X; //Initializing new X list.

    X.add_start(4);
    X.add_start(3);
    X.add_start(2);
    X.add_start(1);

    X.add_end(5);
    X.add_end(6);
    X.add_end(7);

    cout << "The start of the List should be 1: " << X.get_start() << endl;
    cout << "The end of the List should be 7: " << X.get_end() << endl;
    cout << endl;

    cout << "List X should contain 1, 2, 3, 4, 5, 6, 7:" << endl;
    X.print();

    X.add_start(0);
    X.add_end(8);

    cout << "List X should contain 0, 1, 2, 3, 4, 5, 6, 7, 8:" << endl;
    X.print();

    cout << "The length of this list should be 9: " << X.get_length() << endl;
    cout << endl;

    cout << "The following X list should not be empty." << endl;
    if (X.is_empty())
        cout << "The list is empty." << endl;
    else
        cout << "The list is not empty." << endl;

    cout << endl;

    List Y;
    cout << "The following list Y should be empty:" << endl;
    if (Y.is_empty())
        cout << "The list is empty." << endl;
    else
        cout << "The list is not empty." << endl;



    //This ran perfectly with the expected output which is found below.
}


/*
 Full output was:

The start of the List should be 5: 5
The end of the List should be 5: 5
List should contain: 5
5
The start of the List should be 5: 5
The end of the List should be 10: 10
List should contain: 5 10
5  10
-----my added code-----
The start of the List should be 1: 1
The end of the List should be 7: 7

List X should contain 1, 2, 3, 4, 5, 6, 7:
1  2  3  4  5  6  7
List X should contain 0, 1, 2, 3, 4, 5, 6, 7, 8:
0  1  2  3  4  5  6  7  8
The length of this list should be 9: 9

The following X list should not be empty.
The list is not empty.

The following list Y should be empty:
The list is empty.

 */


