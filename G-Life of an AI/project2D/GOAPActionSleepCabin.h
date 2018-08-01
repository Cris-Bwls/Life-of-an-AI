#pragma once
#include "GOAPActionSleepBase.h"
class GOAPActionSleepCabin :
	public GOAPActionSleepBase
{
public:
	GOAPActionSleepCabin(AI* pAI, Terrain* pTerrain);
	~GOAPActionSleepCabin();
};

