//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* Hash_Table_Test.cpp

*/
//============================================================================
#include "Hash_Table.h"
#include <string>
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	Hash_Table ht;
	Book pp("Pride and Prejudice", "Jane Austen", 1234567, 4.95);
	Book c("Contact", "Carl Sagan", 99993339, 9.95);
	Book hg("The Hunger Games", "Suzanne Collins", 12388888, 13.55);
	Book hp("Harry Potter", "J.K. Rowlings", 55555678, 12.99);
	Book mhc("The Man in the High Castle", "Philip K Dick", 95959595, 15.95);
	Book bh("Bleak House", "Charles Dickens", 473890238, 8.00);

	//Testing Insert to see if it works:
	ht.insert(pp);
	ht.insert(c);
	ht.insert(hg);
	ht.insert(mhc);
	ht.insert(bh);

	ht.print_bucket(9);

	ht.print_table();

	//Testing count_bucket:
	cout << endl;
    cout << "Here are the number of books at this index 9: " <<  ht.count_bucket(9) << endl;

	//Testing Find:
    cout << endl;
	cout << "Searching for Harry Potter:" << endl;
	if(ht.find(hp) > 0)
	{
		cout << "Harry Potter was found at Index: " << ht.find(hp) << endl;
	}
		else
	{
		cout << "Harry Potter does not exist." << endl;
	}

	cout << "Searching for The Man in the High Castle:" << endl;
	if(ht.find(mhc) > 0)
	{
		cout << "The Man in the High Castle was found at Index: " << ht.find(mhc) << endl;
	}
			else
	{
		cout << "The Man in the High Castle does not exist." << endl;
	}

    cout << endl;
	//Testing Remove
	ht.remove(hg);
	cout << "Removed Hunger Games." << endl;
	cout << "Now Bucket 9 should only show The Main the High Castle: " << endl;
	cout << endl;
	ht.print_bucket(9);

}
/*
OUTPUT:

Printing bucket: 9

The Hunger Games
by Suzanne Collins
ISBN#: 12388888
Price: $13.55

The Man in the High Castle
by Philip K Dick
ISBN#: 95959595
Price: $15.95

<----------------------->
Bucket: 0
Bleak House
by Charles Dickens
ISBN#: 473890238
Price: $8
Number of books on this bucket: 1
<----------------------->
<----------------------->
Bucket: 2
Pride and Prejudice
by Jane Austen
ISBN#: 1234567
Price: $4.95
Number of books on this bucket: 1
<----------------------->
<----------------------->
Bucket: 4
Contact
by Carl Sagan
ISBN#: 99993339
Price: $9.95
Number of books on this bucket: 1
<----------------------->
<----------------------->
Bucket: 9
The Hunger Games
by Suzanne Collins
ISBN#: 12388888
Price: $13.55
Number of books on this bucket: 2
<----------------------->

Here are the number of books at this index 9: 2

Searching for Harry Potter:
Harry Potter does not exist.
Searching for The Man in the High Castle:
The Man in the High Castle was found at Index: 9

Removed Hunger Games.
Now Bucket 9 should only show The Main the High Castle:

Printing bucket: 9

The Man in the High Castle
by Philip K Dick
ISBN#: 95959595
Price: $15.95
*/
