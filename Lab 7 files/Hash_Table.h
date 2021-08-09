//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* BinarySearchTree.h

*/
//============================================================================

#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <string>
#include "List.h"
#include "Book.h"
using namespace std;

class Hash_Table {
public:
    /**Constructors*/

    Hash_Table();
    //constructor

    ~Hash_Table();
    //destructor

    /**Access Functions*/

    int hash(string key);
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: title + author

    int count_bucket(int index);
    //counts the number of Books at this index
    //returns the count
    //pre: 0<= index < SIZE

    int find(Book b);
    //Searches for b in the table
    //returns the index at which b is located
    //returns -1 if b is not in the table

    /**Manipulation Procedures*/

    void insert(Book b);
    //inserts a new book into the table
    //calls the hash function on the key to determine
    //the correct bucket

    void remove(Book b);
    //removes b from the table
    //calls the hash function on the key to determine
    //the correct bucket

    /**Additional Functions*/

    void print_bucket(int index);
    //Prints all the books at index
    //pre: 0<= index < SIZE
    //Should print according to the following formula:
    //"Printing index <index#>
    //skips two lines
    //Next, prints each book at that index in the format:
    //<title>
    //by <author>
    //ISBN #: <isbn>
    //Price: $<X.XX>
    //followed by a blank line

    void print_table();
    //Prints the first book at each index
    //along with a count of the total books
    //at each index by calling count_bucket
    //as a helper function
    //Prints in the format:
    //<----------------------->
    //Bucket: <index>
    //<title>
    //by <author>
    //ISBN #: <isbn>
    //Price: $<X.XX>
    //Number of books at this bucket: <number of elements at this index>
    //<----------------------->

private:
    static const int SIZE = 10;
    List<Book> Table[SIZE];
};

#endif /* HASH_TABLE_H_ */

/*
 Printing bucket: 9

The Hunger Games
by Suzanne Collins
ISBN#: 12388888
Price: $13.55

The Man in the High Castle
by Philip K Dick
ISBN#: 95959595
Price: $15.95

removed the hunger games from the list
Printing bucket: 9

The Man in the High Castle
by Philip K Dick
ISBN#: 95959595
Price: $15.95


printing tables
<----------------------->
Bucket: 0
Bleak House
by Charles Dickens
ISBN#: 473890238
Price: $8
Number of books at this bucket: 1
<----------------------->

<----------------------->
Bucket: 2
Pride and Prejudice
by Jane Austen
ISBN#: 1234567
Price: $4.95
Number of books at this bucket: 1
<----------------------->

<----------------------->
Bucket: 4
Contact
by Carl Sagan
ISBN#: 99993339
Price: $9.95
Number of books at this bucket: 2
<----------------------->

<----------------------->
Bucket: 9
The Man in the High Castle
by Philip K Dick
ISBN#: 95959595
Price: $15.95
Number of books at this bucket: 1
<----------------------->

finding hunger games
hunger games not found
finding harry potter
harry potter is at index 4
there are 1 books at index 0

 */

