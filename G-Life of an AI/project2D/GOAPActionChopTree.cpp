#include "GOAPActionChopTree.h"



GOAPActionChopTree::GOAPActionChopTree()
{
	m_ActionName = "GOAPActionChopTree";
	{
		WorldStateProperty wsp;
		wsp.eSymbol = EGOAPSYMBOLS_HAVE_TOOL;
		wsp.bData = true;

		m_PreConditionList.push_back(wsp);
	}

	m_EffectList.push_back(EGOAPSYMBOLS_HAVE_WOOD);
}


GOAPActionChopTree::~GOAPActionChopTree()
{
}
