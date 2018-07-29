#include "AI.h"

#include "GOAPActionBase.h"
#include "GOAPPlanner.h"
#include <typeinfo>

// DEBUG
#include <iostream>
#include "GOAPActionGatherSticks.h"
#include "GOAPActionGatherStone.h"
#include "GOAPActionMakeTool.h"
#include "GOAPActionChopTree.h"
#include "GOAPActionMineRock.h"
#include "GOAPActionMakeObject.h"
#include "GOAPActionLightFire.h"

#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

AI::AI()
{
	m_pPlanner = new GOAPPlanner;

	// DEBUG
	AddAction(new GOAPActionGatherSticks);
	AddAction(new GOAPActionMakeTool);
	AddAction(new GOAPActionChopTree);
	AddAction(new GOAPActionMineRock);
	AddAction(new GOAPActionLightFire);
	AddAction(new GOAPActionMakeObject);
	AddAction(new GOAPActionGatherStone);
	AddAction(new GOAPActionGatherSticks);
	AddAction(new GOAPActionGatherSticks);
	AddAction(new GOAPActionGatherSticks);

	m_pPlanner->PopulateEffectMap(m_ActionList);

	std::vector<WorldStateProperty> vec;
	WorldStateProperty wsp;
	wsp.eSymbol = EGOAPSYMBOLS_FIRE_LIT;
	wsp.bData = true;

	
	auto start = Clock::now();

	auto plan = m_pPlanner->MakePlan(wsp);

	auto end = Clock::now();
	
	for (int i = 0; i < plan.size(); ++i)
	{
		printf("%s\n", plan[i]->GetName());
	}

	std::cout << "time taken:" << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << " microseconds" << std::endl;
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
