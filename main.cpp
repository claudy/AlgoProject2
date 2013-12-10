//Andrew Claudy & JT Broad
//Intro to Algorithms w/ Dr. Yeager
//Due 2355 on 09 Dec 2013
//Description:
//Driver

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


void main()
{
#pragma region Testing of the Prims Implementation
	Graph_AdjacenyListBased g;
	g.addVertex(1);
	g.addVertex(2);
	g.addVertex(3);
	g.addVertex(4);
	g.addVertex(5);
	g.addEdge(1, 2, 7);
	g.addEdge(2, 3, 6);
	g.addEdge(3, 5, 9);
	g.addEdge(3, 4, 8);
	g.addEdge(3, 1, 124);
	cout << "# vertices=" << g.getSizeInVerticies() << "  edges=" << g.getSizeInEdges() << endl << endl;
	g.printVertexList(cout);
	cout << "===========" << endl;
	cout << "After PrimAlgorithm(g, 1);" << endl;
	PrimAlgorithm(g, 1);
	g.printVertexList(cout);
	cout << "===========" << endl;
	///////////////////////
	Graph_AdjacenyListBased h;
	h.addEdge(1, 2, 4);
	h.addEdge(1, 3, 2);
	h.addEdge(1, 5, 3);
	h.addEdge(3, 5, 6); 
	h.addEdge(3, 6, 3);
	h.addEdge(3, 4, 1);
	h.addEdge(2, 4, 5);
	h.addEdge(4, 6, 6);
	h.addEdge(5, 6, 2);
	h.printVertexList(cout);
	cout << "===========" << endl;
	cout << "After PrimAlgorithm(h, 1);" << endl;
	PrimAlgorithm(h, 1);
	h.printVertexList(cout);
	cout << "===========" << endl;
	system("cls");
	///////////////////////
	
	//Graph_AdjacenyListBased m;
	//m.addEdge(1, 2, 2);
	//m.addEdge(2, 1, 2);
	//m.addEdge(1, 4, 1);
	//m.addEdge(4, 1, 1);
	//m.addEdge(2, 4, 2);
	//m.addEdge(4, 2, 2);
	//m.addEdge(3, 4, 3); //maybe switch
	//m.addEdge(4, 3, 3);
	//m.printVertexList(cout);
	//cout << "===========" << endl;
	//cout << "MST.printVertexList(cout);" << endl;
	//PrimAlgorithm(m, 1).printVertexList(cout);
	//cout << "-+-+-+-+-+-+-+-+-" << endl << "m.printVertexList(cout);" << endl;
	//m.printVertexList(cout);
#pragma endregion

#pragma region The actual use of the algorithm by the 'ISP'
	//Fiber optic cables prices vary wildly depending on the
	//Number of strands contained within the cable. 
	//See ebay for 'OUTDOOR 300FT 4 STRAND BULK 50/125 MULTIMODE WATERPROOF FIBER OPTIC CABLE'.
	//
	Network network(300, 100, 11111);
	network.printVertexList(cout);
#pragma endregion

}