//Andrew Claudy and JT Broad
//Draws partial inspiration from:
//http://www.daniweb.com/software-development/cpp/threads/340527/undirected-graph-implementation-using-adjacency-lists
//
//http://stackoverflow.com/questions/19889291/should-i-use-a-graph-library
//
//http://www.cplusplus.com/reference/map/map/find/
//
//http://stackoverflow.com/questions/19955150/applying-dijkstras-algorithm-on-a-graph-of-five-nodes

#pragma once

//Declarations
#include <limits>
using std::numeric_limits;
const int MAX_INT = numeric_limits<int>::max();

#include <ostream>
using std::ostream;
using std::endl;

#include <set>
using std::set;

#include <map>
using std::map;
using std::pair;

#include <vector>
using std::vector;

struct Edge;
struct Vertex;

//Definitions
struct Vertex
{
	Vertex(const int& id_)
	{
		id = id_;
		visited = 0;

	}
	Vertex(const Vertex& v_)
	{
		id = v_.id;
		visited = v_.visited;
		adjacent = v_.adjacent; //O(n) deep copy
								//+ object instantiation time
	}

	int id;
	int visited;			//Essentially a Color.
	vector<Edge> adjacent;	//Vertices adjacent
	int pi;
};

struct Edge //(hint: Undirected despite wording)
{
	Edge(const int& source_, 
		const int& destination_,
		const int& weight_)
	{
		source = source_;
		destination = destination_;
		weight = weight_;
		traversed = 0;
	}
	int source;
	int destination;
	int weight;
	int traversed;
};

class Graph_AdjacenyListBased
{
public:
	Vertex addVertex(const int& id_)
	{
		Vertex v(id_);
		graph.insert(pair<int, Vertex>(id_, v)); 
		return v;
	}

	void addEdge(const int& a, const int& b, const int& weight)
	{
		//These are used to decrease the # of calls to graph.find()
		Vertex* alpha;
		Vertex* bravo;

		//Assign alpha to the vertex a.
		if(graph.find(a) == graph.end())
		{	
			// No item 'a' existed in the map. Create it.
			alpha = &addVertex(a);
		}
		else
		{
			alpha = &graph.find(a)->second;
		}
		//Assign bravo to the vertex b.
		if(graph.find(b) == graph.end())
		{	
			// No item 'b' existed in the map. Create it.
			bravo = &addVertex(b);
		}
		else
		{
			bravo = &graph.find(b)->second;
		}

		//Now create the edge between the two verts.
		Edge e = Edge(alpha->id, bravo->id, weight);
		//And insert it into the adjacency lists of the verts.
		alpha->adjacent.push_back(e);
		bravo->adjacent.push_back(e);
	}

	bool hasVertex(int vertexID_) const
	{
		return graph.find(vertexID_) != graph.end();
	}

	int getSizeInVerticies() const
	{
		return graph.size();
	}

	int getSizeInEdges() const
	{
		return graph.size();
	}

	ostream& printVertexList(ostream& out) const
	{
		bool noneForThisVertex;

		for(auto iter = graph.begin(); iter != graph.end(); iter++)
		{
			noneForThisVertex = true;

			out << "Vertex " << iter->first << //iter->second.id is identical behavior to iter->first.
				" (visited=" << iter->second.visited << ")" << endl;
			for(auto iter2 = iter->second.adjacent.begin(); 
				iter2 != iter->second.adjacent.end(); iter2++)
			{
				if(iter2->destination != iter->first) 
				{
					// != so outbound arrow edge
					out << "  dest=" << iter2->destination <<
						" weight=" << iter2->weight <<
						" traversed=" << iter2->traversed << endl;
				}
				else 
				{
					// == so inbound arrow edge
					out << "  from=" << iter2->source <<
						" weight=" << iter2->weight <<
						" traversed=" << iter2->traversed << endl;
				}
				noneForThisVertex = false;
			}

			if(noneForThisVertex)
				out << "  No edges connected." << endl;
			out << endl;
		}
		out << endl;
		return out;
	}

	//Imagine removeVertex(int) and removeEdge(Edge). Note how imagining does not make the functions appear.
	friend Graph_AdjacenyListBased PrimAlgorithm(Graph_AdjacenyListBased& G, int idOfStartVertex);
private:
	map<int, Vertex> graph; //ID of vertex, Vertex instance.

};