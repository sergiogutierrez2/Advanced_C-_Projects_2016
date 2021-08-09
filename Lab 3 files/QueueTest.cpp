/**
* @author Sergio Gutierrez
* CIS 22C
* QueueTest.cpp
*/

/*
#include <iostream>
#include "Queue.h"
#include <assert.h>
#include <cstddef>
using namespace std;

int main()
{
    cout << "*****My QueueTest code of Main is Found Below: *****" << endl;
    Queue X;

    cout << "The following will fail the assertion, there is no front." <<endl;
    cout << "I will comment it out when finished.\n";
    //X.get_front();
    cout << endl;

    X.enqueue("Adrian");
    X.enqueue("Natalie");

    cout << "The following will display the front, which is Adrian." << endl;
    cout << "Here is the front: " << X.get_front() << endl;

    X.enqueue("Serverus");
    X.enqueue("Zen");
    X.enqueue("Kenny");

    cout << "The following will display these names in this order: "
        << "Adrian Natalie Serverus Zen Kenny" << endl;
    X.print();
    cout << endl;

    cout << "The following will display the front, which is Adrian." << endl;
    cout << "Here is the front: " << X.get_front() << endl;

    cout << "The following will display 5, which is the length." << endl;
    cout << X.get_length() << endl;

    X.dequeue(); //Remove Adrian
    X.dequeue(); //Remove Natalie

    cout << "The following will display these names in this order: "
    << "Serverus Zen Kenny" << endl;
    X.print();
    cout << endl;

    Queue Y(X); //copy constructor

    if (X == Y)
    {
     cout << "This will be printed if both lists are the same!" << endl;
    }

    cout << "Therefore: ";
    cout << "the following will also display these names in this order: "
    << "Serverus Zen Kenny" << endl;
    Y.print();

    cout << endl;
    Queue Z;
    cout << "The following will fail the assertion, there is no front." <<endl;
        cout << "I will comment it out when finished.\n";
    //Z.dequeue();

    cout << "Is the Z Queue empty? " << endl;
    if (Z.is_empty()==1)
    {
    	cout << "Yes, it's empty." << endl;
    }
    else
    {
    	cout << "No, its not empty." << endl;
    }
    Z.enqueue("Ron");
    cout << "How about now? " << endl;
    if (Z.is_empty()==1)
     {
       cout << "Yes, it's empty." << endl;
     }
    else
     {
       cout << "No, its not empty." << endl;
     }



}*/

/*  OUTPUT:
 *
*****My QueueTest code of Main is Found Below: *****
The following will fail the assertion, there is no front.
I will comment it out when finished.

The following will display the front, which is Adrian.
Here is the front: Adrian
The following will display these names in this order: Adrian Natalie Serverus Zen Kenny
Adrian Natalie Serverus Zen Kenny
The following will display the front, which is Adrian.
Here is the front: Adrian
The following will display 5, which is the length.
5
The following will display these names in this order: Serverus Zen Kenny
Serverus Zen Kenny
This will be printed if both lists are the same!
Therefore: the following will also display these names in this order: Serverus Zen Kenny
Serverus Zen Kenny
The following will fail the assertion, there is no front.
I will comment it out when finished.
Is the Z Queue empty?
Yes, it's empty.
How about now?
No, its not empty.
 */




