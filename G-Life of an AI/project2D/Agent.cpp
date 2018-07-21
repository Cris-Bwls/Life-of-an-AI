#include "Agent.h"
#include "Terrain.h"

#define _USE_MATH_DEFINES
#include <math.h>

Agent::Agent()
{
	m_pTerrain = nullptr;

	m_fMaxSpeed = 15.0f;
	m_fHungrySpeed = m_fMaxSpeed * 0.5f;
	m_fCurrentMaxSpeed = m_fMaxSpeed;

	m_nHunger = 0;
}


Agent::~Agent()
{
}

void Agent::HungerCheck()
{
	if (m_nHunger > 80)
	{
		m_fCurrentMaxSpeed = m_fHungrySpeed;

		if (m_nHunger > 100)
			m_nHunger = 100;
	}
	else
	{
		m_fCurrentMaxSpeed = m_fMaxSpeed;

		if (m_nHunger < 0)
			m_nHunger = 0;
	}
}

void Agent::Draw(aie::Renderer2D* pRenderer)
{
	if (m_pTexture)
		pRenderer->drawSpriteTransformed3x3(m_pTexture, (float*)m3Transform);
	else
	{
		pRenderer->setRenderColour(0xffaec8FF);
		pRenderer->drawCircle(m3Transform[2].x, m3Transform[2].y, 6.0f);
		pRenderer->setRenderColour(0xFFFFFFFF);
	}
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
	m_fCurrentMaxSpeed = fMaxSpeed;
}

float Agent::GetMaxSpeed()
{
	return m_fCurrentMaxSpeed;
}