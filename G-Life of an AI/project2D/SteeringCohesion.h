#pragma once
#include "SteeringBase.h"

class SteeringSeek;
class Flocking;

class SteeringCohesion :
	public SteeringBase
{
public:
	SteeringCohesion();
	~SteeringCohesion();

	Vector2 Update(Flocking* pFlocking, Agent* pAgent, float fDeltaTime);

private:
	SteeringSeek* m_pSeek;
};

