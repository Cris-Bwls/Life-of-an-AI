#pragma once
#include "Agent.h"

#include <vector>

class GOAPActionBase;
class GOAPPlanner;
struct WorldStateProperty;

class AI :
	public Agent
{
public:
	AI();
	~AI();

	void AddAction(GOAPActionBase* pAction);

	void Plan(WorldStateProperty wsp);

	inline std::vector<GOAPActionBase*>*  GetPlan() { return &m_Plan; };
	inline GOAPPlanner* GetPlanner() { return m_pPlanner; }

private:
	GOAPPlanner* m_pPlanner;
	std::vector<GOAPActionBase*> m_Plan;
	std::vector<GOAPActionBase*> m_ActionList;
};

