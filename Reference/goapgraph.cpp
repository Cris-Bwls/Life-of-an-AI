#include "goapgraph.h"

GoapEdge::GoapEdge(GoapNode* from, GoapNode* to, GoapAction* action)
	: from(from), to(to), action(action)
{
	from->edgesFrom.push_back(this);
	to->edgesTo.push_back(this);
}

GoapNode::GoapNode(StateMap const& worldState)
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

GoapNode::~GoapNode()
{
	for (auto edge : edgesFrom)
		delete edge;
}

GoapGraph::GoapGraph()
{
	rootNode = nullptr;
}

GoapGraph::~GoapGraph()
{
	for (auto node : nodes)
		delete node;
}

void GoapGraph::addNode(GoapNode* node)
{
	if (!rootNode)
		rootNode = node;

	nodes.push_back(node);
}

GoapNode* GoapGraph::getNode(StateMap const& state)
{
	for (GoapNode* node : nodes)
	{
		if (std::equal(state.begin(), state.end(),
			node->worldState.begin()))
			return node;
	}

	GoapNode* newNode = new GoapNode(state);
	//printf(" => Making new node...\n");
	addNode(newNode);
	return newNode;
}
