//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* Stack.cpp

*/
//============================================================================

#include "Stack.h"
#include "List.h"
#include <iostream>
#include <cstddef>

using namespace std;


Stack::Stack(){}

Stack::~Stack(){}

Stack::Stack(const  Stack &S):stack(S.stack){}

void Stack::pop()
{
    stack.remove_start();
}

void Stack::push(int data)
{
    stack.add_start(data);
}


bool Stack::operator==(const Stack &S)
{
	return stack == S.stack;
}

int Stack::get_top()
{
    return stack.get_start();
}

int Stack::get_size()
{
    return stack.get_length();
}

void Stack::print()
{
    stack.print();
}
