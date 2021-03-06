#include "graph.h"
#include <vector>
#include <string>
#include <iostream>

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


//int getWeight( string fromVertex, string toVertex ) � Returns the cost to move from fromVertex to adjacent vertex toVertex. If the two vertices are not adjacent or not found, returns -1.
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


//bool getAdjacent( string fromVertex, queue vertexQue) � given the vertex fromVertex, return a queue containing the adjacent vertices.  Returns false if vertex not found.
vector<string> getAdjacent(string fromVertex) {
	int fV = -1;
	vector<string> vAdj;
	for (unsigned int i = 0; i < vertices.size(); i++) //obtain index of vertices
	{
		if (vertices[i] == fromVertex) {
			fV = i;
		}
	}

	if(fV != -1)
	{
		
		vector<int> v = edges[fV];
		for (unsigned int i = 0; i < vertices.size(); i++)
		{
			
			if (v[i] >= 0)
			{
				vAdj.push_back(vertices[i]);
			}
		}

		return vAdj;
	}

	
	return vAdj;	
}


//GETTERS
vector<string> getVertices()
{
	return vertices;
}

vector<vector<int>> getEdges()
{
	return edges;
}









//traceback for djikstra algorithm
void path(string startVertex, string endVertex, vector<DNode> vertexQue, string* o)
{
	string output;
	string current = endVertex;
	vector<string> p;
	p.push_back(endVertex);

	while (current != startVertex); //loop until start Vertex = current
	{

		//find current in vertexQue
		for (DNode d : vertexQue)
		{
			if (d.name == current)
			{
				//find its prev
				current = d.from;
				p.push_back(current);
			}
		}
	} 


	//reverse
	reverse(p.begin(), p.end());

	//string converstion and spacing
	for (string s : p)
	{
		output += s;
		output += " ";
	}

	*o = output;
}


//Djikstra algorithm used to determine the most efficient path from one node to another,
//returning the distance between the two vertices or < 0 if none found
int dijkstra(string startVertex, string endVertex, vector<DNode> vertexQue, string* o) {
	int cost = 0;
	//check if at end point
	if (startVertex == endVertex)
	{
		//print path and return cost
		path(startVertex, endVertex, vertexQue, o);
		return cost;
	}

	//generate DNodes and vertexQue
	vector<string> adjVertices;

	adjVertices = getAdjacent(startVertex);
	
	for (string s : adjVertices)
	{
			
		//check for duplicates
		bool pres = false;
		for (DNode d : vertexQue)
		{
				
			if (d.name == s)
			{
				pres = true; //duplicate found
				if (!d.visited)
				{
					//if more efficient path found, use this path
					int cTemp = getWeight(startVertex, d.name);
					if (d.cost > cTemp)
					{
						d.cost = cTemp;
						d.from = startVertex;
					}
				}
			}
		}


		//new node found
		if (!pres)
		{	
			DNode d;
			d.name = s;
			d.from = startVertex;
			d.visited = false;
			d.cost = getWeight(startVertex, d.name);
			vertexQue.push_back(d);
		}
	}
	



	//find cheapest element in queue and send that for the next djikstra iteration
	int cheapestCost = INT_MAX;
	int next = -1;

	for (unsigned int i = 0; i < vertexQue.size(); i++)
	{
		if (!vertexQue[i].visited)
		{
			if (vertexQue[i].cost < cheapestCost)
			{
				next = i;
				cheapestCost = vertexQue[i].cost;
			}
		}
	}
	
	
	//check if endpoint is reachable

	if (next == -1) //can't reach endpoint
	{
		//this number should be large enough to overpower any positive values from previous instances in the recursion
		return -1000;
	}

	else
	{
		//recursive step
		vertexQue[next].visited = true;
		cost += cheapestCost;
		cost += dijkstra(vertexQue[next].name, endVertex, vertexQue, o);
	}

	cout << cost << endl;

	return cost;
}




