#pragma once
#include "Agent.h"
#include "EGOAPSymbols.h"

#include <vector>

class GOAPActionBase;
class GOAPPlanner;

class AI :
	public Agent
{
public:
	AI();
	~AI();

	void AddAction(GOAPActionBase* pAction);

private:
	SymbolMap m_worldState;
	GOAPPlanner* m_pPlanner;
	std::vector<GOAPActionBase*> m_ActionList;
};

