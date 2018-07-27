#include "GOAPActionGatherSticks.h"



GOAPActionGatherSticks::GOAPActionGatherSticks()
{
	m_ActionName = "GOAPActionGatherSticks";

	//PreConditions
	m_PreConditions[EGOAPSYMBOL_TREE_EXISTS] = true;

	//Effects
	m_Effects[EGOAPSYMBOL_HAVE_WOOD] = true;
}


GOAPActionGatherSticks::~GOAPActionGatherSticks()
{
}
