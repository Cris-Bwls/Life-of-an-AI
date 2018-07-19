#pragma once
#include <map>
#include <memory>
#include "Renderer2D.h"

class Agent;
class BaseFSMState;
class Terrain;

class BaseFSM
{
public:
	BaseFSM(Agent* pAgent, Terrain* pTerrain);
	virtual ~BaseFSM();

	virtual void AddState(char* stateName);
	void ChangeState(char* stateName);

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

protected:
	Agent* m_pAgent;
	Terrain* m_pTerrain;

	BaseFSMState* m_currentState;
	std::map<char*, std::unique_ptr<BaseFSMState>> m_StateMap;
};

