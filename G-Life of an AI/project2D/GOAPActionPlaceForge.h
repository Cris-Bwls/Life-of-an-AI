#pragma once
#include "GOAPActionBase.h"
class GOAPActionPlaceForge :
	public GOAPActionBase
{
public:
	GOAPActionPlaceForge(AI* pAI, Terrain* pTerrain);
	~GOAPActionPlaceForge();
};

