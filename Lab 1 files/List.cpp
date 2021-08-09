//============================================================================
/* List.cpp
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

//Default Constructor
List::List(): start(NULL), end(NULL), cursor(NULL), length(0) {}

//Destructor
List::~List()
{
    cursor = start;
    NodePtr temp;
    while(cursor != NULL)
    {
        temp = cursor->next;

        delete cursor;

        cursor = temp;

    }
}

void List::add_start(int data)
{
    if (length==0) //It tests to see if there is an already existing list.
    {
        start = new Node(data);
        end = start;

    }
    else
    {
        NodePtr N = new Node(data);//create the new node by calling the node constructor
        N->next = start;//set the new node's next field to point to the start
        start = N;//make the start be the new node
    }

    length++;

}

void List::add_end(int data)
{
	if (length==0)
	    {
	      end = new Node(data);
	      start = end;
	    }
	    else
	    {
	        NodePtr N = new Node(data);
	        end->next = N;
	        end = N;
	    }

	    length++;

}

void List::print()
{

	NodePtr temp = start; //create a temporary iterator
    while (temp != NULL) {

        //What two lines of code go here?
    	cout << temp->data << "  ";
    	temp = temp->next;
        //Hint: One statement should contain a cout

    }
    cout << endl; //This keeps your printouts well organized with a space
    //between the lists.
}



bool List::is_empty()
{
    return (length==0);
}

int List::get_length()
{
    return length;
}

int List::get_start()
{
    return start -> data;

}

int List::get_end()
{
    return end -> data;

}




