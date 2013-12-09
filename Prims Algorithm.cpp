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

bool doesItContainThisValue(const deque<int>& deque_, int value_);

//This algorithm EDITS the G's vertex properties
Graph_AdjacenyListBased PrimAlgorithm(Graph_AdjacenyListBased& G, int idOfStartVertex)
{
	Graph_AdjacenyListBased MST; //Helps keep track of what has been visited.
	int idOfVertexCurrentlyUnderExamination;
	deque<int> Q; //A queue of the ids in G that need to be breadth-scanned for the least weight edge.

	//Exceptional case: if the graph input is empty, return empty tree.
	if(G.getSizeInVerticies() < 1)
		return MST;
	//Exceptional case: if the start index does not exist, return empty tree.
	if(!G.hasVertex(idOfStartVertex))
		return MST;

	//Initialize a tree. done already above.
	//Line 5 of the algorithm ... iterate over the map and push into Q.
	for(auto iter = G.graph.begin(); iter != G.graph.end(); iter++)
	{
		Q.push_back(iter->first);
		iter->second.key = MAX_INT;
		iter->second.pi = MAX_INT;
	}
	//Set the root of the tree to equal the trunk of ISP network
	MST.addVertex(idOfStartVertex);
	G.graph.at(idOfStartVertex).key = 0; //Line 4 of the algorithm


	//Start loop
	while(!Q.empty()) //Line 6 of the algorithm
	{
		//Grab the next vertex. (Line 7)
		idOfVertexCurrentlyUnderExamination = Q.front();
		Q.pop_front();

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
				if(doesItContainThisValue(Q, edgeToTest->destination) &&
					edgeToTest->weight < G.graph.at(edgeToTest->destination).key) //Line 9
				{
					//Line 10-11
					G.graph.at(edgeToTest->destination).key = edgeToTest->weight;
					G.graph.at(edgeToTest->destination).pi = edgeToTest->source;
					{
						MST.addVertex(edgeToTest->destination);
						Vertex *newV = &(MST.graph.find(edgeToTest->destination)->second);
						newV->key = edgeToTest->weight;
						newV->pi = edgeToTest->source;
					
						MST.addEdge(edgeToTest->source,
							edgeToTest->destination,
							edgeToTest->weight, 
							1); //Editing this property in G is too complicated right now.
					}
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
	return MST;
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