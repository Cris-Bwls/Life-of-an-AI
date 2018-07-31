#include "GOAPActionLightFire.h"

#include "StaticObjectManager.h"

GOAPActionLightFire::GOAPActionLightFire()
{
	m_ActionName = "GOAPActionLightFire";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_WOOD, true));
	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_EXISTS_FIRE, true));

	m_EffectList.push_back(EGOAPSYMBOL_ACTIVE_FIRE);
}


GOAPActionLightFire::~GOAPActionLightFire()
{
}

bool GOAPActionLightFire::CheckProceduralPreconditions()
{
	// DEBUG
	return true;

	// CHECK IF FIRE EXISTS	
	if (StaticObjectManager::GetInstance()->bFireExists)
		return true;
	return false;
}