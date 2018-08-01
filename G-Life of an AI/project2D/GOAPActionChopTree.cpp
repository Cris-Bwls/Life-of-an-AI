#include "GOAPActionChopTree.h"
#include "AI.h"
#include "Terrain.h"



GOAPActionChopTree::GOAPActionChopTree(AI* pAI, Terrain* pTerrain) : GOAPActionBase(pAI, pTerrain)
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
