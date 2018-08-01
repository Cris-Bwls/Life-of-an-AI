#include "GOAPActionGatherBerries.h"
#include "AI.h"
#include "Terrain.h"



GOAPActionGatherBerries::GOAPActionGatherBerries(AI* pAI, Terrain* pTerrain) : GOAPActionBase(pAI, pTerrain)
{
	m_ActionName = "GOAPActionGatherBerries";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_TREE_EXISTS, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_FOOD);

	m_nCost = 50;
}


GOAPActionGatherBerries::~GOAPActionGatherBerries()
{
}