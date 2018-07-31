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
	AddAction(new GOAPActionGatherSticks);
	AddAction(new GOAPActionMakeStoneTool);
	AddAction(new GOAPActionChopTree);
	AddAction(new GOAPActionMineRock);
	AddAction(new GOAPActionLightFire);
	AddAction(new GOAPActionMakeFire);
	AddAction(new GOAPActionGatherStone);
	AddAction(new GOAPActionCook);
	AddAction(new GOAPActionEatFood);
	AddAction(new GOAPActionGatherBerries);
	AddAction(new GOAPActionHunt);
	AddAction(new GOAPActionGetIronTool);
	AddAction(new GOAPActionGetStoneTool);
	AddAction(new GOAPActionPlaceCrafter);
	AddAction(new GOAPActionPlaceForge);
	AddAction(new GOAPActionMakeIronTool);

	m_pPlanner->PopulateEffectMap(m_ActionList);
	m_pPlanner->ChangeWorldState(WorldStateProperty(EGOAPSYMBOL_TREE_EXISTS, true));
	m_pPlanner->ChangeWorldState(WorldStateProperty(EGOAPSYMBOL_ROCK_EXISTS, true));
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

void AI::Plan()
{
	system("cls");

	auto start = Clock::now();

	auto plan = m_pPlanner->MakePlan(WorldStateProperty(EGOAPSYMBOL_FULL, true));

	auto end = Clock::now();

	for (int i = 0; i < plan.size(); ++i)
	{
		printf("%s\n", plan[i]->GetName());
	}

	std::cout << "time taken:" << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;
}
