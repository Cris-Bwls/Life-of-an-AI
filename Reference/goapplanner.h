#pragma once

#include <map>
#include <queue.h>
#include <darray.h>
#include <hashtable.h>

typedef std::map<std::string, bool> NiceMap;

class GoapAction;

struct GoapNode
{
	GoapAction* action;
	std::map<std::string, bool> resultState;
	DArray<GoapAction*> otherActions;
	GoapNode* prev;
	bool reached;
	float cost;
};

class GoapPlanner
{
public:
	GoapPlanner() = default;
	~GoapPlanner() = default;

	Queue<GoapAction*> makePlan(DArray<GoapAction*> availableActions, 
		NiceMap worldState, const char* goalKey, bool goalVal);

	bool canDoAction(GoapAction* action, NiceMap worldState);

	void applyState(NiceMap* applyTo, NiceMap* toApply);

	DArray<GoapNode*> processAction(GoapNode* onode, std::string goalKey, bool goalVal);
private:

	DArray<GoapAction*> getAvailableActions(DArray<GoapAction*> actions, NiceMap world);
};