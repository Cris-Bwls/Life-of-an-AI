#include "GOAPActionCook.h"
#include "AI.h"
#include "Terrain.h"



GOAPActionCook::GOAPActionCook(AI* pAI, Terrain* pTerrain) : GOAPActionBase(pAI, pTerrain)
{
	m_ActionName = "GOAPActionCook";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_ACTIVE_FIRE, true));
	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_MEAT, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_FOOD);
}


GOAPActionCook::~GOAPActionCook()
{
}