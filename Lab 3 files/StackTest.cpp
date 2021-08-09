/**
* @author Sergio Gutierrez
* CIS 22C
* StackTest.cpp
*/
/*
#include <iostream>
#include "Stack.h"
#include <assert.h>
#include <cstddef>
using namespace std;


int main()
{

	cout << "*****My StackTest code of Main is Found Below: *****" << endl;
    Stack X;

    cout << "The following will fail the assertion, there is no top." <<endl;
    cout << "I will comment it out when finished.\n";
    //X.get_top();
    cout << endl;

    X.push("Lopez");
    X.push("Hernandez");

    cout << "The following will display the top, which is Hernandez." << endl;
    cout << "Here is the top: " << X.get_top() << endl;

    X.push("Gartonzavesky");
    X.push("Brown");
    X.push("Nyugen");

    cout << "The following will display these last names in this order: "
        << "Nguyen Brown Gartonzavesky Hernandez Lopez" << endl;
    X.print();
    cout << endl;

    cout << "The following will display the front, which is Nyugen." << endl;
    cout << "Here is the front: " << X.get_top() << endl;

    cout << "The following will display 5, which is the length." << endl;
    cout << X.get_length() << endl;

    X.pop(); //Remove Nyugen
    X.pop(); //Remove Brown

    cout << "The following will display these last names in this order: "
    << "Gartonzavesky Hernandez Lopez" << endl;
    X.print();
    cout << endl;

    Stack Y(X); //copy constructor

    if (X == Y)
    {
     cout << "This will be printed if both lists are the same!" << endl;
    }

    cout << "Therefore: ";
    cout << "the following will also display these names in this order: "
    << "Gartonzavesky Hernandez Lopez" << endl;
    Y.print();

    cout << endl;
    Stack Z;
    cout << "The following will fail the assertion, there is no top." <<endl;
        cout << "I will comment it out when finished.\n";
    //Z.pop();

}*/

/*  OUTPUT:
 *
*****My StackTest code of Main is Found Below: *****
The following will fail the assertion, there is no top.
I will comment it out when finished.

The following will display the top, which is Hernandez.
Here is the top: Hernandez
The following will display these last names in this order: Nguyen Brown Gartonzavesky Hernandez Lopez
Nyugen Brown Gartonzavesky Hernandez Lopez
The following will display the front, which is Nyugen.
Here is the front: Nyugen
The following will display 5, which is the length.
5
The following will display these last names in this order: Gartonzavesky Hernandez Lopez
Gartonzavesky Hernandez Lopez
This will be printed if both lists are the same!
Therefore: the following will also display these names in this order: Gartonzavesky Hernandez Lopez
Gartonzavesky Hernandez Lopez
The following will fail the assertion, there is no top.
I will comment it out when finished.
 */



