#include "Deer.h"
#include "BaseFSM.h"
#include "TimeManager.h"

#define HUNGER_TIMER 1.0f

Deer::Deer()
{
	m_FSM = nullptr;
	m_fGameTime = 0.0f;
	m_nHunger = 65;
}


Deer::~Deer()
{
	delete m_FSM;
}

void Deer::Update(float fDeltaTime)
{
	m_FSM->Update(fDeltaTime);
	float fGameTime = TimeManager::GetInstance()->GetGameTime();
	if (m_fGameTime + HUNGER_TIMER < fGameTime)
	{
		++m_nHunger;
		m_fGameTime = fGameTime;
	}
}

void Deer::Draw(aie::Renderer2D * pRenderer)
{
	Agent::Draw(pRenderer);
}

void Deer::SetTerrain(Terrain* pTerrain)
{
	if (!m_pTerrain)
	{
		m_pTerrain = pTerrain;
		SetupFSM();
	}
}

void Deer::SetupFSM()
{
	if (!m_FSM)
	{
		m_FSM = new BaseFSM(this, m_pTerrain);
		m_FSM->AddState("FSMStateFlockMove");
		m_FSM->AddState("FSMStateEatGrass");
		m_FSM->AddState("FSMStateFindGrass");

		m_FSM->ChangeState("FSMStateFlockMove");
	}

}
