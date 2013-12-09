#pragma once

#include "GraphDataStructures.h"

#include <vector>
using std::vector;

const int DISTANCE_BETWEEN_AMPS = 2000;

class Network
{
public:
	Network(float cableCostPer100m, 
		float costOfAmplifier, 
		float costOfASingleNode)
	{
		//ARGS HANDLING

		//Input network layout graph here. Must be fully connected.
		//E.g., if you addEdge from 1 to 2, you must addEdge 2 to 1.
		//because Graph_DataStructure is a directed graph.
		fibernet.addEdge(1, 2, 20005);
		//fibernet.addEdge(2, 1, 20000);
		fibernet.addEdge(1, 4, 10000);
		//fibernet.addEdge(4, 1, 10000);
		fibernet.addEdge(2, 4, 20000);
		//fibernet.addEdge(4, 2, 20000);
		fibernet.addEdge(3, 4, 30000);
		//fibernet.addEdge(4, 3, 30000);
		//^Wikipedia example^//

		//Once all the edges have been added, call PrimAlgorithm.
 		PrimAlgorithm(fibernet, 1);

	}
	~Network(){}

	float getCableCost() const { return cableCostPer100m; }
	float getAmpCost() const { return costOfAmplifier; }
	float getCostOfANodeEquipment() const { return costOfASingleNode; }
	
	float setCableCost(float cost) { cableCostPer100m = cost; }
	float setAmpCost(float cost) { costOfAmplifier = cost; }
	float setCostOfANodeEquipment(float cost) { costOfASingleNode = cost; }

	ostream& printVertexList(ostream& out) const
	{
		fibernet.printVertexList(out);
		out << endl;
		//Todo: Figure out the costs. 
		return out;
	}

private:
	float cableCostPer100m;
	float costOfAmplifier; 
	float costOfASingleNode;

	int numNodes;
	int numAmplifiers;			//Occurs every 2 km
	int metersOfCableRoundedUp; //Each edge is rounded up to the nearest 100m.
	Graph_AdjacenyListBased fibernet; //Weight is in meters.
};