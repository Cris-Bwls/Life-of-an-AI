#include "GOAPActionBase.h"



GOAPActionBase::GOAPActionBase()
{
	m_Status = EACTIONSTATUS_INACTIVE;
	m_fBaseCost = 1.0f;
	m_fRunningCost = 1.0f;
}


GOAPActionBase::~GOAPActionBase()
{
}

void GOAPActionBase::Start()
{
	m_Status = EACTIONSTATUS_ACTIVE;
}

void GOAPActionBase::Run(float fDeltaTime)
{
	if (m_Status != EACTIONSTATUS_ACTIVE)
		Start();
}

void GOAPActionBase::Finish()
{
	m_Status = EACTIONSTATUS_DONE;
}

inline void GOAPActionBase::Reset()
{
	HowGoodIsThisGOAP();

	m_Status = EACTIONSTATUS_INACTIVE;
	ResetRunningCost();
}
