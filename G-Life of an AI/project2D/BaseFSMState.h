#pragma once
#include "Renderer2D.h"

class Agent;
class BaseFSM;

class BaseFSMState
{
public:
	BaseFSMState();
	virtual ~BaseFSMState();

	virtual void Update(float fDeltaTime) {};
	virtual void Draw(aie::Renderer2D* pRenderer) {};

	inline void SetFSM(BaseFSM* pFSM) { m_pFSM = pFSM; };
	inline void SetAgent(Agent* pAgent) { m_pAgent = pAgent; };

private:
	BaseFSM* m_pFSM;
	Agent* m_pAgent;
};

