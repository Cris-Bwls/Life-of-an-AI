#pragma once
#include "GOAPActionBase.h"
class GOAPActionSleepBase :
	public GOAPActionBase
{
public:
	GOAPActionSleepBase(AI* pAI, Terrain* pTerrain);
	virtual ~GOAPActionSleepBase();
};

