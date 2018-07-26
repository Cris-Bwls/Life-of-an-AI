#pragma once

#include <map>
#include <vector>

using StateMap = std::map<std::string, bool>;

class GoapNode;
class GoapAction;

class GoapEdge
{
public:
	GoapEdge(GoapNode* from, GoapNode* to, GoapAction* action);
	~GoapEdge() = default;

	GoapEdge(const GoapEdge& other) = default;
	GoapEdge(GoapEdge&& other) noexcept = default;
	GoapEdge& operator=(const GoapEdge& other) = default;
	GoapEdge& operator=(GoapEdge&& other) noexcept = default;

	GoapNode* from;
	GoapNode* to;
	GoapAction* action;
};

class GoapNode
{
public:
	explicit GoapNode(StateMap const& worldState);
	~GoapNode();

	// default everything should be fine since all members are STL types
	// which should all have these implemented properly
	GoapNode(const GoapNode& other) = default;
	GoapNode(GoapNode&& other) = default;
	GoapNode& operator=(const GoapNode& other) = default;
	GoapNode& operator=(GoapNode&& other) noexcept = default;

	// edges pointing to this node from another node
	std::vector<GoapEdge*> edgesTo;
	// edges pointing from this node to another node
	std::vector<GoapEdge*> edgesFrom; // pointers owned by this class!!!

	// the "world state" of this node - the unique part of the graph
	// there should only be one node with a certain world state
	StateMap worldState;

	// stuff used for generating the graph
	std::vector<GoapAction*> actionsLeft;
	
	// A* stuff
	bool traversed;
	GoapNode* previous;
	GoapAction* prevAction;
	float fScore, gScore, hScore;
};

class GoapGraph
{
public:
	GoapGraph();
	~GoapGraph();

	GoapGraph(const GoapGraph& other) = default;
	GoapGraph(GoapGraph&& other) noexcept = default;
	GoapGraph& operator=(const GoapGraph& other) = default;
	GoapGraph& operator=(GoapGraph&& other) noexcept = default;

	void addNode(GoapNode* node);

	GoapNode* getNode(StateMap const& state);

	GoapNode* rootNode;
	std::vector<GoapNode*> nodes;
};