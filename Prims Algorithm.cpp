#pragma once

#include <vector>
using std::vector;

#include <queue>
using std::queue;

#include "GraphDataStructures.h"

#include <algorithm> //Maybe need?


Graph_AdjacenyListBased PrimAlgorithm(Graph_AdjacenyListBased G, int idOfStartVertex)
{
	Graph_AdjacenyListBased MST;
	int leastWeightFoundAtThisVertex;
	int leastWeightFoundDestinationID;
	queue<int> Q; // A queue of the ids in G that need to be breadth-scanned for the least weight edge.

	//Exceptional case: if the graph input is empty, return empty tree.
	if(G.getSizeInVerticies() < 1)
		return MST;
	//Exceptional case: if the graph input is empty, return empty tree.
	if(!G.hasVertex(idOfStartVertex))
		return MST;

	//Initialize a tree. done already.
	//Set the root of the tree to equal the trunk of ISP network
	MST.addVertex(idOfStartVertex);
	Q.push(idOfStartVertex);

	//TODO: Start loop
	{
		int idOfVertexCurrentlyUnderExamination = Q.front();
		Q.pop();
		//Look at the vertices
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
		MST.addVertex(leastWeightFoundDestinationID); //Vertex copy ctor?
		MST.addEdge(idOfVertexCurrentlyUnderExamination, leastWeightFoundDestinationID, leastWeightFoundAtThisVertex); //Edge copy ctor instead?
		//NOTE: The edge must be the minimum-weight edge from that vertex. So in,
		//other words, find the greediest short sighted immediate solution.
		//Repeat until all vertices have been added into the tree.
	}
	return MST;
}