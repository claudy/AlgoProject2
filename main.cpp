//Andrew Claudy & JT Broad
//Intro to Algorithms w/ Dr. Yeager
//Due 2355 on 09 Dec 2013
//Description:
//<insert description here>

#include <algorithm>
using std::pair;

#include <deque>
using std::deque;

#include <vector>
using std::vector;

#include <iostream>
using std::cout;
using std::endl;

#include <fstream>
using std::ifstream;

#include "Network.h"

#define edge pair<int,int>//format (w,(u,v))
                          //(weights, (node,node))

void main()
{
	Graph_AdjacenyListBased g;
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(5);
	g.addEdge(1, 2, 10);
	g.addEdge(3, 5, 2);
	cout << "# vertices=" << g.getSizeInVerticies() << "  edges=" << g.getSizeInEdges() << endl << endl;
	g.printVertexList(cout);
}