#include "Hash_Table.cpp"
#include "Hash_Table_Search.cpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class Search {
	private:
		Hash_Table* ht;
		Hash_Table_Search* hts;
		string useless[21] = { "there", "a", "the" , "of", "to", "and", "but", "nor", "or", "some", "any",
							"very", "in", "on", "at", "before", "after", "into", "over", "through", "along"};
		vector<string> files = { "almightygosh.txt", "areweready.txt", "byebye.txt", "electrify.txt", "explotar.txt", "highandlow.txt", "painting.txt",
							 "paperroute.txt", "porcelain.txt", "raging.txt", "sameoldblues.txt", "sendthemoff.txt", "shelter.txt", "surprise.txt", "tearingmeup.txt"};
	public:
		Search(){
			ht = NULL;
			hts = NULL;
		}
		void insert(Song s){
			ofstream fout("output.txt");
			fout << s.get_artist() << endl;
			fout << s.get_title() << endl;
			fout << s.get_genre() << endl << endl << endl;
			fout << s.get_lyrics() << endl;
			files.push_back("output.txt");
			buildAssignmentTable();
			buildInvertedIndex();
		}

		void remove(string title){
			for (int i = 0; i < files.size(); i++){
				ifstream fin(files[i]);
				if(fin.fail()){
					cout << "Input failed to open" << endl;
					exit(-1);
				}
				string line;
				getline(fin, line);
				getline(fin, line);
				if(line == title){
					files.erase(std::remove(files.begin(), files.end(), files[i]), files.end());
					cout << "Song has been successfully removed." << endl;
					return;
				}
			}
			cout << "Song is not on the list." << endl;
			buildAssignmentTable();
			buildInvertedIndex();
		}

		void buildAssignmentTable(){
			delete hts;
			hts = new Hash_Table_Search();
			int count = 0;
			for (int i = 0; i < files.size(); i++){
				ifstream fin(files[i]);
				if(fin.fail()){
					cout << "Input failed to open" << endl;
					exit(-1);
				}
				string line;
				getline(fin, line);
				getline(fin, line);
				getline(fin, line);
				getline(fin, line);
				getline(fin, line);

				while(getline(fin, line)){
					vector<string> vec;
					istringstream iss(line);
					while (iss) {
			       		string word;
			        	iss >> word;
			        	transform(word.begin(), word.end(), word.begin(), ::tolower);
			        	vec.push_back(word);
			    	}
			    	for(int k = 0; k < vec.size(); k++){
			    		for(int j = 0; j < 21; j++){
			    			if(vec[k] == useless[j]){
			    				vec.erase(remove_if(vec.begin(), vec.end(), [&]( const string& str )
			    				{
			        			return std::find(begin(useless), end(useless), str ) != end(useless);
			    				}), vec.end());
			    			}
			    		}
			    		wordID w(vec[k], -1);
			    		if (hts->find(vec[k]) == -1){
			    			w.setID(count);
			    			hts->insert(w);
			    			count++;
			    		}
					}
				}
			}
		}

		void buildInvertedIndex(){
			delete ht;
			ht = new Hash_Table();
			int count = 0;
			for (int i = 0; i < files.size(); i++){
				Song s;
				ifstream fin(files[i]);
				if(fin.fail()){
					cout << "Input failed to open" << endl;
					exit(-1);
				}

				string line;
				getline(fin, line);
				s.set_artist(line);
				getline(fin, line);
				s.set_title(line);
				getline(fin, line);
				s.set_genre(line);
				getline(fin, line);
				getline(fin, line);

				string lyric;

				while(getline(fin, line)){
					lyric += "\n\t" + line;
					s.set_lyrics(lyric);
				}

				ifstream fin1(files[i]);
				if(fin1.fail()){
					cout << "Input failed to open" << endl;
					exit(-1);
				}

				getline(fin1, line);
				getline(fin1, line);
				getline(fin1, line);
				getline(fin1, line);
				getline(fin1, line);

				while(getline(fin1, line)){

					vector<string> vec;
					istringstream iss(line);
					while (iss) {
			       		string word;
			        	iss >> word;
			        	transform(word.begin(), word.end(), word.begin(), ::tolower);
			        	vec.push_back(word);
			    	}
			    	for(int k = 0; k < vec.size(); k++){
			    		for(int j = 0; j < 21; j++){
			    			if(vec[k] == useless[j]){
			    				vec.erase(remove_if(vec.begin(), vec.end(), [&]( const string& str )
			    				{
			        			return std::find(begin(useless), end(useless), str ) != end(useless);
			    				}), vec.end());
			    			}
			    		}
			    		ht->insert(hts->find(vec[k]), s);
					}
				}
			}
		}

		void print_ht(){
			ht->print();
		}

		void print_hts(){
			hts->print();
		}

		void searchKeyword(string word){
			int index = hts->find(word);
			if (index < 0 or index > 1000){
				cout << "Word not found." << endl;
			} else {
				ht->print_bucket(index);
				cout << endl;
			}

		}
};


/*1. Read in a word from a file
2. Determine whether it has already been assigned an id
2a. Search the wordid hash table to see if the word is there.
2aa. If the word is found in the WordID hash table, return it's id
2ab. If the word is not found in the WordID hash table, assign it an id = counter++; and insert it into the wordID hash table
3. Insert the Haiku that contains that word into the hash table at index = id*/
