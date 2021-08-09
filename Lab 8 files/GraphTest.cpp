//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* GraphTest.cpp

*/
//============================================================================

#include "Graph.cpp"
#include "Graph.h"
#include<iostream>

using namespace std;

int main()
{
    Graph g(6);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 6);

    cout << "The number of Vertices: " << g.get_num_vertices() << endl;
    cout << "The number of Edges: " << g.get_num_edges() << endl;

    /*cout << endl;

    g.print_graph(cout);

    cout << endl;
    cout << endl;
    cout << "Test of BFS with 1:" << endl;
    g.breadth_first_search(1);
    g.print_BFS(cout);
    cout << "The distance from 1 to 5 is ";
    //code for distance
    cout << "A shortest 1-5 path is: ";
    g.print_path(1, 5, cout);
    cout << endl;

    cout << "Test of BFS with 2:" << endl;
    g.breadth_first_search(2);
    g.print_BFS(cout);
    cout << "The distance from 2 to 3 is ";
    //code for distance
    cout << "A shortest 2-3 path is: ";
    g.print_path(2, 3, cout);
    cout << endl;


    if(g.is_empty())
       {
           cout << "We have an empty graph." << endl;
       }
       else
       {
           cout << "This graph isn't empty." << endl;
       }*/
}

