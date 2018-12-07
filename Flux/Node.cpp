#include "Node.h"

Node::Node(unsigned int id) : id(id)
{
}

Node::~Node()
{
	for (auto node : connections)
		delete node;
}

void Node::AddConnection(Node * other, int cost, bool reverse)
{
	connections.push_back(new Edge(this, other, cost, reverse));
}

unsigned int Node::operator[](Node * other)
{
	return ConnectionCost(other);
}

bool Node::HasConnection(Node * other)
{
	for (auto edge : connections)
		if (edge->End() == other)
			return true;

	return false;
}

int Node::ConnectionCost(Node * other)
{
	for (auto edge : connections)
		if (edge->End() == other)
			return edge->Cost();

	return 0;
}

Edge * Node::GetConnection(Node * other)
{
	for (auto edge : connections)
		if (edge->End() == other)
			return edge;

	return nullptr;
}

unsigned int Node::Id()
{
	return id;
}

vector<Edge*>& Node::Edges()
{
	return connections;
}
