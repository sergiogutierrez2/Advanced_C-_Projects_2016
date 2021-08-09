#include "Hash_Table_Search.h"
#include <iostream>
#include <assert.h>

using namespace std;

Hash_Table_Search::Hash_Table_Search(){}

Hash_Table_Search::~Hash_Table_Search(){}

int Hash_Table_Search::hash(wordID b){
    return b.getID();
}

int Hash_Table_Search::find(string word){
    for(int i = 0; i < SIZE; i++){
        if (Table[i].getWord() == word){
            return i;
        }
    }
    return -1;
}

void Hash_Table_Search::insert(wordID b){
    int index = hash(b);
    Table[index] = b;
}

void Hash_Table_Search::print(){
    for (int i = 0; i < SIZE; i++){
        cout << "Table[" << i << "]: " << Table[i].getWord() << endl;
    }
}
