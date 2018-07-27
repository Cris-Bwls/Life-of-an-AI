#include "AI.h"

#include "GOAPActionBase.h"
#include "GOAPPlanner.h"
#include <queue>
#include <typeinfo>

// DEBUG
#include <iostream>
#include "GOAPActionGatherSticks.h"
#include "GOAPActionGatherStone.h"
#include "GOAPActionMakeTool.h"
#include "GOAPActionChopTree.h"
#include "GOAPActionMineRock.h"
#include "GOAPActionGetTool.h"
#include "GOAPActionGetWeapon.h"
#include "GOAPActionMakeWeapon.h"
#include "GOAPActionMakeFire.h"
#include "GOAPActionLightFire.h"

AI::AI()
{
	m_pPlanner = new GOAPPlanner;

	//init worldstate
	for (int i = 0; i < EGOAPSYMBOL_TOTAL; ++i)
	{
		m_worldState[(EGOAPSymbol)i] = false;
	}

	m_worldState[EGOAPSYMBOL_TREE_EXISTS] = true;
	m_worldState[EGOAPSYMBOL_ROCK_EXISTS] = true;

	m_ActionList.push_back(new GOAPActionGatherSticks);
	m_ActionList.push_back(new GOAPActionGatherStone);
	m_ActionList.push_back(new GOAPActionMakeTool);
	m_ActionList.push_back(new GOAPActionChopTree);
	m_ActionList.push_back(new GOAPActionMineRock);
	m_ActionList.push_back(new GOAPActionGetTool);
	m_ActionList.push_back(new GOAPActionGetWeapon);
	m_ActionList.push_back(new GOAPActionMakeWeapon);
	m_ActionList.push_back(new GOAPActionMakeFire);
	m_ActionList.push_back(new GOAPActionLightFire);
	m_ActionList.push_back(new GOAPActionGatherSticks);
	m_ActionList.push_back(new GOAPActionGatherSticks);
	m_ActionList.push_back(new GOAPActionGatherSticks);
	m_ActionList.push_back(new GOAPActionGatherSticks);

	// give action list to planner
	m_pPlanner->SetActionList(&m_ActionList);

	//DEBUG
	m_pPlanner->SetState(m_worldState);
	auto plan = m_pPlanner->MakePlan(EGOAPSYMBOL_HAVE_WEAPON, true);

	while (plan.size() > 0)
	{
		printf("%s\n", plan.front()->GetName());
		plan.pop();
	}
}


AI::~AI()
{
	delete m_pPlanner;

	while (m_ActionList.size() > 0)
	{
		delete m_ActionList.back();
		m_ActionList.pop_back();
	}
}

void AI::AddAction(GOAPActionBase* pAction)
{
	for (int i = 0; i < m_ActionList.size(); ++i)
	{
		if (typeid(*(m_ActionList[i])).hash_code() == typeid(*(pAction)).hash_code())
		{
			delete pAction;
			return;
		}
	}

	m_ActionList.push_back(pAction);
}
