#pragma once
#include "GameObject.h"
#include <vector>
#include "SteeringSeek.h"


class Terrain;

class Agent :
	public GameObject
{
public:
	Agent();
	virtual ~Agent();

	virtual void Update(float fDeltaTime) {};
	virtual void Draw(aie::Renderer2D* pRenderer);

	void HungerCheck();

	void SetVelocity(Vector2 v2Velocity);
	Vector2 GetVelocity();

	void SetMaxSpeed(float fMaxSpeed);
	float GetMaxSpeed();

	inline void ChangeHunger(int nHungerChange) { m_nHunger += nHungerChange; };
	inline int GetHunger() { return m_nHunger; };

	inline void SetTarget(GameObject* pTarget) { m_pTarget = pTarget; };
	inline GameObject* GetTarget() { return m_pTarget; };

	inline void SetTargetPos(Vector2 targetPos) { m_TargetPos = targetPos; };
	inline Vector2* GetTargetPos() { return &m_TargetPos; };

	inline void SetPath(std::vector<Vector2> path) { m_Path = path; };
	inline std::vector<Vector2>* GetPath() { return &m_Path; };

	virtual inline void SetTerrain(Terrain* pTerrain) { m_pTerrain = pTerrain; };
protected:
	Terrain* m_pTerrain;

	Vector2 m_v2Velocity;
	float m_fCurrentMaxSpeed;
	float m_fMaxSpeed;
	float m_fHungrySpeed;

	int m_nHunger;

	GameObject* m_pTarget;
	Vector2 m_TargetPos;
	std::vector<Vector2> m_Path;
};

