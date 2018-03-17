#include "graph.h"
#include <vector>

//GRAPH - strings for the vertices and ints for the weights
vector<string> vertices = vector<string>();
vector<vector<int>> edges = vector<vector<int>>();

//initializes the graph to an empty state.
void makeEmpty() {
	vertices.clear();
	edges.clear();
}


//add vertex
void addVertex(string vertexname) {
	vertices.push_back(vertexname);
	

	vector<int> v = vector<int>(); //add new row for new vertex

	if (edges.empty())
	{
	}
	else
	{
		for (unsigned int i = 0; i < edges.size(); i++) //initialize edge values with -1
		{
			edges[i].push_back(-1);
		}
	}

	for (unsigned int i = 0; i < vertices.size(); i++) //initialize edge values with -1
	{
		v.push_back(-1);
	}

	

	edges.push_back(v); //add appropriate column/row for new vertex in the adj matrix
}


//bool addEdge(string fromVertex, string toVertex, int cost) - Adds an edge from fromVertex to toVertex with a weight of cost.  Returns false if either vertex not found.
bool addEdge(string fromVertex, string toVertex, int cost) {
	
	int fV, tV = -1;

	for (unsigned int i = 0; i < vertices.size(); i++) //obtain index of vertices
	{
		if (vertices[i] == fromVertex) {
			fV = i;
		}

		else if (vertices[i] == toVertex) {
			tV = i;
		}
	}


	if (fV == -1 || tV == -1)
	{
		return false;
	}

	else
	{
		edges[fV][tV] = cost;
		return true;
	}
}


//int getWeight( string fromVertex, string toVertex ) – Returns the cost to move from fromVertex to adjacent vertex toVertex. If the two vertices are not adjacent or not found, returns -1.
int getWeight(string fromVertex, string toVertex) {

	int fV, tV = -1;

	for (unsigned int i = 0; i < vertices.size(); i++) //obtain index of vertices
	{
		if (vertices[i] == fromVertex) {
			fV = i;
		}

		else if (vertices[i] == toVertex) {
			tV = i;
		}
	}


	if (fV == -1 || tV == -1)
	{
		return -1;
	}

	else
	{
		return edges[fV][tV];
	}
}


//bool getAdjacent( string fromVertex, queue vertexQue) – given the vertex fromVertex, return a queue containing the adjacent vertices.  Returns false if vertex not found.
bool getAdjacent(string fromVertex, queue<string> vertexQue) {
	int fV = -1;

	for (unsigned int i = 0; i < vertices.size(); i++) //obtain index of vertices
	{
		if (vertices[i] == fromVertex) {
			fV = i;
		}
	}

	if (fV == -1)
	{
		return false;
	}
	else
	{
		vector<int> v = edges[fV];

		for (int i : v)
		{
			vertexQue.emplace(vertices[i]);
		}

		return true;
	}
}


vector<string> getVertices()
{
	return vertices;
}

vector<vector<int>> getEdges()
{
	return edges;
}