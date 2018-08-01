#include "GOAPActionMakeIronTool.h"
#include "AI.h"
#include "Terrain.h"



GOAPActionMakeIronTool::GOAPActionMakeIronTool(AI* pAI, Terrain* pTerrain) : GOAPActionBase(pAI, pTerrain)
{
	m_ActionName = "GOAPActionMakeIronTool";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_WOOD, true));
	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_IRON, true));
	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_HAVE_STONE_TOOL, true));

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_EXISTS_FORGE, true));

	m_EffectList.push_back(EGOAPSYMBOL_AVAILABLE_IRON_TOOL);
}


GOAPActionMakeIronTool::~GOAPActionMakeIronTool()
{
}
