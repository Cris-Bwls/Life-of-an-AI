#pragma once
#include "GOAPActionSleepBase.h"
class GOAPActionSleepOutside :
	public GOAPActionSleepBase
{
public:
	GOAPActionSleepOutside(AI* pAI, Terrain* pTerrain);
	~GOAPActionSleepOutside();
};

