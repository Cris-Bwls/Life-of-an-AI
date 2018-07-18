#pragma once
#include "SteeringBase.h"
class SteeringWander :
	public SteeringBase
{
public:
	SteeringWander(float fRadius, float fDistance, float fJitter);
	~SteeringWander();

	Vector2 Update(Agent* pAgent, float fDeltaTime);

private:
	// Functions
	Vector2 WanderSeek(Agent* pAgent, float fDeltaTime, Vector2 v2Pos);
	Vector2 WanderTarget(Agent* pAgent);
	
	float m_fRadius;
	float m_fDistance;
	float m_fJitter;


};

