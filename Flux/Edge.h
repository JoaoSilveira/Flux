#pragma once
#include "Node.h"
#include <ostream>

class Node;

using namespace std;

class Edge
{
	Node* start;
	Node* end;
	int cost;
	int original_cost;
	bool reverse;

public:
	Edge(Node* start, Node* end, int cost);
	Edge(Node* start, Node* end, int cost, bool reverse);

	int Cost();
	void Cost(int cost);
	Node* Start();
	Node* End();
	bool Reverse();

	friend ostream& operator<<(ostream& stream, Edge& e);
};

