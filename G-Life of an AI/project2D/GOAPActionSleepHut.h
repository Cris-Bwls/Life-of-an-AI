#pragma once
#include "GOAPActionSleepBase.h"
class GOAPActionSleepHut :
	public GOAPActionSleepBase
{
public:
	GOAPActionSleepHut(AI* pAI, Terrain* pTerrain);
	~GOAPActionSleepHut();
};

