//============================================================================
/**

* Sergio Gutierrez

* CIS 22C

* Graph.cpp

*/
//============================================================================

#include "Graph.h"
#include "List.h"
#include<iostream>
#include <vector>
#include <cstdlib>
#include <iomanip>
#include <queue>
using namespace std;

Graph::Graph(int n)
{
    vertices = n;
    edges = 0;

 for(int i=0; i<=vertices; i++)
  {
   color.push_back('W');
   distance.push_back(-1);
   parent.push_back(0);
   adj.push_back(List<int>());
  }

}


Graph::~Graph()
{
    adj.clear();
    color.clear();
    distance.clear();
    parent.clear();
    edges = 0;
    vertices = 0;
}


int Graph::get_num_edges()
{
  return edges;
}


int Graph::get_num_vertices()
{
  return vertices;
}


bool Graph::is_empty()
{
   if(vertices == 0)
   {
     return true;
   }
   else
   {
    return false;
   }
}

     void Graph::addEdge(int u, int v)
{
    	 if(u != v)
    	 	{
    	 		adj.at(u).add_end(v);
    	 		adj.at(v).add_end(u);
    	 	}
    	 	else
    	 	{
    	 		adj.at(u).add_end(v);
    	 	}

    	 	edges ++;
}

void Graph::print_graph(ostream& output)
{
      for(unsigned index = 0; index < adj.size(); index++)
     {
	     if(!adj[index].is_empty())
	    {
	       output << index << ": ";
	       adj[index].begin_cursor();
	       while(!adj[index].off_end())
	         {
	            output << adj[index].get_cursor() << " ";
	            adj[index].move_cursor();
	         }
	            output << endl;
	      }
	  }

}

void Graph::print_BFS(ostream& output)
{
    output << "V" << setw(8) << "C" << setw(8) << "P" << setw(8) << "D" << endl;

    for(int index = 0; index < adj.size(); index++)
   {
        if(!adj[index].is_empty())
        {
            output << index << setw(8) << color[index] << setw(8) <<  parent[index] << setw(8) <<  distance[index] << endl;
        }
    }
}

void Graph::breadth_first_search(int source)
{
    queue<int> q;
    for(unsigned i = 0; i < adj.size(); i++)
    {
        color[i] = 'W';
        distance[i] = -1;
        parent[i] = 0;
    }
    color[source] = 'G';
    distance[source] = 0;

    q.push(source);
    while(!q.empty())
    {
      int x = q.front();
      q.pop();
      adj[x].begin_cursor();
      while(!adj[x].off_end())
      {
           if (color[adj[x].get_cursor()] == 'W')
           {
             color[adj[x].get_cursor()] = 'G';
             distance[adj[x].get_cursor()] = distance[x] + 1;
             parent[adj[x].get_cursor()] = x;
             q.push(adj[x].get_cursor());
            }
            adj[x].move_cursor();
        }

        color[x] = 'B';
    }
}

void Graph::print_path(int source, int destination, ostream &output)
{
	if (destination == source)
	{
	   output << source << " ";
	}

	else if (parent[destination] == 0)

	 {
	    output << "No" << source << "-" << destination << "path exists" << endl;
	 }

	else
	{
	    print_path(source, parent[destination], output);
	    output << destination << " ";
	}
}

