#include "Hash_Table.h"
#include <iostream>
#include <assert.h>



using namespace std;

Hash_Table::Hash_Table(){}

Hash_Table::~Hash_Table(){}

int Hash_Table::hash(int index){
    return index;
}

/*int Hash_Table::count_bucket(int index){
    return Table[index].getSize();
}*/

bool Hash_Table::find(Song b){
    for(int i = 0; i < SIZE; i++){
        if(Table[i].isEmpty()){
            return false;
        }
        return Table[i].find(b);
    }
}

void Hash_Table::insert(int i, Song s){
    int index = hash(i);
    Table[index].insert(s);
}

void Hash_Table::print_bucket(int index){
    Table[index].inOrderPrint(cout);
}

void Hash_Table::print(){
    for(int i = 0; i < SIZE; i++){
        cout << "Table[" << i << "]: ";
        Table[i].inOrderPrint(cout);
        cout << endl;
    }
}
