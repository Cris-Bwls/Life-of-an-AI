#include "GOAPGraph.h"
#include "GOAPActionBase.h"

// EDGE
GOAPGraphEdge::GOAPGraphEdge(GOAPGraphNode* from, GOAPGraphNode* to, GOAPActionBase* action)
	: pNodeFrom(from), pNodeTo(to), pAction(action)
{
	pNodeFrom->edgesFrom.push_back(this);
	pNodeTo->edgesTo.push_back(this);
}

// END-EDGE

// NODE
GOAPGraphNode::GOAPGraphNode(SymbolMap const& worldState)
	: worldState(worldState)
{
	traversed = false;
	previous = nullptr;
	prevAction = nullptr;

	// A* scores
	fScore = INFINITY;
	gScore = INFINITY;
	hScore = INFINITY;
}

GOAPGraphNode::~GOAPGraphNode()
{
	for (auto edge : edgesFrom)
		delete edge;
}
// END-NODE

// GRAPH
GOAPGraph::GOAPGraph()
{
	rootNode = nullptr;
}

GOAPGraph::~GOAPGraph()
{
	for (auto node : nodes)
		delete node;
}

void GOAPGraph::addNode(GOAPGraphNode* node)
{
	if (!rootNode)
		rootNode = node;

	nodes.push_back(node);
}

GOAPGraphNode* GOAPGraph::getNode(SymbolMap const& state)
{
	for (GOAPGraphNode* node : nodes)
	{
		if (std::equal(state.begin(), state.end(),
			node->worldState.begin()))
			return node;
	}

	GOAPGraphNode* newNode = new GOAPGraphNode(state);
	//printf(" => Making new node...\n");
	addNode(newNode);
	return newNode;
}

// END-GRAPH