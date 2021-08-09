//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* Palindrome.cpp

*/
//============================================================================
#include <iostream>
#include "Queue.h"
#include "Stack.h"
#include <fstream>
#include <cctype>

using namespace std;

int main()
{
   string text;
   ifstream infilestream ("Palindrome.txt");

	if (infilestream.is_open())
	{
	 while(getline (infilestream, text))
		{
		 Queue X;
		 Stack Y;

		for(int index = 0; index < text.length(); index++)
		{
			string letter;

			if(isalpha(text[index]))
			{
			letter = tolower(text[index]);
			X.enqueue(letter);
			Y.push(letter);
			}
		}

		bool equal = true;

		while(equal == true && X.get_length() != 0)
	  {
		 if(X.get_front() != Y.get_top())
		{
			 equal = false;
		}
		 X.dequeue();
		 Y.pop();
	  }


		if(equal == true)
		{
		  cout << text << " (Palindrome)" << endl;
		}
		else
		{
		cout << text << " (Not a Palindrome)"<< endl;
		}
	}

		infilestream.close();
	}
	else
	{
		cout << "Failed to open text file.";
	}

}


/*
******************OUTPUT:**************
A man, a plan, a canal, Panama. (Palindrome)
Do geese see God? (Palindrome)
Never odd. Even. (Not a Palindrome)
Never odd or even. (Palindrome)
Eye (Palindrome)
Ear (Not a Palindrome)
Able was I ere I saw Elba! (Palindrome)
Was it Eliot's toilet I saw? (Palindrome)
Race cars (Not a Palindrome)
*/

