#pragma once

#include <map>
#include <vector>
#include "EGOAPSymbols.h"

typedef const char* gloat;
typedef const char* insult;

enum ActionStatus
{
	// EACTIONSTATUS_

	EACTIONSTATUS_INACTIVE = 0,
	EACTIONSTATUS_ACTIVE,
	EACTIONSTATUS_DONE,
	EACTIONSTATUS_FAILED
};

class GOAPActionBase
{
public:
	GOAPActionBase();
	virtual ~GOAPActionBase();


	inline SymbolMap* GetPreConditions() { return &m_PreConditions; }
	inline SymbolMap* GetEffects() { return &m_Effects; }

	inline float GetRunningCost() { return m_fRunningCost; }
	inline float GetBaseCost() { return m_fBaseCost; }
	inline char* GetName() { return m_ActionName; }

	inline ActionStatus GetStatus() { return m_Status; }
	inline void SetStatus(ActionStatus status) { m_Status = status; }

	inline void ResetRunningCost() { m_fRunningCost = m_fBaseCost; }
	inline void AddRunningCost(float fCost) { m_fRunningCost += fCost; }
	inline std::vector<char*>* GetCostModifiers() { return &m_CostModifiers; }

	inline gloat HowGoodIsThisGOAP() { return "This GOAP is the best"; };

	virtual void Start();
	virtual void Run(float fDeltaTime);
	virtual void Finish();

	virtual inline void Reset();

protected:
	SymbolMap m_PreConditions;
	SymbolMap m_Effects;

	std::vector<char*> m_CostModifiers;

	char* m_ActionName;

	float m_fBaseCost;
	float m_fRunningCost;

	ActionStatus m_Status;
};

