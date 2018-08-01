#include "GOAPActionGatherSticks.h"
#include "AI.h"
#include "Terrain.h"



GOAPActionGatherSticks::GOAPActionGatherSticks(AI* pAI, Terrain* pTerrain) : GOAPActionBase(pAI, pTerrain)
{
	m_ActionName = "GOAPActionGatherSticks";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_TREE_EXISTS, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_WOOD);
}


GOAPActionGatherSticks::~GOAPActionGatherSticks()
{
}
