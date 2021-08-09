/* List.h
 * Created on: Sept 30, 2016
 * Author: Sergio Gutierrez
 * Class:  22C
 * Fall Quarter 2016
 * Professor: Jennifer Parrish
 */

#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL
#include <iostream>

class List
{
    private:
             struct Node
             {
                int data;
                Node* next;

                Node(int data): next(NULL), data(data){}
             };

             typedef struct Node* NodePtr;

             NodePtr start;
             NodePtr end;
             NodePtr cursor;

             int length;
    public:

        /**Constructors and Destructors*/

        List();
        //Default constructor; initializes and empty list
        //Postcondition: The list is now initialized with default values.

        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition: The memory that was allocated in the list is now free

        List(const List &list);
        //Copy construcor. Initializes list to have the same elements as another list
        //Postcondition: The new copy of the list now has a copy
        // of the same elements as the original list.

        /**Accessors*/


        int get_start();
        //Returns the first element in the list
        //Precondition: The Data which the start pointer points to
        //can be accessed.


        int get_end();
        //Returns the last element in the list
        //Precondition: The Data which the end pointer points to
        //can be accessed.


        int get_cursor();
        //Returns the element pointed to by the iterator
        //Precondition: The Data on which the cursor is on can be accessed.


        bool is_empty();
        //Determines whether a list is empty.



        bool off_end();
        //Determines if the iterator is off the end of the list (i.e. whether cursor is NULL)


        int get_length();
        //Returns the length of the list


        /**Manipulation Procedures*/

        void begin_cursor();
        //Moves the iterator to point to the first element in the list
        //If the list is empty, the iterator remains NULL
        //Postcondition: The iterator is now pointing to the
        // the first element in the list


        void insert_cursor(int data);
        //Inserts a new element into the list in the position after the iterator
        //Precondition: Iterator has a certain position on the list.
        //Postcondition: Iterator points to new element that was inserted.

        void remove_end();
        //Removes the value of the last element in the list
        //Precondition: There is an element that is last on the list.
        //Postcondition: The element that was last on the list is now removed.

        void remove_start();
        //Removes the value of the first element in the list
        //Precondition: There is an element that is first on the list.
        //Postcondition: The element that was first on the list is now removed.

        void add_end(int data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: A new element was inserted at the end of the list.

        void add_start(int data);
        //Inserts a new element at the start of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: A new element was inserted at
        // the beginning of the list


        void remove_cursor();
        //Removes the element pointed at by the iterator
        //Precondition: The iterator points to an element.
        //Postcondition: The iterator is no longer pointing to the element.

        void move_cursor();
        //Moves the iterator forward by one element in the list
        //Precondition: The iterator is pointing to an element.
        //Postcondition: The iterator is now pointing to an element that
        //is one element forward to the one it was originally pointing.


        /**Additional List Operations*/

        void print();
        //Prints to the console the value of each element in the list sequentially
        //and separated by a blank space
        //Prints nothing if the list is empty
};



#endif /* LIST_H_ */
