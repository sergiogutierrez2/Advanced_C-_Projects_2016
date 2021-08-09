#include <string>
#include <iostream>

using namespace std;

class wordID {
	private:
		string word;
		int id;
	public:
		wordID(){
			word = "";
			id = -1;
		}
		wordID(string w, int i){
			word = w;
			id = i;
		}
		void setID(int value){
			id = value;
		}
		int getID(){
			return id;
		}
		string getWord(){
			return word;
		}

		bool operator==(const wordID& rhs){
			return (word == rhs.word);
		}
};
