#pragma once
#include "SteeringBase.h"
class SteeringFlee :
	public SteeringBase
{
public:
	SteeringFlee();
	~SteeringFlee();

	Vector2 Update(Agent* pAgent, float fDeltaTime);
};

