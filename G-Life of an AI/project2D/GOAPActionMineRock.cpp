#include "GOAPActionMineRock.h"



GOAPActionMineRock::GOAPActionMineRock()
{
	m_ActionName = "GOAPActionMineRock";

	//PreConditions
	m_PreConditions[EGOAPSYMBOL_HAVE_TOOL] = true;
	m_PreConditions[EGOAPSYMBOL_ROCK_EXISTS] = true;

	//Effects
	m_Effects[EGOAPSYMBOL_HAVE_STONE] = true;
}


GOAPActionMineRock::~GOAPActionMineRock()
{
}