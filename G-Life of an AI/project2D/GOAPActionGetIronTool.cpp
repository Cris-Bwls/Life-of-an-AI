#include "GOAPActionGetIronTool.h"
#include "AI.h"
#include "Terrain.h"



GOAPActionGetIronTool::GOAPActionGetIronTool(AI* pAI, Terrain* pTerrain) : GOAPActionBase(pAI, pTerrain)
{
	m_ActionName = "GOAPActionGetIronTool";
	
	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_AVAILABLE_IRON_TOOL, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_IRON_TOOL);
	m_EffectList.push_back(EGOAPSYMBOL_HAVE_TOOL);
}


GOAPActionGetIronTool::~GOAPActionGetIronTool()
{
}
