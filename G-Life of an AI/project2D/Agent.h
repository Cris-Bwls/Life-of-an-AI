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

	inline void ChangeHunger(int nHungerChange) { m_nHunger += nHungerChange; };
	inline int GetHunger() { return m_nHunger; };

	inline void SetTarget(GameObject* pTarget) { m_pTarget = pTarget; };
	inline GameObject* GetTarget() { return m_pTarget; };

protected:
	Vector2 m_v2Velocity;
	float m_fCurrentMaxSpeed;
	float m_fMaxSpeed;
	float m_fHungrySpeed;

	int m_nHunger;
	GameObject* m_pTarget;
};

