//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* BST.cpp

*/
//============================================================================

#include <iostream>
#include <fstream>
#include <sstream>
#include "Graph.cpp"
using namespace std;

/*int main()

{
	ofstream output("output.txt");
	ifstream input("input.txt");

	if(input.is_open())
    {
      ofstream fout("outfile.txt");
      int num;
      input >> num;
      Graph g(num);
      int x, y;
      while(input >> x >> y)
       {
    	  if(!(x == 0 && y == 0))
         {
          g.addEdge(x, y);
         }
      }
       g.print_graph(fout);

    while(input >> x >> y)
       {
        if(!(x == 0 && y == 0))
        {
          g.breadth_first_search(x);
          fout << "A shortest " << x << "-" << y << " path is: ";
          g.print_path(x, y, fout);
          fout << endl;
       }
     }
   }

	else
	{
	     cout << "The file could not be opened.\n";
     }


}*/
