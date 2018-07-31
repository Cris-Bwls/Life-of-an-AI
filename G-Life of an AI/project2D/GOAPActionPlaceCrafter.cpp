#include "GOAPActionPlaceCrafter.h"



GOAPActionPlaceCrafter::GOAPActionPlaceCrafter()
{
	m_ActionName = "GOAPActionPlaceCrafter";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_WOOD, true));
	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_STONE, true));

	m_EffectList.push_back(EGOAPSYMBOL_EXISTS_CRAFTER);
}


GOAPActionPlaceCrafter::~GOAPActionPlaceCrafter()
{
}
