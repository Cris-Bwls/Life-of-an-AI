#pragma once
#include "GOAPActionBase.h"
class GOAPActionCook :
	public GOAPActionBase
{
public:
	GOAPActionCook(AI* pAI, Terrain* pTerrain);
	~GOAPActionCook();
};