#include "GOAPPlanner.h"
#include "GOAPActionBase.h"
#include "Agent.h"
#include <algorithm>

GOAPPlanner::GOAPPlanner()
{
	// Initialize Effect Map
	for (int i = 0; i < EGOAPSYMBOL_TOTAL; ++i)
	{
		EGOAPSymbol currentSymbol = (EGOAPSymbol)i;
		std::vector<GOAPActionBase*> newList;

		m_EffectMap[currentSymbol] = newList;
	}
}


GOAPPlanner::~GOAPPlanner()
{
}

void GOAPPlanner::PopulateEffectMap(std::vector<GOAPActionBase*> actionList)
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

void GOAPPlanner::ChangeWorldState(WorldStateProperty pChange)
{
	m_WorldState.WorldStateProperties[pChange.eSymbol].bData = pChange.bData;
}

std::vector<GOAPActionBase*> GOAPPlanner::MakePlan(WorldStateProperty goalState)
{
	auto SortHeapFunc = ([](GOAPActionBase* lhs, GOAPActionBase* rhs) {return lhs->GetFScore() > rhs->GetFScore(); });
	
	std::vector<GOAPActionBase*> plan;
	std::vector<GOAPActionBase*> openList;

	WorldState planWorldState = m_WorldState;
	
	// Reset Effect Map
	for (int i = 0; i < EGOAPSYMBOL_TOTAL; ++i)
	{
		EGOAPSymbol currentSymbol = (EGOAPSymbol)i;

		for (unsigned int j = 0; j < m_EffectMap[currentSymbol].size(); ++j)
		{
			m_EffectMap[currentSymbol][j]->SetUsed(false);
			m_EffectMap[currentSymbol][j]->SetPrev(nullptr);
			m_EffectMap[currentSymbol][j]->m_nFailureCost = 0;
		}
	}

	auto worldStateData = m_WorldState.WorldStateProperties[goalState.eSymbol].bData;
	auto goalStateData = goalState.bData;

	// Check if goal state is current world state
	if (worldStateData == goalStateData)
		return plan;

	auto currentEffectActions = m_EffectMap[goalState.eSymbol];

	for (unsigned int j = 0; j < currentEffectActions.size(); ++j)
	{
		auto pAction = currentEffectActions[j];
		openList.push_back(pAction);
		std::push_heap(openList.begin(), openList.end(), SortHeapFunc);
		pAction->SetGScore(pAction->GetCost());
		pAction->SetUsed(true);
	}

	while (openList.size() > 0)
	{
		// Remove lowest node from open list and make it used
		GOAPActionBase* pCurrent = openList[0];

		std::pop_heap(openList.begin(), openList.end(), SortHeapFunc);
		openList.pop_back();

		// Check if Plan is Complete
		bool bPlanComplete = false;
		int nConditionSuccessCount = 0;
		std::vector<EGOAPSymbol> requiredEffects;

		auto currentPreConditions = pCurrent->GetPreConditionList();
		for (unsigned int i = 0; i < currentPreConditions.size(); ++i)
		{
			auto planStateData = planWorldState.WorldStateProperties[currentPreConditions[i].eSymbol].bData;
			auto preConditionData = currentPreConditions[i].bData;

			if (planStateData == preConditionData)
				++nConditionSuccessCount;
			else
			{
				requiredEffects.push_back(currentPreConditions[i].eSymbol);
			}
		}

		if (nConditionSuccessCount == currentPreConditions.size())
		{
			int nEffectCount = 0;
			for (int i = 0; i < pCurrent->GetEffectList().size(); ++i)
			{
				if (planWorldState.WorldStateProperties[pCurrent->GetEffectList()[i]].bData)
					++nEffectCount;
			}
			if (nEffectCount != pCurrent->GetEffectList().size())
				bPlanComplete = true;
		}


		// IF Plan Complete
		if (bPlanComplete)
		{
			plan.insert(plan.begin(), pCurrent);

			pCurrent->SetUsed(true);

			auto currentEffects = pCurrent->GetEffectList();
			for (int i = 0; i < currentEffects.size(); ++i)
			{
				planWorldState.WorldStateProperties[currentEffects[i]].bData = true;
			}

			while (pCurrent->GetPrev())
			{
				pCurrent = pCurrent->GetPrev();		

				int nEffectCount = 0;
				auto currentEffects = pCurrent->GetEffectList();
				for (int i = 0; i < currentEffects.size(); ++i)
				{
					if (planWorldState.WorldStateProperties[currentEffects[i]].bData == true)
						++nEffectCount;
				}
				if (nEffectCount == currentEffects.size())
					continue;
				
				int nPlanConditionSuccessCount = 0;
				auto currentPreConditions = pCurrent->GetPreConditionList();
				for (unsigned int i = 0; i < currentPreConditions.size(); ++i)
				{
					auto worldStateData = planWorldState.WorldStateProperties[currentPreConditions[i].eSymbol].bData;
					auto preConditionData = currentPreConditions[i].bData;

					if (worldStateData == preConditionData)
						++nPlanConditionSuccessCount;
					else
						requiredEffects.push_back(currentPreConditions[i].eSymbol);
				}

				if (nPlanConditionSuccessCount != currentPreConditions.size())
				{
					bPlanComplete = false;
					pCurrent->m_nFailureCost += 10;
				}

				if (bPlanComplete)
				{
					pCurrent->SetUsed(true);
					plan.insert(plan.begin(), pCurrent);

					for (int i = 0; i < currentEffects.size(); ++i)
					{
						planWorldState.WorldStateProperties[currentEffects[i]].bData = true;
					}

					// GOAL state reached return plan
					if (goalState.bData == planWorldState.WorldStateProperties[goalState.eSymbol].bData)
						return plan;
				}
			}

			// Return Plan (???REDUNDANT???)
			if(bPlanComplete)
				return plan;
		}

		for (unsigned int i = 0; i < requiredEffects.size(); ++i)
		{
			auto currentEffectActions = m_EffectMap[requiredEffects[i]];
			
			for (unsigned int j = 0; j < currentEffectActions.size(); ++j)
			{
				auto pNeighbour = currentEffectActions[j];

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
						pNeighbour->SetFScore(pNeighbour->GetGScore() + pNeighbour->GetHScore() + pNeighbour->m_nFailureCost);

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
					pNeighbour->SetFScore(pNeighbour->GetGScore() + pNeighbour->GetHScore() + pNeighbour->m_nFailureCost);

					// Add to List
					pNeighbour->SetPrev(pCurrent);

					openList.push_back(pNeighbour);
					std::push_heap(openList.begin(), openList.end(), SortHeapFunc);
				}
			}
		}

		requiredEffects.clear();
	}
	
	// Returns if no plan found
	plan.clear();
	return plan;
}
