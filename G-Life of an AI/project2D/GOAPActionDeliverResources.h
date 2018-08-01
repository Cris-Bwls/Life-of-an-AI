#pragma once
#include "GOAPActionBase.h"
class GOAPActionDeliverResources :
	public GOAPActionBase
{
public:
	GOAPActionDeliverResources(AI* pAI, Terrain* pTerrain);
	~GOAPActionDeliverResources();
};