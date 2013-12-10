#include "Network.h"

#include <cmath>
using std::ceil;
using std::floor;

ostream& Network::printCostEstimate(ostream& out)
{
	numNodes = 0;
	numAmplifiers = 0;
	metersOfCableRoundedUp = 0;

	int keySum = 0;
	float costOfNodes = 0;
	float costOfAmps = 0;
	float costOfCabling = 0;

	for(auto iter = fibernet.graph.begin(); iter != fibernet.graph.end(); iter++)
	{
		 keySum += iter->second.key;

		 metersOfCableRoundedUp = static_cast<int>(std::ceil((float)iter->second.key / 100.0) * 100); //# of spools needed

		 if(iter->second.key > 2000) // Prevents the zero case.
		 {
			int numAmpsOnThisEdge = static_cast<int>(std::floor((float)iter->second.key / 2000.0)); //Occurs every 2 km
			if(iter->second.key % 2000 == 0)
				numAmpsOnThisEdge--;
			numAmplifiers += numAmpsOnThisEdge;
		 }

		 numNodes++;
	}
	distanceSum = keySum;

	//Non-iterative calculations
	costOfNodes = costOfASingleNode * numNodes;
	costOfAmps = costOfAmplifier * numAmplifiers;
	costOfCabling = distanceSum * cableCostPer100m / 100.0f;
	out << "Total distance=" << distanceSum << endl;
	out.setf(out.fixed);
	out.precision(2);
	out << "Cost of cable per meter=$" << (cableCostPer100m / 100.0) << endl;
	out << "Number of Nodes=" << numNodes << endl;
	out << "Cost of Nodes=$" << costOfNodes << "  (Cost of one node=$" << costOfASingleNode << ")" << endl;
	out << "Number of Amplifiers=" << numAmplifiers << endl;
	out << "Cost of Amplifiers=$" << costOfAmps << "  (Cost of one amplifier=$" << costOfAmplifier << ")" << endl;
	out << "TOTAL NETWORK COST=$" << costOfNodes + costOfAmplifier + costOfCabling << endl;

	return out;
}