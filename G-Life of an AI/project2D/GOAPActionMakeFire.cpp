#include "GOAPActionMakeFire.h"



GOAPActionMakeFire::GOAPActionMakeFire()
{
	m_ActionName = "GOAPActionMakeObject";

	//PreConditions
	m_PreConditions[EGOAPSYMBOL_HAVE_WOOD] = true;

	//Effects
	m_Effects[EGOAPSYMBOL_EXISTS_FIRE] = true;
}


GOAPActionMakeFire::~GOAPActionMakeFire()
{
}