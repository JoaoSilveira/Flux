#pragma once

#include <vector>
#include <queue>
#include "Node.h"

using namespace std;

class Node;

class Graph
{
	vector<Node*> nodes;

public:
	Graph();
	~Graph();

	bool HasNode(unsigned int id);
	Node* GetNode(unsigned int id);
	void AddNode(Node* node);
	vector<Node*>& Nodes();
	vector<Edge*> Path(Node* start, Node* end);
	int FordFulkerson(Node* start, Node* end);



	Node* operator[](unsigned int id);
};

