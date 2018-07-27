#include "GOAPActionChopTree.h"



GOAPActionChopTree::GOAPActionChopTree()
{
	m_ActionName = "GOAPActionChopTree";

	//PreConditions
	m_PreConditions[EGOAPSYMBOL_HAVE_TOOL] = true;
	m_PreConditions[EGOAPSYMBOL_TREE_EXISTS] = true;

	//Effects
	m_Effects[EGOAPSYMBOL_HAVE_WOOD] = true;
}


GOAPActionChopTree::~GOAPActionChopTree()
{
}
