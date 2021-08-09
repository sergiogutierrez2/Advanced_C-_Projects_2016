//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* List.h

*/
//============================================================================

#ifndef LIST_H_
#define LIST_H_

#include <cstddef> //for NULL
#include <iostream>
#include <assert.h>
#include <cstdlib>

using namespace std;

template <class listitem>
class List
{
    private:
			struct Node
	        {
	               listitem data;
	               Node* next;
	               Node* previous;
	               Node(listitem data): data(data), next(NULL), previous(NULL){}
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
        //Postcondition: List is empty set node to NULL

        ~List();
        //Destructor. Frees memory allocated to the list
        //Postcondition: nodes on the list is deleted and freed

        List(const List &list);
        //Copy construcor. Initializes list to have the same elements as another list
        //Postcondition: New List is duplicated with old List list.

        /**Accessors*/


        listitem get_start();
        //Returns the first element in the list
        //Precondition: There is a accessible int data in the list.


        listitem get_end();
        //Returns the last element in the list
        //Precondition: There is a accessible last data in the list.


        listitem get_cursor();
        //Returns the element pointed to by the iterator
        //Precondition: There is a accessible data that iterator is pointing


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
        //Postcondition: iterator will be pointed to fist element


        void add_cursor(listitem data);
        //Inserts a new element into the list in the position after the iterator
        //Precondition: Iterator is pointed to certain element in the list
        //Postcondition: Iterator will be pointed to new element in the list.

        void remove_end();
        //Removes the value of the last element in the list
        //Precondition: there is a element available in the list
        //Postcondition: value of the last element in the list will be removed.

        void remove_start();
        //Removes the value of the first element in the list
        //Precondition: there is a first element in the list
        //Postcondition: the first element in the list will be removed.

        void add_end(listitem data);
        //Inserts a new element at the end of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: a new element will be added to the end of the list

        void add_start(listitem data);
        //Inserts a new element at the start of the list
        //If the list is empty, the new element becomes both start and end
        //Postcondition: a new element will be added at the start of the list.


        void remove_cursor();
        //Removes the element pointed at by the iterator
        //Precondition: iterator is pointing at some element
        //Postcondition: iterator will be pointing at different element

        void move_cursor();
        //Moves the iterator forward by one element in the list
        //Precondition: iterator is pointed at the element
        //Postcondition: iterator will be pointed at the other element


        /**Additional List Operations*/

        void print();
        //Prints to the console the value of each element in the list sequentially
        //and separated by a blank space
        //Prints nothing if the list is empty

        bool operator==(const List &list);

};

     template <class listitem>
     List<listitem>::List(): start(NULL), end(NULL), cursor(NULL), length(0) {}

     template <class listitem>
     List<listitem>::~List()
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

     template <class listitem>
     List<listitem>::List(const List &list): length(list.length)
     {
         if(list.start == NULL)
         {
             start = end = cursor = NULL;
         }
         else
         {
             start = new Node(list.start->data); //using second Node constructor
             NodePtr temp = list.start; //set a temporary node pointer to point at the start of the original list
             cursor = start; //set iterator to point to start of the new list

             while(temp->next != NULL)
             {

                 temp = temp->next; //advance up to the next node in the original list

                 cursor->next = new Node(temp->data); //using node constructor to create a new node with copy of data
                 cursor = cursor->next; //advance to this new node

             }
             end = cursor;
             cursor = NULL;
         }
     }

    template<class listitem>
    void List<listitem>::remove_start()
	{
        assert(length != 0);
        if(length ==1)
    	{
    		delete start;
    		start = end = cursor = NULL;
    		length = 0;
    	}
    	else
    	{
    		start = start->next;
    		delete start->previous;
    		start->previous = NULL;
    		length --;
    	}
    }
    template<class listitem>
    void List<listitem>::remove_end()
	{
        assert(length != 0);
    	if(length ==1)
    	{
    		delete end;
    		end = start = cursor = NULL;
    		length = 0;
    	}
    	else
    	{
    		end = end->previous;
    		delete end->next;
    		end->next = NULL;
    		length --;
    	}
    }

