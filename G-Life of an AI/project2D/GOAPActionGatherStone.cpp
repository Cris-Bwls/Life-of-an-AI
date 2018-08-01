#include "GOAPActionGatherStone.h"
#include "AI.h"
#include "Terrain.h"



GOAPActionGatherStone::GOAPActionGatherStone(AI* pAI, Terrain* pTerrain) : GOAPActionBase(pAI, pTerrain)
{
	m_ActionName = "GOAPActionGatherStone";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_ROCK_EXISTS, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_STONE);

}


GOAPActionGatherStone::~GOAPActionGatherStone()
{
}
