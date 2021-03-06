#include "SteeringWander.h"
#include "Agent.h"
#include <time.h>
#include <random>


SteeringWander::SteeringWander(float fRadius, float fDistance, float fJitter)
{
	m_fRadius = fRadius;
	m_fDistance = fDistance;
	m_fJitter = fJitter;

	srand((unsigned int)time((time_t)0));
}


SteeringWander::~SteeringWander()
{
}


Vector2 SteeringWander::Update(Agent* pAgent, float fDeltaTime)
{
	Vector2 v2Target = WanderTarget(pAgent);
	return WanderSeek(pAgent, fDeltaTime, v2Target) * m_fWeighting;
}

Vector2 SteeringWander::WanderSeek(Agent* pAgent, float fDeltaTime, Vector2 v2Pos)
{

	Vector2 v2Dir = v2Pos - pAgent->GetPos();
	v2Dir.normalise();
	v2Dir *= pAgent->GetMaxSpeed();

	Vector2 v2Accel = v2Dir - pAgent->GetVelocity();

	Vector2 v2Vel = v2Accel * fDeltaTime;

	return v2Vel;

	return Vector2();
}

Vector2 SteeringWander::WanderTarget(Agent* pAgent)
{
	float rot = pAgent->GetRotation();

	float random = rand() * 0.314f;
	Vector2 v2Target;
	v2Target.x = -sinf(random)*m_fRadius;
	v2Target.y = cosf(random)*m_fRadius;

	Vector2 v2Jitter((float)rand(), (float)rand());
	v2Jitter.normalise();
	v2Jitter *= m_fJitter;

	v2Target += v2Jitter;

	v2Target.normalise();
	v2Target *= m_fRadius;


	Vector2 v2Offset;
	v2Offset.x = -sin(rot)*m_fDistance;
	v2Offset.y = cos(rot)*m_fDistance;

	v2Target += v2Offset + pAgent->GetPos();

	return v2Target;

	return Vector2();
}