#pragma once
#include "GOAPActionBase.h"
class GOAPActionGetResources :
	public GOAPActionBase
{
public:
	GOAPActionGetResources(AI* pAI, Terrain* pTerrain);
	~GOAPActionGetResources();
};