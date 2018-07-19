#pragma once
#include "SteeringBase.h"

class Flocking;

class SteeringAlignment :
	public SteeringBase
{
public:
	SteeringAlignment();
	~SteeringAlignment();

	Vector2 Update(Flocking* pFlocking ,Agent* pAgent, float fDeltaTime);
};

