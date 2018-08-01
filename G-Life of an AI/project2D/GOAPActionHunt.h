#pragma once
#include "GOAPActionBase.h"
class GOAPActionHunt :
	public GOAPActionBase
{
public:
	GOAPActionHunt(AI* pAI, Terrain* pTerrain);
	~GOAPActionHunt();
};