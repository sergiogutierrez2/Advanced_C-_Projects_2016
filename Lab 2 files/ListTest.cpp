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
    List<double> ListDoubles;
    List<int> ListInts;
    List<char> ListChars;
    List<string> ListStrings;

    ListDoubles.add_start(7.4);
    ListDoubles.add_start(4.4);
    ListDoubles.add_start(1.4);
    ListDoubles.add_end(11.4);
    ListDoubles.add_end(15.4);

    cout << "Should print 1.4, 4.4, 7.4, 11.4, 15.4:\n";
    ListDoubles.print();


    List<double> ListDoubles2(ListDoubles); //copy constructor
    cout << "Should print 1.4, 4.4, 7.4, 11.4, 15.4:\n";
    ListDoubles2.print();

    if (ListDoubles == ListDoubles2)
    {
    cout << "Both lists of doubles are the same!" << endl;
    }

    ListInts.add_end(7);
    ListInts.add_end(2);
    ListInts.add_end(9);
    ListInts.begin_cursor();
    ListInts.insert_cursor(15);
    ListInts.move_cursor();
    ListInts.insert_cursor(12);
    ListInts.add_end(4);
    ListInts.add_end(13);
    ListInts.remove_end();

    cout << "Should print 7 15 12 2 9 4:\n";
    ListInts.print();

    cout << "The Following should print 0:" << endl;
    cout << ListChars.get_length() << endl;
    cout << "This will fail the assertion, iterator is off the end of the list. Comment out when finished.\n";
        //ListChar.move_cursor();
        //Indeed, it failed assertion.

    ListChars.add_end('A');
    ListChars.add_end('B');
    ListChars.begin_cursor();
    ListChars.move_cursor();
    cout << "This should print B:" << endl;
    cout << ListChars.get_cursor() << endl;
    ListChars.move_cursor();
    cout << "This will fail the assertion, iterator is off the end of the list. Comment out when finished.\n";
    //cout << ListChars.get_cursor() << endl;
    //Indeed it failed.

    ListStrings.add_end("Hello");
    ListStrings.add_end("Professor!");
    cout << "This should print: Hello  Professor!\n";
    ListStrings.print();

    ListStrings.remove_end();
    ListStrings.remove_end();

    cout << "These next 2 should fail the assertion, iterator is off the end of the list. Comment out when finished.\n";
    //ListStrings.remove_end();
    //ListStrings.remove_start();
    //Yep, they failed.
	cout << endl;

}



/*  OUTPUT:

*****Student Test Code Begins Here: *****
Should print 1.4, 4.4, 7.4, 11.4, 15.4:
1.4  4.4  7.4  11.4  15.4
Should print 1.4, 4.4, 7.4, 11.4, 15.4:
1.4  4.4  7.4  11.4  15.4
Both lists of doubles are the same!
Should print 7 15 12 2 9 4:
7  15  12  2  9  4
The Following should print 0:
0
This will fail the assertion, iterator is off the end of the list. Comment out when finished.
This should print B:
B
This will fail the assertion, iterator is off the end of the list. Comment out when finished.
This should print: Hello  Professor!
Hello  Professor!
These next 2 should fail the assertion, iterator is off the end of the list. Comment out when finished.

 */


