#pragma once
#include "GOAPActionBase.h"
class GOAPActionEatFood :
	public GOAPActionBase
{
public:
	GOAPActionEatFood(AI* pAI, Terrain* pTerrain);
	~GOAPActionEatFood();
};