#include "GOAPActionPlaceForge.h"
#include "AI.h"
#include "Terrain.h"



GOAPActionPlaceForge::GOAPActionPlaceForge(AI* pAI, Terrain* pTerrain) : GOAPActionBase(pAI, pTerrain)
{
	m_ActionName = "GOAPActionPlaceForge";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_WOOD, true));
	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_STONE, true));

	m_EffectList.push_back(EGOAPSYMBOL_EXISTS_FORGE);
}


GOAPActionPlaceForge::~GOAPActionPlaceForge()
{
}
