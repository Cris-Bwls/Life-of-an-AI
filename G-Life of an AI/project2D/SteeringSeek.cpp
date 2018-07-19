#include "SteeringSeek.h"
#include "Input.h"
#include "Vector2.h"
#include "Agent.h"

SteeringSeek::SteeringSeek()
{
}


SteeringSeek::~SteeringSeek()
{
}

Vector2 SteeringSeek::Update(Agent* pAgent, float fDeltaTime, Vector2 v2Dest)
{
	Vector2 v2Dir = v2Dest - pAgent->GetPos();
	v2Dir.normalise();
	v2Dir *= pAgent->GetMaxSpeed();

	Vector2 v2Accel = v2Dir - pAgent->GetVelocity();

	Vector2 v2Vel = v2Accel * fDeltaTime;

	return v2Vel * m_fWeighting;
}