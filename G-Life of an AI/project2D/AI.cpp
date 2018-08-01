#include "AI.h"

#include "GOAPActionBase.h"
#include "GOAPPlanner.h"
#include <typeinfo>

// DEBUG
#include <iostream>
#include "GOAPActionGatherSticks.h"
#include "GOAPActionGatherStone.h"
#include "GOAPActionMakeStoneTool.h"
#include "GOAPActionChopTree.h"
#include "GOAPActionMineRock.h"
#include "GOAPActionMakeFire.h"
#include "GOAPActionLightFire.h"
#include "GOAPActionCook.h"
#include "GOAPActionEatFood.h"
#include "GOAPActionGatherBerries.h"
#include "GOAPActionHunt.h"
#include "GOAPActionGetIronTool.h"
#include "GOAPActionGetStoneTool.h"
#include "GOAPActionPlaceCrafter.h"
#include "GOAPActionPlaceForge.h"
#include "GOAPActionMakeIronTool.h"

#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

AI::AI()
{
	m_pPlanner = new GOAPPlanner;

	// DEBUG
	AddAction(new GOAPActionGatherSticks(this, m_pTerrain));
	AddAction(new GOAPActionMakeStoneTool(this, m_pTerrain));
	AddAction(new GOAPActionChopTree(this, m_pTerrain));
	AddAction(new GOAPActionMineRock(this, m_pTerrain));
	AddAction(new GOAPActionLightFire(this, m_pTerrain));
	AddAction(new GOAPActionMakeFire(this, m_pTerrain));
	AddAction(new GOAPActionGatherStone(this, m_pTerrain));
	AddAction(new GOAPActionCook(this, m_pTerrain));
	AddAction(new GOAPActionEatFood(this, m_pTerrain));
	AddAction(new GOAPActionGatherBerries(this, m_pTerrain));
	AddAction(new GOAPActionHunt(this, m_pTerrain));
	AddAction(new GOAPActionGetIronTool(this, m_pTerrain));
	AddAction(new GOAPActionGetStoneTool(this, m_pTerrain));
	AddAction(new GOAPActionPlaceCrafter(this, m_pTerrain));
	AddAction(new GOAPActionPlaceForge(this, m_pTerrain));
	AddAction(new GOAPActionMakeIronTool(this, m_pTerrain));

	m_pPlanner->PopulateEffectMap(m_ActionList);

	m_pPlanner->ChangeWorldState(WorldStateProperty(EGOAPSYMBOL_TREE_EXISTS, true));
	m_pPlanner->ChangeWorldState(WorldStateProperty(EGOAPSYMBOL_ROCK_EXISTS, true));
	//m_pPlanner->ChangeWorldState(WorldStateProperty(EGOAPSYMBOL_AVAILABLE_STONE_TOOL, true));
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

void AI::Plan(WorldStateProperty wsp)
{
	system("cls");

	auto start = Clock::now();

	m_Plan = m_pPlanner->MakePlan(wsp);

	auto end = Clock::now();

	for (int i = 0; i < m_Plan.size(); ++i)
	{
		printf("%s\n", m_Plan[i]->GetName());
	}

	std::cout << "time taken:" << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;
}
