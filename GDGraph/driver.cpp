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


	cout << endl << endl << "NEW VERTEX SUCCESSFULLY ADDED" << endl << endl;

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

		cout << endl << endl;
	}
}


//TEST1 – Initializes the graph.Then insert the vertices and edges defined for the example on slide 6 in lecture 24 (Game Map and Graphs).
void TEST1() {
	cout << "RUNNING TEST 1..." << endl << endl;

	//add vertexes
	addVertex("Dallas");
	addVertex("Austin");
	addVertex("Washington");
	addVertex("Denver");
	addVertex("Atlanta");
	addVertex("Chicago");
	addVertex("Houston");

	//add edges


	//Dallas Edges
	addEdge("Dallas", "Austin", 200);
	addEdge("Dallas", "Chicago", 900);
	addEdge("Dallas", "Denver", 780);

	//Austin Edges
	addEdge("Austin", "Houston", 160);
	addEdge("Austin", "Dallas", 200);

	//Washington Edges
	addEdge("Washington", "Atlanta", 600);
	addEdge("Washington", "Dallas", 1300);

	//Denver Edges
	addEdge("Denver", "Atlanta", 1400);
	addEdge("Denver", "Chicago", 1000);

	//Chicago Edges
	addEdge("Chicago", "Denver", 1000);

	//Houston Edges
	addEdge("Houston", "Atlanta", 800);

	//Atlanta Edges
	addEdge("Atlanta", "Washington", 600);
	addEdge("Atlanta", "Houston", 800);

	//13 TOTAL EDGES

	cout << "TEST 1 COMPLETE" << endl << endl;
}


//TEST2 (Bonus Points) - Initializes the graph. Then insert the vertices and edges defined for the example on slide 3 (Movealot) in lecture 24.
void TEST2() {

	cout << "TEST 2 HAS NOT BEEN IMPLEMENTED" << endl << endl;

}


//QUIT – Quit the test program.
void QUIT() {
	cout << "EXITTING APPLICATION..." << endl << endl;
	exit(0);
}


//PATH - Given two vertices, use Djikstra's algo to generate a path between the two and print the path
void PATH() {
	string output;
	string* oa = &output;
	int cost;
	vector<DNode> dVector;
	string vS;
	string vE;

	cout << "PRINTING PATH BETWEEN TWO VERTICES USING DJIKSTRA ALGORITHM :: " << endl << endl;

	cout << "PLEASE ENTER THE NAME OF THE STARTING VERTEX: ";
	cin >> vS;

	cout << endl << "PLEASE ENTER THE NAME OF THE END VERTEX : ";
	cin >> vE;


	cout << endl << endl << "EXECUTING DJIKSTRA ALGORITHM..." << endl;

	DNode dS;
	dS.name = vS;
	dS.visited = true;
	dVector.push_back(dS);

	cost = dijkstra(vS, vE, dVector, oa);

	if (cost < 0)
	{
		cout << endl << endl << "THE END VERTEX IS UNREACHABLE FROM THE GIVEN STARTING VERTEX" << endl << endl;;
	}
	else
	{
		cout << "DISTANCE: " << cost << endl;
		cout << "PATH TAKEN: " << output << endl << endl;
	}
}