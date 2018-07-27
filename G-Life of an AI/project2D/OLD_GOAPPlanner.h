#pragma once
#include <vector>
#include <map>

#include "OLD_GOAPWorldState.h"

class Agent;
class GOAPActionBase;

class OLD_GOAPPlanner
{
public:
	OLD_GOAPPlanner();
	~OLD_GOAPPlanner();

	void PopulateEffectMap(std::vector<GOAPActionBase*> actionList);
	void ChangeWorldState(OLD_WorldStateProperty pChange);

	std::vector<GOAPActionBase*> MakePlan(std::vector<OLD_WorldStateProperty> goalState);

private:
	Agent* m_pAgent;
	OLD_WorldState m_WorldState;
	std::map<OLD_EGOAPSymbols, std::vector<GOAPActionBase*>> m_EffectMap;
};

