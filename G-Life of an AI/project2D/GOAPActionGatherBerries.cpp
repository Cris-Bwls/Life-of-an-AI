#include "GOAPActionGatherBerries.h"



GOAPActionGatherBerries::GOAPActionGatherBerries()
{
	m_ActionName = "GOAPActionGatherBerries";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_TREE_EXISTS, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_FOOD);

	m_nCost = 50;
}


GOAPActionGatherBerries::~GOAPActionGatherBerries()
{
}