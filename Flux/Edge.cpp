#include "Edge.h"

Edge::Edge(Node * start, Node * end, int cost) : Edge(start, end, cost, false)
{
}

Edge::Edge(Node * start, Node * end, int cost, bool reverse)
	: start(start), end(end), cost(cost), original_cost(cost), reverse(reverse)
{
}

int Edge::Cost()
{
	return this->cost;
}

void Edge::Cost(int cost)
{
	this->cost = cost;
}

Node * Edge::Start()
{
	return start;
}

Node * Edge::End()
{
	return end;
}

bool Edge::Reverse()
{
	return this->reverse;
}

ostream & operator<<(ostream & stream, Edge & e)
{
	return stream
		<< e.start->Id()
		<< " -> "
		<< e.end->Id()
		<< ", "
		<< e.original_cost - e.cost
		<< " / "
		<< e.original_cost;
}
