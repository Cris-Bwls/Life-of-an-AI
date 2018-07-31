#include "GOAPActionChopTree.h"



GOAPActionChopTree::GOAPActionChopTree()
{
	m_ActionName = "GOAPActionChopTree";
	
	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_TOOL, true));
	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_TREE_EXISTS, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_WOOD);

	m_nCost = 5;
}


GOAPActionChopTree::~GOAPActionChopTree()
{
}
