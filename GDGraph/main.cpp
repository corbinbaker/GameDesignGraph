//Corbin Baker
//March 16,2017
//Game Design: Assignment 5 || Implementing a Game Map in a Graph


#include "driver.h"
#include <iostream>
#include <string>
using namespace std;




/*Implement a directional weighted graph. The graph should be designed to use a string to identify each node and a movement cost to characterize an edge connecting two nodes.
Create a test driver for your graph. This should be using just standard input and output (best to use console along with cin and cout).
Code must be tested to insure it functions under all circumstances. Identify a number of test cases that would exercise your graph,
identify the expected results for a test plan, then execute the test plan and insure all test cases function properly. Be sure to document each step of the testing.*/

int main(int argc, char *argv[])
{
	string input;

	while (true)
	{
		cout << "PLEASE ENTER ONE OF THE FOLLOWING COMMANDS :: " << endl;
		cout << "INIT / ADDV / ADDE / PRINT / TEST1 / TEST2 / PATH/ QUIT" << endl << endl;
		cin >> input;

		if (input == "INIT")
		{
			system("CLS");
			INIT();
		}

		else if (input == "ADDV")
		{
			system("CLS");
			ADDV();
		}

		else if (input == "ADDE")
		{
			system("CLS");
			ADDE();
		}

		else if (input == "PRINT")
		{
			system("CLS");
			PRINT();
		}

		else if (input == "TEST1")
		{
			system("CLS");
			TEST1();
		}

		else if (input == "TEST2")
		{
			system("CLS");
			TEST2();
		}

		else if (input == "PATH")
		{
			system("CLS");
			PATH();
		}

		else if (input == "QUIT")
		{
			system("CLS");
			QUIT();
		}

		else {
			cout << endl << "~~~~~~~ INVALID COMMAND ~~~~~~~" << endl << endl;
		}
			
	}

}