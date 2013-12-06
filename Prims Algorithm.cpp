//Andrew Claudy & JT Broad
//Intro to Algorithms w/ Dr. Yeager
//Due 2355 on 09 Dec 2013
//Description:
//Implements the Prim's Algorithm for finding the MST.

#pragma once

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include "GraphDataStructures.h"

#include <algorithm> //Maybe need?

//This algorithm EDITS the G's vertex property "traversed"
Graph_AdjacenyListBased PrimAlgorithm(Graph_AdjacenyListBased& G, int idOfStartVertex)
{
	Graph_AdjacenyListBased MST;
	int leastWeightFoundAtThisVertex;
	int leastWeightFoundDestinationID;
	int idOfVertexCurrentlyUnderExamination;
	queue<int> Q; //A queue of the ids in G that need to be breadth-scanned for the least weight edge.

	//Exceptional case: if the graph input is empty, return empty tree.
	if(G.getSizeInVerticies() < 1)
		return MST;
	//Exceptional case: if the graph input is empty, return empty tree.
	if(!G.hasVertex(idOfStartVertex))
		return MST;

	//Initialize a tree. done already.
	//Set the root of the tree to equal the trunk of ISP network
	MST.addVertex(idOfStartVertex);
	Q.push(idOfStartVertex); //Push the first vertex.

	//Start loop
	while(!Q.empty())
	{
		//Grab the next vertex.
		idOfVertexCurrentlyUnderExamination = Q.front();
		Q.pop();

		//Initialize some stuff
		leastWeightFoundAtThisVertex = MAX_INT;

		//Look at the adjacency list, cycle through looking for the unleast weight.
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
				if(edgeToTest->weight < leastWeightFoundAtThisVertex &&
					G.graph.at(edgeToTest->destination).visited == false)
				{
					leastWeightFoundAtThisVertex = edgeToTest->weight;
					leastWeightFoundDestinationID = edgeToTest->destination;
				}
			}
			edgeToTest++; //Iterate to the next edge
		}
		//Grow the tree by one edge from one of the vertices not in the tree yet.
		if(G.graph.at(leastWeightFoundDestinationID).visited = 0) 
		{
			Q.push(leastWeightFoundDestinationID); //Only add the vertex to the Q if it has not been visited.
			G.graph.at(leastWeightFoundDestinationID).visited = 1;
		}
		MST.addVertex(leastWeightFoundDestinationID); //Vertex copy ctor?
		MST.addEdge(idOfVertexCurrentlyUnderExamination, leastWeightFoundDestinationID, leastWeightFoundAtThisVertex); //Edge copy ctor instead?
		//NOTE: The edge must be the minimum-weight edge from that vertex. So in,
		//other words, find the greediest short sighted immediate solution.
		//Repeat until all vertices have been added into the tree.
	}
	//End Loop
	return MST;
}