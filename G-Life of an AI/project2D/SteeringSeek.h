#pragma once
#include "SteeringBase.h"
class SteeringSeek :
	public SteeringBase
{
public:
	SteeringSeek();
	~SteeringSeek();

	Vector2 Update(Agent* pAgent, float fDeltaTime);
};

