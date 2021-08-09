//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* BinarySearchTree.cpp

*/
//============================================================================
#include <assert.h>
#include <fstream>
#include <cstddef>
#include <sstream>
#include <string>
#include <iostream>
#include "BinarySearchTree.h"

using namespace std;

int main()
{
	ofstream writingfile ("outfile.txt");
	ifstream readingFile ("infile.txt");

	if (writingfile.is_open())
		{

	while (readingFile.is_open() && writingfile.is_open())
	{
		BinarySearchTree<int> myTree;
		string str;
		    if(getline(readingFile, str))
		    {
		    	istringstream iss(str);
		    	 int number;
		    	 while( iss >> number )
		    	 {
		    		 myTree.insert(number);
		    	 }
		    }

		    myTree.preOrderPrint(writingfile);
		    writingfile << endl;
		    myTree.inOrderPrint(writingfile);
		    writingfile << endl;

		    string str2;
		    if(getline(readingFile, str2))
		    		    {
		    	istringstream iss(str2);
		    	int number;
		    	while( iss >> number )
		    	 {
		    		if (myTree.find(number))
		    		    {
		    			writingfile << number << " was found in the Binary Search Tree." << endl;
		    			myTree.remove(number);
		    		    }
		    		    else
		    		    {
		    		    	writingfile << number << " was not found in the Binary Search Tree." << endl;
		    		    }
		    		}
		       }

		    string str3;
		    if(getline(readingFile, str3))
		    {
		    	istringstream iss(str3);
		    	int number;
		    	while( iss >> number )
		     {
		    		myTree.insert(number);
		     }
		   }

		    myTree.postOrderPrint(writingfile);

		    writingfile << endl;
		    writingfile << "The Root of the Tree is " << myTree.getRoot() << endl;
		    writingfile << "The Maximum value is " << myTree.maximum() << endl;
		    writingfile << "The Minimum value is " << myTree.minimum() << endl;
		    writingfile << "The size of the Binary Search Tree is " << myTree.getSize() << endl;
		    writingfile << "The height of the Binary Search Tree is " << myTree.getHeight() << endl;
		    writingfile << endl;

		    if (readingFile.eof())
		    {
			    readingFile.close();
			    writingfile.close();
		    }

	   }
	}

	else
	{
		cout << "The file was not opened.";
	}
}

/* infile.txt:
12 6 9 45 3 7 10 2 4 13
4
9
55 18 3 6 78 9
13
66
808 707 909 1001 505 1200 499 644 1190 1592
707
78
5 4 6 3 7 2 8 1 9
3
10

   Outfile.txt:
12 6 3 2 4 9 7 10 45 13
2 3 4 6 7 9 10 12 13 45
4 was found in the Binary Search Tree.
2 3 7 10 9 6 13 45 12
The Root of the Tree is 12
The Maximum value is 45
The Minimum value is 2
The size of the Binary Search Tree is 9
The height of the Binary Search Tree is 3

55 18 3 6 9 78
3 6 9 18 55 78
13 was not found in the Binary Search Tree.
9 6 3 18 66 78 55
The Root of the Tree is 55
The Maximum value is 78
The Minimum value is 3
The size of the Binary Search Tree is 7
The height of the Binary Search Tree is 4

808 707 505 499 644 909 1001 1200 1190 1592
499 505 644 707 808 909 1001 1190 1200 1592
707 was found in the Binary Search Tree.
78 499 644 505 1190 1592 1200 1001 909 808
The Root of the Tree is 808
The Maximum value is 1592
The Minimum value is 78
The size of the Binary Search Tree is 10
The height of the Binary Search Tree is 4

5 4 3 2 1 6 7 8 9
1 2 3 4 5 6 7 8 9
3 was found in the Binary Search Tree.
1 2 4 10 9 8 7 6 5
The Root of the Tree is 5
The Maximum value is 10
The Minimum value is 1
The size of the Binary Search Tree is 9
The height of the Binary Search Tree is 5

 */


