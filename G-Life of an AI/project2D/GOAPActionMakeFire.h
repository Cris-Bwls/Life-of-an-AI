#pragma once
#include "GOAPActionBase.h"
class GOAPActionMakeFire :
	public GOAPActionBase
{
public:
	GOAPActionMakeFire(AI* pAI, Terrain* pTerrain);
	~GOAPActionMakeFire();
};