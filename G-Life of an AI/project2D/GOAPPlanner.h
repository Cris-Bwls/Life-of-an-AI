#pragma once
#include <vector>
#include <map>

#include "GOAPWorldState.h"

class Agent;
class GOAPActionBase;

class GOAPPlanner
{
public:
	GOAPPlanner();
	~GOAPPlanner();

	void PopulateEffectMap(std::vector<GOAPActionBase*> actionList);
	void ChangeWorldState(WorldStateProperty* pChange);

	std::vector<GOAPActionBase*> GetPathToGoal(std::vector<WorldStateProperty> goalState);

private:
	Agent* m_pAgent;
	WorldState m_WorldState;
	std::map<EGOAPSymbols, std::vector<GOAPActionBase*>> m_EffectMap;
};

