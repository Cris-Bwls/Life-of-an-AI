#pragma once
#include <vector>
#include "GOAPWorldState.h"

class GOAPActionBase
{
public:
	GOAPActionBase();
	virtual ~GOAPActionBase();

	inline std::vector<EGOAPSymbols> GetPreConditionList() { return m_PreConditionList; };
	inline std::vector<EGOAPSymbols> GetEffectList() { return m_EffectList; };
private:
	std::vector<EGOAPSymbols> m_PreConditionList;
	std::vector<EGOAPSymbols> m_EffectList;
};

