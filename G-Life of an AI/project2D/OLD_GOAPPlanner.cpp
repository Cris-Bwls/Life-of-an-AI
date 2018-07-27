#include "OLD_GOAPPlanner.h"
#include "OLD_GOAPActionBase.h"
#include "Agent.h"
#include <algorithm>

OLD_GOAPPlanner::OLD_GOAPPlanner()
{
	// Initialize Effect Map
	for (int i = 0; i < EGOAPSYMBOLS_TOTAL; ++i)
	{
		OLD_EGOAPSymbols currentSymbol = (OLD_EGOAPSymbols)i;
		std::vector<GOAPActionBase*> newList;

		m_EffectMap[currentSymbol] = newList;
	}
}


OLD_GOAPPlanner::~OLD_GOAPPlanner()
{
}

void OLD_GOAPPlanner::PopulateEffectMap(std::vector<GOAPActionBase*> actionList)
{
	for (unsigned int i = 0; i < actionList.size(); ++i)
	{
		auto actionEffects = actionList[i]->GetEffectList();

		for (unsigned int j = 0; j < actionEffects.size(); ++j)
		{
			m_EffectMap[actionEffects[j]].push_back(actionList[i]);
		}
	}
}

void OLD_GOAPPlanner::ChangeWorldState(OLD_WorldStateProperty pChange)
{
	m_WorldState.WorldStateProperties[pChange.eSymbol].bData = pChange.bData;
}

std::vector<GOAPActionBase*> OLD_GOAPPlanner::MakePlan(std::vector<OLD_WorldStateProperty> goalState)
{
	auto SortHeapFunc = ([](GOAPActionBase* lhs, GOAPActionBase* rhs) {return lhs->GetFScore() > rhs->GetFScore(); });
	
	std::vector<GOAPActionBase*> plan;
	std::vector<GOAPActionBase*> openList;
	
	// Reset Effect Map
	for (int i = 0; i < EGOAPSYMBOLS_TOTAL; ++i)
	{
		OLD_EGOAPSymbols currentSymbol = (OLD_EGOAPSymbols)i;

		for (unsigned int j = 0; j < m_EffectMap[currentSymbol].size(); ++j)
		{
			m_EffectMap[currentSymbol][j]->SetUsed(false);
			m_EffectMap[currentSymbol][j]->SetPrev(nullptr);
		}
	}
	
	for (unsigned int i = 0; i < goalState.size(); ++i)
	{
		auto worldStateData = m_WorldState.WorldStateProperties[goalState[i].eSymbol].bData;
		auto goalStateData = goalState[i].bData;

		// Check if goal state is current world state
		if (worldStateData == goalStateData)
			return plan;

		auto currentEffectMap = m_EffectMap[goalState[i].eSymbol];

		for (unsigned int j = 0; j < currentEffectMap.size(); ++j)
		{
			auto pAction = currentEffectMap[j];
			openList.push_back(pAction);
			std::push_heap(openList.begin(), openList.end(), SortHeapFunc);
			pAction->SetGScore(pAction->GetCost());
		}
	}

	while (openList.size() > 0)
	{
		// Remove lowest node from open list and make it used
		GOAPActionBase* pCurrent = openList[0];

		std::pop_heap(openList.begin(), openList.end(), SortHeapFunc);
		openList.pop_back();

		pCurrent->SetUsed(true);

		//auto currentEffects = pCurrent->GetEffectList();
		//for (int i = 0; i < currentEffects.size(); ++i)
		//{
		//	m_WorldState.WorldStateProperties[currentEffects[i]].bData = true;
		//}
		
		// Check if Plan is Complete
		bool bPlanComplete = false;
		int nConditionSuccessCount = 0;
		std::vector<OLD_EGOAPSymbols> requiredEffects;

		auto currentPreConditions = pCurrent->GetPreConditionList();
		for (unsigned int i = 0; i < currentPreConditions.size(); ++i)
		{
			auto worldStateData = m_WorldState.WorldStateProperties[currentPreConditions[i].eSymbol].bData;
			auto preConditionData = currentPreConditions[i].bData;

			if (worldStateData == preConditionData)
				++nConditionSuccessCount;
			else
			{
				auto pNow = pCurrent;
				while (pNow->GetPrev())
				{
					pNow = pNow->GetPrev();
					for (int j = 0; j < pNow->GetEffectList().size(); ++j)
					{
						if (pNow->GetEffectList()[j] == currentPreConditions[i].eSymbol)
						{
							++nConditionSuccessCount;
							continue;
						}
					}
				}
				requiredEffects.push_back(currentPreConditions[i].eSymbol);
			}
		}

		if (currentPreConditions.size() > 0)
			if (nConditionSuccessCount == currentPreConditions.size())
				bPlanComplete = true;


		// IF Plan Complete
		if (bPlanComplete)
		{
			plan.insert(plan.begin(), pCurrent);

			while (pCurrent->GetPrev())
			{
				pCurrent = pCurrent->GetPrev();
				plan.insert(plan.begin(), pCurrent);
			}

			// Return Plan
			return plan;
		}

		for (unsigned int i = 0; i < requiredEffects.size(); ++i)
		{
			auto currentEffectMap = m_EffectMap[requiredEffects[i]];
			
			for (unsigned int j = 0; j < currentEffectMap.size(); ++j)
			{
				auto pNeighbour = currentEffectMap[j];

				// Skip null
				if (!pNeighbour)
					continue;

				// Skip If Procedural Preconditions check fails
				if (!pNeighbour->CheckProceduralPreconditions())
					continue;

				// Skip used
				if (pNeighbour->GetUsed())
					continue;

				//IF in open list
				if (std::find(openList.begin(), openList.end(), pNeighbour) != openList.end())
				{
					// Check if better plan
					int newGScore = pCurrent->GetGScore() + pNeighbour->GetCost();
					if (newGScore < pNeighbour->GetGScore())
					{
						// Update to use better plan
						pNeighbour->SetGScore(newGScore);
						pNeighbour->SetFScore(pNeighbour->GetGScore() + pNeighbour->GetHScore());

						pNeighbour->SetPrev(pCurrent);

						openList.push_back(pNeighbour);
						std::push_heap(openList.begin(), openList.end(), SortHeapFunc);
					}
				}
				// ELSE add to open list and calculate scores
				else
				{
					// Calculate GScore
					pNeighbour->SetGScore(pCurrent->GetGScore() + pNeighbour->GetCost());

					// Calculate H Score
					int nHScore = 0;
					
					auto neighbourPreConditions = pNeighbour->GetPreConditionList();
					for (unsigned int k = 0; k < neighbourPreConditions.size(); ++k)
					{
						auto worldStateData = m_WorldState.WorldStateProperties[neighbourPreConditions[k].eSymbol].bData;
						auto preConditionData = neighbourPreConditions[k].bData;

						// IF effect needed
						if (worldStateData != preConditionData)
							++nHScore;
					}

					// Multiply
					nHScore *= 10;

					// Set HScore
					pNeighbour->SetHScore(nHScore);

					// Set FScore
					pNeighbour->SetFScore(pNeighbour->GetGScore() + pNeighbour->GetHScore());

					// Add to List
					pNeighbour->SetPrev(pCurrent);

					openList.push_back(pNeighbour);
					std::push_heap(openList.begin(), openList.end(), SortHeapFunc);
				}
			}
		}
	}
	
	// Returns if no plan found
	return plan;
}
