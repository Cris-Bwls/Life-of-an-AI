#include "GOAPActionLightFire.h"

#include "StaticObjectManager.h"

GOAPActionLightFire::GOAPActionLightFire()
{
	m_ActionName = "GOAPActionLightFire";

	//PreConditions
	m_PreConditions[EGOAPSYMBOL_EXISTS_FIRE] = true;
	m_PreConditions[EGOAPSYMBOL_HAVE_WOOD] = true;

	//Effects
	m_Effects[EGOAPSYMBOL_ACTIVE_FIRE] = true;
}


GOAPActionLightFire::~GOAPActionLightFire()
{
}

bool GOAPActionLightFire::CheckProceduralPreconditions()
{
	// CHECK IF FIRE EXISTS	
	if (StaticObjectManager::GetInstance()->bFireExists)
		return true;
	return false;
}