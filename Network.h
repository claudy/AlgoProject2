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
		float costOfASingleNode){}
	~Network(){}

	float getCableCost() const { return cableCostPer100m; }
	float getAmpCost() const { return costOfAmplifier; }
	float getCostOfANodeEquipment() const { return costOfASingleNode; }
	
	float setCableCost(float cost) { cableCostPer100m = cost; }
	float setAmpCost(float cost) { costOfAmplifier = cost; }
	float setCostOfANodeEquipment(float cost) { costOfASingleNode = cost; }

private:
	float cableCostPer100m;
	float costOfAmplifier; 
	float costOfASingleNode;

	int numNodes;
	int numAmplifiers;			//Occurs every 2 km
	int metersOfCableRoundedUp; //Each edge is rounded up to the nearest 100m.
};