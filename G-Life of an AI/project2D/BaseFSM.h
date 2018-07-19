#pragma once
#include <map>
#include "Renderer2D.h"

class Agent;
class BaseFSMState;

class BaseFSM
{
public:
	BaseFSM();
	virtual ~BaseFSM();

	virtual void AddState(char* stateName);
	void ChangeState(char* stateName);

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

private:
	Agent* m_pAgent;

	BaseFSMState* m_currentState;
	std::map<char*, BaseFSMState*> m_StateMap;
};

