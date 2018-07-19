#include "Deer.h"
#include "BaseFSM.h"


Deer::Deer()
{
	m_FSM = nullptr;
}


Deer::~Deer()
{
	delete m_FSM;
}

void Deer::Update(float fDeltaTime)
{
	m_FSM->Update(fDeltaTime);
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
