#include "GOAPActionMineRock.h"



GOAPActionMineRock::GOAPActionMineRock()
{
	m_ActionName = "GOAPActionMineRock";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_TOOL, true));
	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_ROCK_EXISTS, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_STONE);
	m_EffectList.push_back(EGOAPSYMBOL_HAVE_IRON);

	m_nCost = 5;
}


GOAPActionMineRock::~GOAPActionMineRock()
{
}