     template <class listitem>
 	void List<listitem>::add_start(listitem data)
 	{
 		if (length==0)
 		{
 			start = new Node(data);
 			end = start;
 		}
 		else
 		{
 			NodePtr N = new Node(data);
 			N->next = start;
 			start->previous = N;
 			start = N;
 		}
 		length++;
 	}
     template <class listitem>
 	void List<listitem>::add_end(listitem data)
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
 				N->previous = end;
 				end = N;
 			}
 			length++;
 	}

   template <class listitem>
   void List<listitem>::begin_cursor()
   {
	   if(length == 0)
	   {
		   cout << "List is empty" << endl;
	   }
	   else
	   {
		   cursor = start;
	   }
   }
   template<class listitem>
   void List<listitem>::remove_cursor()
      {
   	   assert(length != 0);
   	   if(length == 1)
   	   {
   		   delete cursor;
   		   cursor = start = end = NULL;
   		   length = 0;
   	   }
   	   if(length == 2)
   	   {
   		   NodePtr temp = cursor->next;
   		   delete cursor;
   		   cursor = start = end = temp;
   		   length--;
   	   }
   	   else
   	   {
	        cursor->previous->next = cursor->next;
	        cursor->next->previous = cursor->previous;
	        delete cursor;
	        cursor = NULL;
	        length--;
   	   }
      }
   template<class listitem>
   void List<listitem>::add_cursor(listitem data)
   {
	   assert (length!=0);
	   if (length == 1)
	   {
		   NodePtr N = new Node(data);
		   N->next = NULL;
	      	N->previous = cursor;
	      	cursor->next = N;
	      	length++;
	   }
	   else
	       {
	          NodePtr N = new Node(data);
	          N->next = cursor->next;
	          N->previous = cursor;
	          cursor->next->previous = N;
	          cursor->next = N;
	          length++;
	       }

    }

   template<class listitem>
   void List<listitem>::print()
	{
		NodePtr temp = start;
		while(temp != NULL)
		{
			if(temp != NULL)
			{
				cout << temp->data << " ";
			}

			temp = temp -> next;
		}
		cout << endl;
   }


   template <class listitme>
   void List<listitme>::move_cursor()
   {
	   assert(length != 0);

	   if(cursor == NULL)
	   {
	      cout << "The iterator is off the end." << endl;
	   }
 	   else if(cursor != NULL)
	   {
 	       cursor = cursor->next;
	   }
	   else
	   {
	      while(cursor->next != NULL)
	      {
   	       cursor = cursor->next;
	      }
	   }
   }

    template <class listitem>
    listitem List<listitem>::get_start()
	{
    	assert(start != NULL);
    	return start -> data;
	}
    template <class listitem>
    listitem List<listitem>::get_end()
	{
    	assert(end != NULL);
    	return end -> data;
	}
    template <class listitem>
    int List<listitem>::get_length()
	{
		return length;
	}

    template <class listitem>
    listitem List<listitem>::get_cursor()
	{
    	assert(cursor != NULL);
    	return cursor->data;
	}

    template <class listitem>
	bool List<listitem>::is_empty()
	{
		return (length==0);
	}

    template <class listitem>
    bool List<listitem>::off_end()
    {
    	assert(!is_empty());
    	if(cursor == NULL)
    	{
    		return true;
    	}
    	else
    	{
    		return false;
    	}
    }

    template <class listitem>
    bool List<listitem>::operator==(const List& list)
    {
        if(length != list.length)
            return false;
        NodePtr temp1 = start;
        NodePtr temp2 = list.start;
        while(temp1 != NULL)
        {
            if(temp1->data != temp2->data)
                return false;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        return true;
    }


#endif /* LIST_H_ */
