#include "GOAPActionMakeObject.h"



GOAPActionMakeObject::GOAPActionMakeObject()
{
	m_ActionName = "GOAPActionMakeObject";
	{
		WorldStateProperty wsp;
		wsp.eSymbol = EGOAPSYMBOLS_HAVE_WOOD;
		wsp.bData = true;

		m_PreConditionList.push_back(wsp);
	}
	{
		WorldStateProperty wsp;
		wsp.eSymbol = EGOAPSYMBOLS_HAVE_STONE;
		wsp.bData = true;

		m_PreConditionList.push_back(wsp);
	}

	m_EffectList.push_back(EGOAPSYMBOLS_FIRE_LIT);
}


GOAPActionMakeObject::~GOAPActionMakeObject()
{
}