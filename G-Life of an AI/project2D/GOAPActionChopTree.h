#pragma once
#include "GOAPActionBase.h"
class GOAPActionChopTree :
	public GOAPActionBase
{
public:
	GOAPActionChopTree(AI* pAI, Terrain* pTerrain);
	~GOAPActionChopTree();
};

