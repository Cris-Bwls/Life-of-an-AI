#pragma once

#include <queue>

#include "goapgraph.h"

class GoapAction;

class GoapPlanner
{
public:
	~GoapPlanner();

	std::queue<GoapAction*> makePlan(std::string const& goalKey,
		bool goalVal) const;

	void addAction(GoapAction* action);
	std::vector<GoapAction*>& getActions() { return m_actions; }

	void setState(StateMap const& newState);

private:
	StateMap m_worldState;
	std::vector<GoapAction*> m_actions;

	bool canDoAction(GoapAction* action, StateMap& state) const;

	GoapGraph makeGraph() const;

	void printPlanFromNode(GoapNode* node) const;
};
