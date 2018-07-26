#pragma once
#include "Agent.h"

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
	GOAPPlanner* m_pPlanner;
	std::vector<GOAPActionBase*> m_ActionList;
};

