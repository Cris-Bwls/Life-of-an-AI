#include "GOAPActionMakeStoneTool.h"



GOAPActionMakeStoneTool::GOAPActionMakeStoneTool()
{
	m_ActionName = "GOAPActionMakeStoneTool";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_WOOD, true));
	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_STONE, true));

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_EXISTS_CRAFTER, true));

	m_EffectList.push_back(EGOAPSYMBOL_AVAILABLE_STONE_TOOL);
}


GOAPActionMakeStoneTool::~GOAPActionMakeStoneTool()
{
}