#include "GOAPActionGatherStone.h"



GOAPActionGatherStone::GOAPActionGatherStone()
{
	m_ActionName = "GOAPActionGatherStone";

	//PreConditions
	m_PreConditions[EGOAPSYMBOL_ROCK_EXISTS] = true;

	//Effects
	m_Effects[EGOAPSYMBOL_HAVE_STONE] = true;
}


GOAPActionGatherStone::~GOAPActionGatherStone()
{
}
