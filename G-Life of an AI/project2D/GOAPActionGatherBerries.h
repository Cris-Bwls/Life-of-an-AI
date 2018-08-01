#pragma once
#include "GOAPActionBase.h"
class GOAPActionGatherBerries :
	public GOAPActionBase
{
public:
	GOAPActionGatherBerries(AI* pAI, Terrain* pTerrain);
	~GOAPActionGatherBerries();
};