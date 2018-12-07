#pragma once
#include <vector>
#include "Edge.h"

using namespace std;

class Edge;

class Node
{
	unsigned int id;
	vector<Edge*> connections;

public:
	Node(unsigned int id);
	~Node();

	void AddConnection(Node* other, int cost, bool reverse = false);
	bool HasConnection(Node* other);
	int ConnectionCost(Node* other);
	Edge* GetConnection(Node* other);
	unsigned int Id();
	vector<Edge*>& Edges();

	unsigned int operator[](Node* other);
};

