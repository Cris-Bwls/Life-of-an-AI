#include "BaseFSM.h"

#include "Agent.h"
#include "BaseFSMState.h"
#include "FSMStateAct.h"
#include "FSMStateEatGrass.h"
#include "FSMStateFindGrass.h"
#include "FSMStateFlockMove.h"
#include "FSMStateMove.h"
#include "Terrain.h"

BaseFSM::BaseFSM(Terrain* pTerrain)
{
	m_pTerrain = pTerrain;
}


BaseFSM::~BaseFSM()
{
}

void BaseFSM::AddState(char* stateName)
{
	if (stateName == "FSMStateAct")
		m_StateMap[stateName] = new FSMStateAct();
	else if (stateName == "FSMStateEatGrass")
		m_StateMap[stateName] = new FSMStateEatGrass();
	else if (stateName == "FSMStateFindGrass")
		m_StateMap[stateName] = new FSMStateFindGrass();
	else if (stateName == "FSMStateFlockMove")
		m_StateMap[stateName] = new FSMStateFlockMove(m_pTerrain);

	m_StateMap[stateName]->SetFSM(this);
	m_StateMap[stateName]->SetAgent(m_pAgent);
}

void BaseFSM::ChangeState(char* stateName)
{
	if (m_StateMap[stateName])
		m_currentState = m_StateMap[stateName];
	else
		m_StateMap.erase(stateName);
}

void BaseFSM::Update(float fDeltaTime)
{
	m_currentState->Update(fDeltaTime);
}

void BaseFSM::Draw(aie::Renderer2D * pRenderer)
{
	m_currentState->Draw(pRenderer);
}
