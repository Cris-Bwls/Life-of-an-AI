#pragma once
#include "GOAPActionSleepBase.h"
class GOAPActionSleepTent :
	public GOAPActionSleepBase
{
public:
	GOAPActionSleepTent(AI* pAI, Terrain* pTerrain);
	~GOAPActionSleepTent();
};

