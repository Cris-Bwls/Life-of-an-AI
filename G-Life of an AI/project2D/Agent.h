#pragma once
#include "GameObject.h"
class Agent :
	public GameObject
{
public:
	Agent();
	virtual ~Agent();

	virtual void Update(float fDeltaTime);
	virtual void Draw(aie::Renderer2D* pRenderer);

	void SetVelocity(Vector2 v2Velocity);
	Vector2 GetVelocity();

	void SetMaxSpeed(float fMaxSpeed);
	float GetMaxSpeed();

protected:
	Vector2 m_v2Velocity;
	float m_fMaxSpeed;
};

