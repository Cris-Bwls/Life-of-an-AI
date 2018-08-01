#pragma once
#include "GOAPActionBase.h"
class GOAPActionMakeStoneTool :
	public GOAPActionBase
{
public:
	GOAPActionMakeStoneTool(AI* pAI, Terrain* pTerrain);
	~GOAPActionMakeStoneTool();
};