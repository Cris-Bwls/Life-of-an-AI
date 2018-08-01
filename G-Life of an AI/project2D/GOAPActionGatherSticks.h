#pragma once
#include "GOAPActionBase.h"
class GOAPActionGatherSticks :
	public GOAPActionBase
{
public:
	GOAPActionGatherSticks(AI* pAI, Terrain* pTerrain);
	~GOAPActionGatherSticks();
};

