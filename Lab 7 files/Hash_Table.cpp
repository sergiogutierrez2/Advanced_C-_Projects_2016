//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* Hash_Table.cpp

*/
//============================================================================

#include "Hash_Table.h"
#include <iostream>
#include <cstdlib>

Hash_Table::Hash_Table()
{}
Hash_Table::~Hash_Table()
{}

int Hash_Table::hash(string key)
{
	int index = 0;
	int sum = 0;
	for(int i = 0; i < key.length(); i++)
	sum += (int) key[i];
	index = sum % SIZE;
	return index;
}

int Hash_Table::count_bucket(int index)
{
	if(index >= 0 && index < SIZE)
	{
		return Table[index].get_length();
	}
	else
	{
		return -1;
	}
}

int Hash_Table::find(Book b)
{
	int temp;
	temp = hash(b.get_title() + b.get_author());

	Table[temp].begin_cursor();

	while(!Table[temp].off_end())
	{
		if(Table[temp].get_cursor().get_isbn() == b.get_isbn())
		{
			return temp;
		}
		else
			Table[temp].move_cursor();
	}

	return -1;
}

void Hash_Table::insert(Book b)
{
	  int temp;
	  temp = hash(b.get_title() + b.get_author());
	  Table[temp].add_end(b);

}

void Hash_Table::remove(Book b)
{
	int temp = hash(b.get_title() + b.get_author());

	Table[temp].begin_cursor();

	while(!Table[temp].off_end())
	{
		if(Table[temp].get_cursor() == b )
		{
			Table[temp].remove_cursor();
		}
		else
		{
			Table[temp].move_cursor();
		}
	}

}

void Hash_Table::print_bucket(int index)
{
	if(index >= 0 && index < SIZE)
		{
		cout << "Printing bucket: " << index << endl << endl;
		Table[index].begin_cursor();

		while(!Table[index].off_end())
		   {
			 Book b = Table[index].get_cursor();
			 cout << b.get_title() << endl;
			 cout << "by "<< b.get_author() << endl;
			 cout << "ISBN#: " << b.get_isbn() << endl;
			 cout << "Price: $" << b.get_price() << endl << endl;
			 Table[index].move_cursor();
		   }
		}

		else
		{
			cout << endl;
			cout << "Index Does Not Exist.";}
}

void Hash_Table::print_table()
{
  for (int index = 0 ; index < SIZE ; index++)
  {
	  if(Table[index].get_length() != 0)
	 {
		Book b = Table[index].get_start();
		cout << "<----------------------->" << endl;
		cout << "Bucket: " << index << endl;
		cout << b.get_title() << endl;
		cout << "by "<< b.get_author() << endl;
		cout << "ISBN#: " << b.get_isbn() << endl;
		cout << "Price: $" << b.get_price() << endl;
		cout << "Number of books on this bucket: " << Table[index].get_length()<< endl;
		cout << "<----------------------->" << endl;
	}
   }
}
