#include "GOAPPlanner.h"
#include "GOAPActionBase.h"
#include "Agent.h"


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
