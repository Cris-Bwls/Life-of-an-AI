#pragma once
#include "GOAPActionBase.h"
class GOAPActionPlaceCrafter :
	public GOAPActionBase
{
public:
	GOAPActionPlaceCrafter(AI* pAI, Terrain* pTerrain);
	~GOAPActionPlaceCrafter();
};

