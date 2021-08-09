/**
* @author Sergio Gutierrez
* CIS 22C
* StackTest.cpp
*/

#include "Stack.h"
#include "List.h"
#include <iostream>
#include <cstddef>

using namespace std;

int main()

{
Stack X;

cout << "The following will fail the assertion, it will be Commented out when finished.\n";
//cout << X.get_top() << endl;

cout << endl;
cout << "The following will display 0: \n";
cout << X.get_size() << endl;

X.push(40);
X.push(30);
X.push(20);
X.push(10);

cout << "The following will display 10, 20, 30, 40: \n";
X.print();

cout << "The following will display 4: \n";
cout << X.get_size() << endl;
cout << "The following will display 10: \n";
cout << X.get_top() << endl;

Stack Y(X); // Using Copy Constructor
cout << "The copy will also display 10, 20, 30, 40: \n";
Y.print();

if (X == Y)
    {
       cout << "Both values are the same!" << endl;
    }
else
   {
    cout << "They are not equal." << endl;
    }

Y.pop();
Y.pop();
Y.pop();

cout << "The following will display 1: \n";
cout << Y.get_size() << endl;

Y.push(39);
Y.push(38);
Y.push(37);

cout << "The following will display 37, 38, 39, 40: \n";
Y.print();



if (X == Y)
    {
       cout << "Both values are the same!" << endl;
    }
else
   {
    cout << "They are not equal." << endl;
    }

}

/*OUTPUT:
 *
The following will fail the assertion, it will be Commented out when finished.

The following will display 0:
0
The following will display 10, 20, 30, 40:
10  20  30  40
The following will display 4:
4
The following will display 10:
10
The copy will also display 10, 20, 30, 40:
10  20  30  40
Both values are the same!
The following will display 1:
1
The following will display 37, 38, 39, 40:
37  38  39  40
They are not equal.
 */



