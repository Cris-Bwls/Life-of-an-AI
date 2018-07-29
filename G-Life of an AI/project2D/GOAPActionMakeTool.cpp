#include "GOAPActionMakeTool.h"



GOAPActionMakeTool::GOAPActionMakeTool()
{
	m_ActionName = "GOAPActionMakeTool";
	{
		WorldStateProperty wsp;
		wsp.eSymbol = EGOAPSYMBOLS_HAVE_WOOD;
		wsp.bData = true;

		m_PreConditionList.push_back(wsp);
	}
	//{
	//	WorldStateProperty wsp;
	//	wsp.eSymbol = EGOAPSYMBOLS_HAVE_STONE;
	//	wsp.bData = true;

	//	m_PreConditionList.push_back(wsp);
	//}

	m_EffectList.push_back(EGOAPSYMBOLS_HAVE_TOOL);
}


GOAPActionMakeTool::~GOAPActionMakeTool()
{
}