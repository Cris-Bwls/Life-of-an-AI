#include "GOAPActionMakeWeapon.h"



GOAPActionMakeWeapon::GOAPActionMakeWeapon()
{
	m_ActionName = "GOAPActionMakeWeapon";

	//PreConditions
	m_PreConditions[EGOAPSYMBOL_HAVE_WOOD] = true;
	m_PreConditions[EGOAPSYMBOL_HAVE_STONE] = true;

	//Effects
	m_Effects[EGOAPSYMBOL_AVAILABLE_WEAPON] = true;
}


GOAPActionMakeWeapon::~GOAPActionMakeWeapon()
{
}
