#include "GOAPPlanner.h"
#include "GOAPActionBase.h"
#include "Agent.h"
#include <algorithm>

GOAPPlanner::GOAPPlanner()
{
	// Initialize Effect Map
	for (int i = 0; i < EGOAPSYMBOLS_TOTAL; ++i)
	{
		EGOAPSymbols currentSymbol = (EGOAPSymbols)i;
		std::vector<GOAPActionBase*> newList;

		m_EffectMap[currentSymbol] = newList;
	}
}


GOAPPlanner::~GOAPPlanner()
{
}

void GOAPPlanner::PopulateEffectMap(std::vector<GOAPActionBase*> actionList)
{
	for (int i = 0; i < actionList.size(); ++i)
	{
		auto actionEffects = actionList[i]->GetEffectList();

		for (int j = 0; j < actionEffects.size(); ++j)
		{
			m_EffectMap[actionEffects[j]].push_back(actionList[i]);
		}
	}
}

void GOAPPlanner::ChangeWorldState(WorldStateProperty * pChange)
{
	m_WorldState.WorldStateProperties[pChange->eSymbol].data = pChange->data;
}

std::vector<GOAPActionBase*> GOAPPlanner::MakePlan(std::vector<WorldStateProperty> goalState)
{
	auto SortHeapFunc = ([](GOAPActionBase* lhs, GOAPActionBase* rhs) {return lhs->GetFinalCost() > rhs->GetFinalCost(); });
	
	std::vector<GOAPActionBase*> plan;
	std::vector<GOAPActionBase*> openList;
	
	// Reset Effect Map
	for (int i = 0; i < EGOAPSYMBOLS_TOTAL; ++i)
	{
		EGOAPSymbols currentSymbol = (EGOAPSymbols)i;

		for (int j = 0; j < m_EffectMap[currentSymbol].size(); ++j)
		{
			m_EffectMap[currentSymbol][j]->SetUsed(false);
			m_EffectMap[currentSymbol][j]->SetPrev(nullptr);
		}
	}
	
	for (int i = 0; i < goalState.size(); ++i)
	{
		auto worldStateData = m_WorldState.WorldStateProperties[goalState[i].eSymbol].data;
		auto goalStateData = goalState[i].data;

		// Check if goal state is current world state
		if (memcmp(&worldStateData, &goalStateData, sizeof(worldStateData)) == 0)
			return plan;

		auto currentEffectMap = m_EffectMap[goalState[i].eSymbol];

		for (int j = 0; j < currentEffectMap.size(); ++j)
		{
			auto pAction = currentEffectMap[j];
			openList.push_back(pAction);
			std::push_heap(openList.begin(), openList.end(), SortHeapFunc);
		}
	}

	while (openList.size() > 0)
	{
		// Remove lowest node from open list and make it used
		GOAPActionBase* pCurrent = openList[0];

		std::pop_heap(openList.begin(), openList.end(), SortHeapFunc);
		openList.pop_back();

		pCurrent->SetUsed(true);
		
		// If Plan Complete

	}

	// DEBUG
	return std::vector<GOAPActionBase*>();
}
