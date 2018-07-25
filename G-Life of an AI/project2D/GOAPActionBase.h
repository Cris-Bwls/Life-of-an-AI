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

	inline void SetPrev(GOAPActionBase* pPrev) { m_pPrev = pPrev; };
	inline GOAPActionBase* GetPrev() { return m_pPrev; };

	inline void SetUsed(bool bUsed) { m_bUsed = bUsed; };
	inline bool GetUsed() { return m_bUsed; };

	inline float GetBaseCost() { return m_fBaseCost; };

	inline void SetFinalCost(float fFinalCost) { m_fFinalCost = fFinalCost; };
	inline float GetFinalCost() { return m_fFinalCost; };
private:
	std::vector<EGOAPSymbols> m_PreConditionList;
	std::vector<EGOAPSymbols> m_EffectList;

	GOAPActionBase* m_pPrev;

	bool m_bUsed;

	float m_fBaseCost;
	float m_fFinalCost;
};

