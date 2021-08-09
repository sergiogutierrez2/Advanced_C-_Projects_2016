//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* Queue.h

*/
//============================================================================

#ifndef QUEUE_H_
#define QUEUE_H_

#include<string>
#include <iostream>
#include <cstddef>
using namespace std;

class Queue
{
    public:
        /**constructors and destructors*/

        Queue();
        //initializes an empty queue
        //postcondition: an empty queue

        Queue(const Queue &queue);
        //initializes queue to have same elements as another queue
        //postcondition: a copy of queue

        ~Queue();
        //frees memory allocated to the queue
        //postcondition: memory for queue has been freed

        /**manipulation procedures*/

        void dequeue();
        //removes an element from the front of the queue
        //precondition: the queue isn't empty
        //postcondition: an element has been removed from the front of the queue

        void enqueue(string data);
        //adds an element to the end of the queue
        //postcondition: an element added to the end of the queue

        /**accessors*/

        bool operator==(const Queue &queue);
        //returns whether this queue is equal to another queue

        string get_front();
        //returns the element at the front of the queue
        //precondition: the queue is not empty

        int get_length();
        //returns the size of the queue

        bool is_empty();
        //returns whether the queue is empty

        /**additional queue operations*/
        void print();
        //prints the elements in the queue in a programmer-specified format to stdout


    private:
        struct Node
        {
            string data;
            Node* next;
            Node(): next(NULL), data(""){}
            Node(string data): next(NULL), data(data){}
        };

        typedef struct Node* NodePtr;

        NodePtr front;
        NodePtr end;
        int length;

};




#endif /* QUEUE_H_ */
