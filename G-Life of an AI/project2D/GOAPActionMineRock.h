#pragma once
#include "GOAPActionBase.h"
class GOAPActionMineRock :
	public GOAPActionBase
{
public:
	GOAPActionMineRock(AI* pAI, Terrain* pTerrain);
	~GOAPActionMineRock();
};