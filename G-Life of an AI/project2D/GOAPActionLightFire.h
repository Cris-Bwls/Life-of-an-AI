#pragma once
#include "GOAPActionBase.h"
class GOAPActionLightFire :
	public GOAPActionBase
{
public:
	GOAPActionLightFire(AI* pAI, Terrain* pTerrain);
	~GOAPActionLightFire();

	bool CheckProceduralPreconditions();
};