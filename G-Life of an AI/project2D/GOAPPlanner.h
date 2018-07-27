#pragma once
#include<queue>
#include "GOAPGraph.h"
#include "EGOAPSymbols.h"

class GOAPActionBase;

class GOAPPlanner
{
public:
	GOAPPlanner();
	~GOAPPlanner();

	std::queue<GOAPActionBase*> MakePlan(EGOAPSymbol symbol, bool goalVal);

	void SetActionList(std::vector<GOAPActionBase*>* pActionList);

	void SetState(SymbolMap const& newState);

private:
	bool CanDoAction(GOAPActionBase* action, SymbolMap& state);

	GOAPGraph MakeGraph();

	void PrintPlanFromNode(GOAPGraphNode* node);

	// Variables
	SymbolMap m_worldState;
	std::vector<GOAPActionBase*>* m_pActionList;

};


