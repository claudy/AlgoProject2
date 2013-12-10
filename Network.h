#pragma once

#include "GraphDataStructures.h"

#include <vector>
using std::vector;

const int DISTANCE_BETWEEN_AMPS = 2000;

class Network
{
public:
	Network(float cableCostPer100m_, 
		float costOfAmplifier_, 
		float costOfASingleNode_,
		int parentNode = 1)
	{
		//ARGS HANDLING
		cableCostPer100m = cableCostPer100m_;
		costOfAmplifier = costOfAmplifier_;
		costOfASingleNode = costOfASingleNode_;

		//INSTRUCTIONS TO USER:
		//INPUT network layout graph HERE. Must be fully connected.
		//E.g., if you addEdge from 1 to 2, you must addEdge 2 to 1.
		//because Graph_DataStructure is a directed graph.
		/*
		fibernet.addEdge(1, 2, 20000);
		fibernet.addEdge(1, 4, 10000);
		fibernet.addEdge(2, 4, 20000);
		fibernet.addEdge(3, 4, 30000);
		*/
		//^Wikipedia example^//

		fibernet.addEdge(1, 2, 1000);
		fibernet.addEdge(1, 3, 4000);
		fibernet.addEdge(2, 3, 3000);
		fibernet.addEdge(1, 5, 10000);
		fibernet.addEdge(2, 4, 7500);
		fibernet.addEdge(4, 7, 5000);
		fibernet.addEdge(3, 4, 6500);
		fibernet.addEdge(3, 6, 7000);
		fibernet.addEdge(5, 6, 4500);
		fibernet.addEdge(3, 5, 3000);
		fibernet.addEdge(6, 7, 8000);
		fibernet.addEdge(4, 6, 6000);

		//Once all the edges have been added, call PrimAlgorithm.
 		PrimAlgorithm(fibernet, parentNode); //CHANGE THIS TO 

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
		return out;
	}
	ostream& printCostEstimate(ostream& out);
private:
	float cableCostPer100m;
	float costOfAmplifier; 
	float costOfASingleNode;

	int numNodes;
	int numAmplifiers;			//Occurs every 2 km
	int metersOfCableRoundedUp; //Each edge is rounded up to the nearest 100m.
	int distanceSum;

	Graph_AdjacenyListBased fibernet; //Weight is in meters.
};