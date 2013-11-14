//Andrew Claudy and JT Broad
//Draws partial inspiration from:
//http://www.daniweb.com/software-development/cpp/threads/340527/undirected-graph-implementation-using-adjacency-lists
//
//http://stackoverflow.com/questions/19889291/should-i-use-a-graph-library
//
//http://www.cplusplus.com/reference/map/map/find/


#pragma once

//Declarations
#include <set>
using std::set;

#include <map>
using std::map;
using std::pair;

#include <vector>
using std::vector;

struct Edge;
struct vertex;

//Definitions
struct vertex
{
	vertex(const int& id_, vertex* parent_)
	{
		id = id_;
		visited = 0;
		parent = parent_;
	}

	int id;
	int visited;			//Essentially a Color.
	vertex* parent;			//Pointer to parent vertex.
	vector<Edge> adjacent;	//Vertices adjacent

};

struct Edge //(hint: Undirected)
{
	Edge(vertex* source, 
		vertex* destination,
		const int& weight_)
	{
		one = source;
		two = destination;
		weight = weight_;
		visited = 0;
	}
	const vertex* one;
	const vertex* two;
	int weight;
	int visited;
};

class Graph_AdjacenyListBased
{
public:
	vertex addVertex(const int& a)
	{
		vertex v(a, nullptr);
		graph.insert(pair<int, vertex>(a, v)); 
		return v;
	}

	void addEdge(const int& a, const int& b, const int& weight)
	{
		//These are used to decrease the # of calls to graph.find()
		vertex* alpha;
		vertex* bravo;

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
		Edge e = Edge(alpha, bravo, weight);
		//And insert it into the adjacency lists of the verts.
		alpha->adjacent.push_back(e);
		bravo->adjacent.push_back(e);
	}

	int getSize() const
	{
		return graph.size();
	}

	//Imagine removeVertex(int) and removeEdge(Edge). Note how imagining does not make the functions appear.

private:
	map<int, vertex> graph; //ID of vertex, Vertex instance.

};