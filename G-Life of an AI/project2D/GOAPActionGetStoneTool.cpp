#include "GOAPActionGetStoneTool.h"
#include "AI.h"
#include "Terrain.h"



GOAPActionGetStoneTool::GOAPActionGetStoneTool(AI* pAI, Terrain* pTerrain) : GOAPActionBase(pAI, pTerrain)
{
	m_ActionName = "GOAPActionGetStoneTool";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_AVAILABLE_STONE_TOOL, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_STONE_TOOL);
	m_EffectList.push_back(EGOAPSYMBOL_HAVE_TOOL);
}


GOAPActionGetStoneTool::~GOAPActionGetStoneTool()
{
}
