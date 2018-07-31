#include "GOAPActionGetStoneTool.h"



GOAPActionGetStoneTool::GOAPActionGetStoneTool()
{
	m_ActionName = "GOAPActionGetStoneTool";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_AVAILABLE_STONE_TOOL, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_STONE_TOOL);
	m_EffectList.push_back(EGOAPSYMBOL_HAVE_TOOL);
}


GOAPActionGetStoneTool::~GOAPActionGetStoneTool()
{
}
