//Andrew Claudy & JT Broad
//Intro to Algorithms w/ Dr. Yeager
//Due 2355 on 09 Dec 2013
//Description:
//Implements the Prim's Algorithm for finding the MST.
//This algorithm EDITS the G's vertex properties.
//This algorithm assumes the G is fully connected.

#pragma once

#include <vector>
using std::vector;

#include <deque>
using std::deque;

#include "GraphDataStructures.h"

//Helper function declarations
bool doesItContainThisValue(const deque<int>& deque_, int value_);
int extractMin(deque<int>& deque_, const Graph_AdjacenyListBased& G);
//end of helper function declarations

//This algorithm EDITS the G's vertex properties
void PrimAlgorithm(Graph_AdjacenyListBased& G, int idOfStartVertex)
{
	int idOfVertexCurrentlyUnderExamination;
	deque<int> Q; //A queue of the ids in G that need to be breadth-scanned for the least weight edge.

	//Exceptional case: if the graph input is empty, return empty tree.
	if(G.getSizeInVerticies() < 1)
		return;
	//Exceptional case: if the start index does not exist, return empty tree.
	if(!G.hasVertex(idOfStartVertex))
		return;

	//Initialize a tree. done already above.
	//Line 5 of the algorithm ... iterate over the map and push into Q.
	for(auto iter = G.graph.begin(); iter != G.graph.end(); iter++)
	{
		Q.push_back(iter->first);
		iter->second.key = MAX_INT;
		iter->second.pi = MAX_INT;
	}
	//Set the root of the tree to equal the trunk of ISP network
	G.graph.at(idOfStartVertex).key = 0; //Line 4 of the algorithm


	//Start loop
	while(!Q.empty()) //Line 6 of the algorithm
	{
		//Grab the next vertex. (Line 7)
		idOfVertexCurrentlyUnderExamination = extractMin(Q, G);

		//Look at the adjacency list, cycle through looking for the unvisited least weight. (Line 8)
		auto edgeToTest = G.graph.at(idOfVertexCurrentlyUnderExamination).adjacent.begin();
		while(edgeToTest != G.graph.at(idOfVertexCurrentlyUnderExamination).adjacent.end())
		{
			//TODO: Remove this code block if doing undirected graphiness
			if(edgeToTest->destination == idOfVertexCurrentlyUnderExamination)
			{
				//Do nothing?
			}
			else
			{
				if(doesItContainThisValue(Q, edgeToTest->destination) && //if v is a member of Q
					edgeToTest->weight < G.graph.at(edgeToTest->destination).key) //if w(u, v) < key(v) (Line 9)
				{
					//Line 10-11
					G.graph.at(edgeToTest->destination).key = edgeToTest->weight;
					G.graph.at(edgeToTest->destination).pi = edgeToTest->source;
				}
			}
			edgeToTest++; //Iterate to the next edge
		}
		//Grow the tree by one edge from one of the vertices not in the tree yet.
			//MST.addVertex(leastWeightFoundDestinationID); //Vertex copy ctor?
			//MST.addEdge(idOfVertexCurrentlyUnderExamination, leastWeightFoundDestinationID, leastWeightFoundAtThisVertex); //Edge copy ctor instead?
		//NOTE: The edge must be the minimum-weight edge from that vertex. So in,
		//other words, find the greediest short sighted immediate solution.
		//Repeat until all vertices have been added into the tree.
		if(G.graph.at(idOfVertexCurrentlyUnderExamination).key == MAX_INT)
		{
			Q.push_back(idOfVertexCurrentlyUnderExamination); // Send the vertex to the back of the line.
			// Assumes the graph is fully connected.
		}
	}
	//End Loop
}

//Returns true if the value_ is found in the deque_.
bool doesItContainThisValue(const deque<int>& deque_, int value_)
{
	for(deque<int>::const_iterator iter = deque_.begin(); iter != deque_.end(); iter++)
	{
		if(*iter == value_)
			return true;
	}
	return false;
}

int extractMin(deque<int>& deque_, const Graph_AdjacenyListBased& G)
{
	int vertexID = -1;
	deque<int>::iterator eraseME;
	int minKey = INT_MAX;
	for(deque<int>::iterator iter = deque_.begin(); iter != deque_.end(); iter++)
	{
		if(G.graph.at(*iter).key < minKey)
		{
			minKey = G.graph.at(*iter).key;
			vertexID = *iter;
			eraseME = iter;
		}
	}
	deque_.erase(eraseME);
	return vertexID;
}