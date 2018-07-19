#pragma once
#include "Vector2.h"

class Agent;

class SteeringBase
{
public:
	SteeringBase();
	virtual ~SteeringBase();

	virtual Vector2 Update(Agent* pAgent, float fDeltaTime) { return Vector2(); };
	
	float m_fWeighting;
};

