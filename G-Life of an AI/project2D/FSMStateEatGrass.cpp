#include "FSMStateEatGrass.h"
#include "BaseFSM.h"
#include "Agent.h"
#include "Grass.h"
#include "TimeManager.h"


FSMStateEatGrass::FSMStateEatGrass()
{
	m_fStartTime = 0.0f;
	m_fEatTime = 5000.0f; // 1 second = 1000.0
}


FSMStateEatGrass::~FSMStateEatGrass()
{
}

void FSMStateEatGrass::Update(float fDeltaTime)
{
	float fGameTime = TimeManager::GetInstance()->GetGameTime();

	if (m_fStartTime + m_fEatTime < fGameTime)
	{
		bool bTargetExists = false;
		if (m_pAgent->GetTarget())
			bTargetExists = true;

		if (((Grass*)m_pAgent->GetTarget())->GetCharges() > 0 && bTargetExists)
		{
			m_fStartTime = fGameTime;
			((Grass*)m_pAgent->GetTarget())->ChangeCharges(-1);
			m_pAgent->ChangeHunger(-20);
		}
		else
		{
			m_pAgent->SetTarget(nullptr);
			if (m_pAgent->GetHunger() > 65)
				m_pFSM->ChangeState("FSMStateFindGrass");
			else
				m_pFSM->ChangeState("FSMStateFlockMove");
		}
	}
}
