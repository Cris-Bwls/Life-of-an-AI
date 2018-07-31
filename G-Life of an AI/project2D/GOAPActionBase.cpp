#include "GOAPActionBase.h"
#include "Agent.h"
#include "Terrain.h"
#include "StaticObject.h"

GOAPActionBase::GOAPActionBase(Agent* pAgent, Terrain* pTerrain)
{
	m_pAgent = pAgent; 
	m_pTerrain = pTerrain;

	m_bUsed = false;
	m_nCost = 10;

	m_nFScore = 0;
	m_nGScore = 0;
	m_nHScore = 0;
}


GOAPActionBase::~GOAPActionBase()
{
}

bool GOAPActionBase::CheckProceduralPreconditions()
{
	return true;
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

bool GOAPActionBase::Act()
{
	return false;
}

bool GOAPActionBase::Move()
{
	return false;
}

bool GOAPActionBase::MoveToPos()
{
	auto targetPos = m_pAgent->GetTargetPos();
	auto path = m_pTerrain->GetPathToPos(m_pAgent->GetPos(), *targetPos, true);
	m_pAgent->SetPath(path);
	
	if (path.size() == 0)
		return false;
	return true;

}

bool GOAPActionBase::MoveToObject()
{
	auto target = m_pAgent->GetTarget();
	auto path = m_pTerrain->GetPathToObject(m_pAgent->GetPos(), (StaticObject*)target, false);
	m_pAgent->SetPath(path);

	if (path.size() == 0)
		return false;
	return true;
}

inline void GOAPActionBase::Reset()
{
	m_Status = EACTIONSTATUS_INACTIVE;
}
