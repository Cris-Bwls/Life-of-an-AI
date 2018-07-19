#pragma once
#include "SteeringBase.h"

class Flocking;

class SteeringSeperation :
	public SteeringBase
{
public:
	SteeringSeperation();
	~SteeringSeperation();

	Vector2 Update(Flocking* pFlocking, Agent* pAgent, float fDeltaTime);
};

