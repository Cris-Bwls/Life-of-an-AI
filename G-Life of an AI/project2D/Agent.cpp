#include "Agent.h"

#define _USE_MATH_DEFINES
#include <math.h>

Agent::Agent()
{
}


Agent::~Agent()
{
}

void Agent::Update(float fDeltaTime)
{
	Vector2 v2TotalVelocity;

	//for (int i = 0; i < m_BehaviourList.size(); ++i)
	//{
	//	float fMagnitude = v2TotalVelocity.magnitude();
	//	float fRemaining = m_fMaxSpeed - fMagnitude;

	//	if (fRemaining <= 0.0f)
	//	{
	//		break;
	//	}

	//	Vector2 v2Force = m_BehaviourList[i]->Update(this, fDeltaTime);
	//	v2Force *= m_BehaviourList[i]->m_fWeighting;

	//	float fForce = v2Force.magnitude();
	//	if (fForce < fRemaining)
	//	{
	//		v2TotalVelocity += v2Force;
	//	}
	//	else
	//	{
	//		v2Force.normalise();
	//		v2Force *= fRemaining;

	//		v2TotalVelocity += v2Force;
	//	}
	//}

	m_v2Velocity += v2TotalVelocity;

	Vector2 v2Pos = GetPos();
	v2Pos += m_v2Velocity * fDeltaTime;

	m_fRotation = atan2f(m_v2Velocity.y, m_v2Velocity.x);
	m_fRotation -= M_PI_2;

	SetRotation(m_fRotation);

	SetPos(v2Pos);
}

void Agent::Draw(aie::Renderer2D* pRenderer)
{
	pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m3Transform);
}

void Agent::SetVelocity(Vector2 v2Velocity)
{
	m_v2Velocity = v2Velocity;
}

Vector2 Agent::GetVelocity()
{
	return m_v2Velocity;
}

void Agent::SetMaxSpeed(float fMaxSpeed)
{
	m_fMaxSpeed = fMaxSpeed;
}

float Agent::GetMaxSpeed()
{
	return m_fMaxSpeed;
}