#pragma once
#include "GOAPActionBase.h"
class GOAPActionGatherStone :
	public GOAPActionBase
{
public:
	GOAPActionGatherStone(AI* pAI, Terrain* pTerrain);
	~GOAPActionGatherStone();
};

