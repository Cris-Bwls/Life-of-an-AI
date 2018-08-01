#include "GOAPActionEatFood.h"
#include "AI.h"
#include "Terrain.h"



GOAPActionEatFood::GOAPActionEatFood(AI* pAI, Terrain* pTerrain) : GOAPActionBase(pAI, pTerrain)
{
	m_ActionName = "GOAPActionEatFood";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_FOOD, true));

	m_EffectList.push_back(EGOAPSYMBOL_FULL);
}


GOAPActionEatFood::~GOAPActionEatFood()
{
}