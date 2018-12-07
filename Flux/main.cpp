#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Graph.h"

using namespace std;

void initializeFromStream(istream& stream, Graph* graph) {
	string line;

	while (getline(stream, line) && line != "")
	{
		stringstream lineStream(line);
		unsigned int id;
		unsigned int cost;
		Node* from;
		Node* to;

		lineStream >> id;

		if (graph->HasNode(id))
			from = graph->GetNode(id);
		else {
			from = new Node(id);
			graph->AddNode(from);
		}

		lineStream >> id;

		if (graph->HasNode(id))
			to = graph->GetNode(id);
		else {
			to = new Node(id);
			graph->AddNode(to);
		}

		lineStream >> cost;

		from->AddConnection(to, cost);
	}
}

Graph* fromFile() {
	string file_name;

	cout << "Enter the file name: ";
	getline(cin, file_name);

	ifstream file(file_name);

	if (!file.is_open()) {
		cerr << "The file '" << file_name << "' could not be opened, aborting...\n";
		exit(EXIT_FAILURE);
	}

	Graph* g = new Graph();

	initializeFromStream(file, g);

	file.close();

	return g;
}

Graph* iterative() {
	cout << "Enter the data as NODE1 NODE2 COST:\nNODE1 >-(COST)-> NODE2\nFinish the data with a blank line.\n\n";

	Graph* g = new Graph();

	initializeFromStream(cin, g);

	return g;
}

int main() {
	unsigned int choice;
	cout << "Graph build mode:\n\t1 - File\n\t2 - Iteractive\n\n> ";
	cin >> choice;
	cin.get();

	while (choice != 1 && choice != 2)
	{
		cout << "> ";
		cin >> choice;
	}

	Graph* graph = choice == 1 ? fromFile() : iterative();

	cout << "Enter the start and end nodes separated by a space: NODE1 NODE2\n";

	int id1, id2;

	cin >> id1 >> id2;
	cin.get();

	cout << "Total Cost: " << graph->FordFulkerson(graph->GetNode(id1), graph->GetNode(id2)) << endl << endl;

	for (auto node : graph->Nodes())
		for (auto edge : node->Edges())
			if (!edge->Reverse())
				cout << *edge << endl;

	delete graph;

	cin.get();
	return 0;
}