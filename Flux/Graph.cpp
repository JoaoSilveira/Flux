#include "Graph.h"
#include <map>


Graph::Graph()
{
}


Graph::~Graph()
{
	for (auto node : nodes)
		delete node;
}

bool Graph::HasNode(unsigned int id)
{
	for (auto node : nodes)
		if (node->Id() == id)
			return true;

	return false;
}

Node * Graph::GetNode(unsigned int id)
{
	for (auto node : nodes)
		if (node->Id() == id)
			return node;

	return nullptr;
}

void Graph::AddNode(Node * node)
{
	nodes.push_back(node);
}

vector<Node*>& Graph::Nodes()
{
	return nodes;
}

vector<Edge*> Graph::Path(Node * start, Node * end)
{
	map<Node*, Node*> parents;
	vector<Node*> nodes;

	nodes.push_back(start);
	parents[start] = nullptr;


	while (!nodes.empty())
	{
		auto node = nodes.front();
		nodes.erase(nodes.begin());

		for (auto edge : node->Edges()) {
			if (edge->Cost() > 0 && parents.count(edge->End()) == 0) {
				nodes.push_back(edge->End());
				parents[edge->End()] = node;
			}
		}
	}

	if (parents.count(end) == 0)
		return vector<Edge*>();

	auto aux = end;

	while (aux != nullptr)
		nodes.push_back(aux), aux = parents[aux];

	reverse(nodes.begin(), nodes.end());
	vector<Edge*> edges;

	aux = nodes.front();
	nodes.erase(nodes.begin());

	while (!nodes.empty())
	{
		edges.push_back(aux->GetConnection(nodes.front()));
		aux = nodes.front();
		nodes.erase(nodes.begin());
	}

	return edges;
}

int Graph::FordFulkerson(Node * start, Node * end)
{
	int maxFlow = 0;

	while (true)
	{
		auto path = Path(start, end);

		if (path.empty())
			break;

		int flow = INT_MAX;

		for (auto node : path) {
			flow = min(flow, node->Cost());
		}

		for (auto edge : path) {
			edge->Cost(edge->Cost() - flow);

			if (edge->End()->HasConnection(edge->Start())) {
				auto reverseEdge = edge->End()->GetConnection(edge->Start());

				reverseEdge->Cost(reverseEdge->Cost() + flow);
			}
			else {
				edge->End()->AddConnection(edge->Start(), flow, true);
			}
		}

		maxFlow += flow;
	}

	return maxFlow;
}

Node * Graph::operator[](unsigned int id)
{
	return GetNode(id);
}
