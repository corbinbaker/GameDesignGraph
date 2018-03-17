//Corbin Baker
//March 16,2017
//Game Design: Assignment 5 || Implementing a Game Map in a Graph


#include <vector>
#include <map>
using namespace std;


vector<string> vertices;
vector<vector<int>> edges;

/*Implement a directional weighted graph. The graph should be designed to use a string to identify each node and a movement cost to characterize an edge connecting two nodes.
Create a test driver for your graph. This should be using just standard input and output (best to use console along with cin and cout).
Code must be tested to insure it functions under all circumstances. Identify a number of test cases that would exercise your graph,
identify the expected results for a test plan, then execute the test plan and insure all test cases function properly. Be sure to document each step of the testing.*/
int main(int argc, char *argv[])
{
	vertices = vector<string>();
}


//void makeEmpty() – Initializes the graph to an empty state.
void makeEmpty() {
	vertices.clear();
	edges.clear();
}


//void addVertex(string vertexname) – Add a vertex to the graph.
void addVertex(string vertexname) {
	Vertex* v = new Vertex(vertexname);
	vertices.push_back(*v);
}


//bool addEdge(string fromVertex, string toVertex, int cost) - Adds an edge from fromVertex to toVertex with a weight of cost.  Returns false if either vertex not found.
bool addEdge(Vertex fromVertex, Vertex toVertex, int cost) {
	Vertex v1;
	Vertex v2;

	for (Vertex v : vertices) {
		if (v == fromVertex)
		{
			v1 = v;
		}

		if (v == toVertex)
		{
			v2 = v;
		}
	}

	if (v1.name.empty() || v2.name.empty())
	{
		return false;
	}

	else
	{
		//inserts cost values for both vertices
		v1.costs.insert(pair<Vertex, int>(v2, cost));
		v2.costs.insert(pair<Vertex, int>(v1, cost));
	}
}


//int getWeight( string fromVertex, string toVertex ) – Returns the cost to move from fromVertex to adjacent vertex toVertex. If the two vertices are not adjacent or not found, returns -1.
int getWeight(Vertex fromVertex, Vertex toVertex) {
	map<Vertex, int>::iterator it;

	for (it = fromVertex.costs.begin(); it != fromVertex.costs.end(); ++it)
	{
		if ((it)->first.name == fromVertex.name)
		{

		}

	}
}


//bool getAdjacent( string fromVertex, queue vertexQue) – given the vertex fromVertex, return a queue containing the adjacent vertices.  Returns false if vertex not found.
bool getAdjacent(Vertex fromVertex, queue<Vertex> vertexQue) {

} */

/*#include "driver.h"
#include "graph.h"

//INIT – Reset the graph
void INIT() {

}


//ADDV – Request a string, then add that string as a vertex.
void ADDV() {

}


//ADDE – Request the name of two vertices, then a weight between the vertices.Creates an edge based on this info.
void ADDE() {

}


//PRINT – Prints each vertex in the graph, along with all edges and weights associated with the vertex.
//The output might look like…
//Atlanta; Adjacent: Houston (800), Washington (600)
void PRINT() {

}


//TEST1 – Initializes the graph.Then insert the vertices and edges defined for the example on slide 6 in lecture 24 (Game Map and Graphs).
void TEST1() {

}


//TEST2 (Bonus Points) - Initializes the graph. Then insert the vertices and edges defined for the example on slide 3 (Movealot) in lecture 24.
void TEST2() {

}


//QUIT – Quit the test program.
void QUIT() {

}*/