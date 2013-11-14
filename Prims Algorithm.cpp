#pragma once

#include <vector>
using std::vector;

#include <algorithm> //Maybe need?


void PrimAlgorithm()
{
	//Exceptional case: if the graph input is empty, return empty tree.

	//Initialize a tree. 
	//Set the root of the tree to equal the trunk of ISP network
	//Grow the tree by one edge from one of the vertices not in the tree yet. 
	//NOTE: The edge must be the minimum-weight edge from that vertex. So in,
	//other words, find the greediest short sighted immediate solution.
	//Repeat until all vertices have been added into the tree.
}