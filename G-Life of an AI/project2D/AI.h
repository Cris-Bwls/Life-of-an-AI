#pragma once
#include "Agent.h"

#include <vector>

class GOAPActionBase;

class AI :
	public Agent
{
public:
	AI();
	~AI();

	void AddAction(GOAPActionBase* pAction);

private:
	std::vector<GOAPActionBase*> m_ActionList;
};

