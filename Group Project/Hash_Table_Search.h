#ifndef Hash_Table_Search_H_
#define Hash_Table_Search_H_

#include <string>
#include "wordid.cpp"

using namespace std;

class Hash_Table_Search {
public:
    /**Constructors*/

    Hash_Table_Search();
    //constructor

    ~Hash_Table_Search();
    //destructor

    /**Access Functions*/

    int hash(wordID b);
    //returns the hash value for the given key
    //the hash value is the sum of
    //of the ASCII values of each char in the key
    //% the size the of the table
    //Key for this table: title + author

    int find(string word);
    //Searches for b in the table
    //returns the index at which b is located
    //returns -1 if b is not in the table

    /**Manipulation Procedures*/

    void insert(wordID b);
    //inserts a new wordID into the table
    //calls the hash function on the key to determine
    //the correct bucket

    void print();

private:
    static const int SIZE = 1000;
    wordID Table[SIZE];
};

#endif /* Hash_Table_Search_H_ */
