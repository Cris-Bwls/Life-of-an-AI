#include "GOAPActionMakeFire.h"



GOAPActionMakeFire::GOAPActionMakeFire()
{
	m_ActionName = "GOAPActionMakeFire";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_WOOD, true));

	m_EffectList.push_back(EGOAPSYMBOL_EXISTS_FIRE);
}


GOAPActionMakeFire::~GOAPActionMakeFire()
{
}