#pragma once
#include "GOAPActionBase.h"
class GOAPActionLightFire :
	public GOAPActionBase
{
public:
	GOAPActionLightFire();
	~GOAPActionLightFire();

	bool CheckProceduralPreconditions();
};