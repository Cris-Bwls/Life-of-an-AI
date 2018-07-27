#pragma once
#include "EGOAPSymbols.h"
#include <vector>

class GOAPActionBase;
struct GOAPGraphNode;

struct GOAPGraphEdge
{
	GOAPGraphEdge(GOAPGraphNode* from, GOAPGraphNode* to, GOAPActionBase* action);
	~GOAPGraphEdge() = default;

	GOAPGraphEdge(const GOAPGraphEdge& other) = default;
	GOAPGraphEdge(GOAPGraphEdge&& other) noexcept = default;
	GOAPGraphEdge& operator=(const GOAPGraphEdge& other) = default;
	GOAPGraphEdge& operator=(GOAPGraphEdge&& other) noexcept = default;

	GOAPGraphNode* pNodeFrom;
	GOAPGraphNode* pNodeTo;
	GOAPActionBase* pAction;
};

struct GOAPGraphNode
{
	explicit GOAPGraphNode(SymbolMap const& worldState);
	~GOAPGraphNode();

	GOAPGraphNode(const GOAPGraphNode& other) = default;
	GOAPGraphNode(GOAPGraphNode&& other) = default;
	GOAPGraphNode& operator=(const GOAPGraphNode& other) = default;
	GOAPGraphNode& operator=(GOAPGraphNode&& other) noexcept = default;

	// edges pointing to this node from another node
	std::vector<GOAPGraphEdge*> edgesTo;
	// edges pointing from this node to another node
	std::vector<GOAPGraphEdge*> edgesFrom; 

	SymbolMap worldState;

	// stuff used for generating the graph
	std::vector<GOAPActionBase*> actionsLeft;

	// A* stuff
	bool traversed;
	GOAPGraphNode* previous;
	GOAPActionBase* prevAction;
	float fScore, gScore, hScore;
};

struct GOAPGraph
{
	GOAPGraph();
	~GOAPGraph();

	GOAPGraph(const GOAPGraph& other) = default;
	GOAPGraph(GOAPGraph&& other) noexcept = default;
	GOAPGraph& operator=(const GOAPGraph& other) = default;
	GOAPGraph& operator=(GOAPGraph&& other) noexcept = default;

	void addNode(GOAPGraphNode* node);

	GOAPGraphNode* getNode(SymbolMap const& state);

	GOAPGraphNode* rootNode;
	std::vector<GOAPGraphNode*> nodes;
};

