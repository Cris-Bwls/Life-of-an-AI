#include "GOAPActionLightFire.h"

#include "StaticObjectManager.h"

GOAPActionLightFire::GOAPActionLightFire()
{
	m_ActionName = "GOAPActionLightFire";
	{
		WorldStateProperty wsp;
		wsp.eSymbol = EGOAPSYMBOLS_HAVE_WOOD;
		wsp.bData = true;

		m_PreConditionList.push_back(wsp);
	}

	m_EffectList.push_back(EGOAPSYMBOLS_FIRE_LIT);
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