#pragma once

#include "ObjectPool.h"
#include "Vector2.h"
#include "Renderer2D.h"

class Agent;
class AI;
class Deer;

class AgentManager
{
public:
	static void Create();
	static void Destroy();
	static AgentManager* GetInstance();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

	Agent* GetAgentByPos(Vector2 v2Pos, int fRadius = 0);

	AI* AddAI(Vector2 v2Pos);
	Deer* AddDeer(Vector2 v2Pos);

	inline ObjectPool<AI>* GetAIPool() { return m_pAIPool; };
	inline ObjectPool<Deer>* GetDeerPool() { return m_pDeerPool; };
private:
	AgentManager();
	~AgentManager();

	static AgentManager* m_pInstance;

	ObjectPool<AI>*	 m_pAIPool;
	ObjectPool<Deer>*	m_pDeerPool;
};

