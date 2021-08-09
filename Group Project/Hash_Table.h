#ifndef HASH_TABLE_H_
#define HASH_TABLE_H_

#include <string>
#include <iostream>
#include "BinarySearchTree.h"
#include "Song.cpp"
#include "Hash_Table_Search.h"
using namespace std;

class Hash_Table {
public:
    /**Constructors*/

    Hash_Table();
    //constructor

    ~Hash_Table();
    //destructor

    /**Access Functions*/

    int hash(int index);
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: title + author

    /*int count_bucket(int index);
    //counts the number of Songs at this index
    //returns the count
    //pre: 0<= index < SIZE*/


    bool find(Song b);
    //Searches for b in the table
    //returns the index at which b is located
    //returns -1 if b is not in the table

    /**Manipulation Procedures*/

    void print_bucket(int index);

    void insert(int i, Song s);
    //inserts a new Song into the table
    //calls the hash function on the key to determine
    //the correct bucket

    void print();

    /*void remove(Song b);
    //removes b from the table
    //calls the hash function on the key to determine
    //the correct bucket
    /**Additional Functions*/

    /*void print_bucket(int index);
    //Prints all the Songs at index
    //pre: 0<= index < SIZE
    //Should print according to the following formula:
    //"Printing index <index#>
    //skips two lines
    //Next, prints each Song at that index in the format:
    //<title>
    //by <author>
    //ISBN #: <isbn>
    //Price: $<X.XX>
    //followed by a blank line
    void print_table();
    //Prints the first Song at each index
    //along with a count of the total Songs
    //at each index by calling count_bucket
    //as a helper function
    //Prints in the format:
    //<----------------------->
    //Bucket: <index>
    //<title>
    //by <author>
    //ISBN #: <isbn>
    //Price: $<X.XX>
    //Number of Songs at this bucket: <number of elements at this index>
    //<----------------------->*/
private:
    static const int SIZE = 1000;
    BinarySearchTree<Song> Table[SIZE];
};

#endif /* HASH_TABLE_H_ */
