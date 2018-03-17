#pragma once
#include <queue>
#include <vector>
using namespace std;


//vector<string> vertices; 
//vector<vector<int>> edges; //ADJ MATRIX

//void makeEmpty() – Initializes the graph to an empty state.
void makeEmpty();


//void addVertex(string vertexname) – Add a vertex to the graph.
void addVertex(string vertexname);


//bool addEdge(string fromVertex, string toVertex, int cost) - Adds an edge from fromVertex to toVertex with a weight of cost.  Returns false if either vertex not found.
bool addEdge(string fromVertex, string toVertex, int cost);


//int getWeight( string fromVertex, string toVertex ) – Returns the cost to move from fromVertex to adjacent vertex toVertex. If the two vertices are not adjacent or not found, returns -1.
int getWeight(string fromVertex, string toVertex);


//bool getAdjacent( string fromVertex, queue vertexQue) – given the vertex fromVertex, return a queue containing the adjacent vertices.  Returns false if vertex not found.
bool getAdjacent(string fromVertex, queue<string> vertexQue);

//getters
vector<string> getVertices();
vector<vector<int>> getEdges();


