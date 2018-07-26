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

AI::AI()
{
	m_pPlanner = new GOAPPlanner;

	// DEBUG
	AddAction(new GOAPActionGatherSticks);
	AddAction(new GOAPActionGatherStone);
	AddAction(new GOAPActionMakeTool);
	AddAction(new GOAPActionChopTree);
	AddAction(new GOAPActionMineRock);
	AddAction(new GOAPActionMakeObject);

	m_pPlanner->PopulateEffectMap(m_ActionList);

	std::vector<WorldStateProperty> vec;
	WorldStateProperty wsp;
	wsp.eSymbol = EGOAPSYMBOLS_FIRE_LIT;
	wsp.bData = true;

	vec.push_back(wsp);

	auto plan = m_pPlanner->MakePlan(vec);
	
	for (int i = 0; i < plan.size(); ++i)
	{
		printf("%s\n", plan[i]->GetName());
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
			return;
	}

	m_ActionList.push_back(pAction);
}
