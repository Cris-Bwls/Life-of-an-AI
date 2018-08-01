#include "GOAPActionHunt.h"
#include "AI.h"
#include "Terrain.h"



GOAPActionHunt::GOAPActionHunt(AI* pAI, Terrain* pTerrain) : GOAPActionBase(pAI, pTerrain)
{
	m_ActionName = "GOAPActionHunt";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_ENEMY_EXISTS, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_MEAT);

	m_nCost = 10;
}


GOAPActionHunt::~GOAPActionHunt()
{
}