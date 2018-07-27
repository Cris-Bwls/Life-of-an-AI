#include "GOAPActionGetWeapon.h"



GOAPActionGetWeapon::GOAPActionGetWeapon()
{
	m_ActionName = "GOAPActionGetWeapon";

	//PreConditions
	m_PreConditions[EGOAPSYMBOL_AVAILABLE_WEAPON] = true;

	//Effects
	m_Effects[EGOAPSYMBOL_HAVE_WEAPON] = true;
}


GOAPActionGetWeapon::~GOAPActionGetWeapon()
{
}
