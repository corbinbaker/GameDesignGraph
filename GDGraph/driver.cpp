#include "graph.h"
#include <iostream>
#include <string>
using namespace std;


//vector<string> vertices;
//vector<vector<int>> edges; //ADJ MATRIX

//INIT – Reset the graph
void INIT() {
	cout << "RESETTING GRAPH..." << endl << endl;
	makeEmpty();
	cout << "GRAPH SUCCESSFULLY RESET" << endl << endl;
}


//ADDV – Request a string, then add that string as a vertex.
void ADDV() {
	string v;

	cout << "ADDING A NEW VERTEX :: " << endl << endl;

	cout << "PLEASE ENTER THE NAME OF THE NEW VERTEX: ";
	cin >> v;

	addVertex(v);


	cout << endl << endl << "NEW EDGE SUCCESSFULLY ADDED" << endl << endl;

}


//ADDE – Request the name of two vertices, then a weight between the vertices.Creates an edge based on this info.
void ADDE() {

	string v1;
	string v2;
	int cost;

	cout << "ADDING A NEW EDGE :: " << endl << endl;

	cout << "PLEASE ENTER THE NAME OF THE FIRST VERTEX: "; 
	cin >> v1; 

	cout << endl << "PLEASE ENTER THE NAME OF THE SECOND VERTEX : ";
	cin >> v2;

	cout << endl << "PLEASE ENTER THE COST OF THIS EDGE: ";
	cin >> cost;


	if (addEdge(v1, v2, cost)) {
		cout << endl << endl << "NEW EDGE SUCCESSFULLY ADDED" << endl << endl;
	}
	else
	{
		cout << endl << endl << "ERROR: PLEASE CHECK THE NAMES OF THE VERTICES" << endl << endl;
	}
}


//PRINT – Prints each vertex in the graph, along with all edges and weights associated with the vertex.
//The output might look like…
//Atlanta; Adjacent: Houston (800), Washington (600)
void PRINT() {
	cout << "PRINTING ALL VERTICES AND EDGES :: " << endl << endl;
	
	vector<string> v = getVertices();
	vector<vector<int>> e = getEdges();

	for (unsigned int i = 0; i < v.size(); i++)
	{
		cout << v[i] << ": " << endl;
		
		for (unsigned int j = 0; j < v.size(); j++)
		{
			if (e[i][j] > -1) {
				cout << "\t" << v[j] << " [" << e[i][j] << "]" << endl;
			}
		}
	}
}


//TEST1 – Initializes the graph.Then insert the vertices and edges defined for the example on slide 6 in lecture 24 (Game Map and Graphs).
void TEST1() {

	//add vertexes
	addVertex("Dallas");
	addVertex("Austin");
	addVertex("Washington");
	addVertex("Denver");
	addVertex("Atlanta");
	addVertex("Chicago");
	addVertex("Houston");

	//add edges
	

}


//TEST2 (Bonus Points) - Initializes the graph. Then insert the vertices and edges defined for the example on slide 3 (Movealot) in lecture 24.
void TEST2() {

	//add vertexes
	//add edges

}


//QUIT – Quit the test program.
void QUIT() {
	cout << "EXITTING APPLICATION..." << endl << endl;
	exit(0);
}