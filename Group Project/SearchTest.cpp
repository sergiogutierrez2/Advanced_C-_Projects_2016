
#include "Search.cpp"
#include <iostream>

using namespace std;

int main(){
	string files[15] = { "almightygosh.txt", "areweready.txt", "byebye.txt", "electrify.txt", "explotar.txt", "highandlow.txt", "painting.txt",
						"paperroute.txt", "porcelain.txt", "raging.txt", "sameoldblues.txt", "sendthemoff.txt", "shelter.txt", "surprise.txt", "tearingmeup.txt"};
	Search s;
	s.buildAssignmentTable();
	s.buildInvertedIndex();


}
