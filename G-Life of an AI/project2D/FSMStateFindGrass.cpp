#include "FSMStateFindGrass.h"
#include "BaseFSM.h"
#include "Agent.h"
#include "Grass.h"
#include "StaticObjectManager.h"
#include "Terrain.h"
#include "TerrainTile.h"
#include "SteeringSeek.h"
#include "TimeManager.h"

#define _USE_MATH_DEFINES
#include <math.h>

#define TIME_OUT_DURATION 5000.0f //1 second is 1000.0f

FSMStateFindGrass::FSMStateFindGrass(Terrain* pTerrain)
{
	m_pSeek = new SteeringSeek();
	m_pTerrain = pTerrain;

	m_bHavePathToGrass = false;
	m_nAttemptCount = 0;
	m_fTimeOutStart = 0.0f;
}


FSMStateFindGrass::~FSMStateFindGrass()
{
	delete m_pSeek;
}

void FSMStateFindGrass::Update(float fDeltaTime)
{
	// IF High Attempt Count
	if (m_nAttemptCount > 5)
	{
		float fGameTime = TimeManager::GetInstance()->GetGameTime();

		// IF Time out is over
		if (m_fTimeOutStart + TIME_OUT_DURATION < fGameTime)
		{
			m_fTimeOutStart = fGameTime;
			m_pFSM->ChangeState("FSMStateFlockMove");
			return;
		}
		// ELSE reset attempts
		else
			m_nAttemptCount = 0;
	}

	// If NO Path
	if (!m_bHavePathToGrass)
	{
		// Increment attempt count
		++m_nAttemptCount;

		// Clear Previous existing Path
		m_Path.clear();

		// Try to make a path
		Vector2 agentPos = m_pAgent->GetPos();
		m_pTarget = nullptr;
		Vector2 v2TargetPos;
		auto grassActiveList = StaticObjectManager::GetInstance()->GetGrassActiveList();
		
		auto listSize = grassActiveList.size();
		if (listSize > 0)
		{
			m_pTarget = grassActiveList[0];
			v2TargetPos = m_pTarget->GetPos();
		}

		for (unsigned int i = 1; i < listSize; ++i)
		{
			Vector2 currentPos = grassActiveList[i]->GetPos();

			if (Vector2(v2TargetPos - agentPos).magnitudeSqr() > Vector2(currentPos - agentPos).magnitudeSqr())
			{
				m_pTarget = grassActiveList[i];
				v2TargetPos = currentPos;
			}
		}

		if (m_pTarget)
		{
			m_Path = m_pTerrain->GetPathToObject(agentPos, m_pTarget, false);
			if (m_Path.size() > 0)
				m_bHavePathToGrass = true;
		}
	}

	// IF Path
	if (m_bHavePathToGrass)
	{

		// IF at next path position (close enough)
		if (Vector2(m_Path.front() - m_pAgent->GetPos()).magnitudeSqr() < 16.0f)
		{
			m_Path.erase(m_Path.begin());

			if (m_Path.size() == 0)
			{
				m_bHavePathToGrass = false;
			}
		}


		// IF Target Position IS blocked
		if (m_bHavePathToGrass)
			if (m_pTerrain->GetTileByPos(m_Path.front())->GetBlocked())
				m_bHavePathToGrass = false; // Rebuild Path
		// ELSE
		else
		{
			// seek to target pos
			Vector2 v2velocity = m_pSeek->Update(m_pAgent, fDeltaTime, m_Path.front());
			v2velocity += m_pAgent->GetVelocity();

			// Make sure within Max Speed
			float fMag = v2velocity.normalise();
			if (fMag > m_pAgent->GetMaxSpeed())
				v2velocity *= m_pAgent->GetMaxSpeed();
			else
				v2velocity *= fMag;

			// Determine new Agent rotation
			float fRotation = atan2f(v2velocity.y, v2velocity.x);
			fRotation -= (float)M_PI_2;

			// Determine new Agent position
			Vector2 v2Pos = m_pAgent->GetPos();
			v2Pos += v2velocity * fDeltaTime;

			// Set Agents vel, pos, rot
			m_pAgent->SetVelocity(v2velocity);
			m_pAgent->SetPos(v2Pos);
			m_pAgent->SetRotation(fRotation);
		}

		if (Vector2(m_pTarget->GetPos() - m_pAgent->GetPos()).magnitudeSqr() < 16.0f)
		{
			m_pFSM->ChangeState("FSMStateEatGrass");
			m_nAttemptCount = 0;
			m_fTimeOutStart = 0.0f;
			m_bHavePathToGrass = false;

			m_pAgent->SetTarget(m_pTarget);
		}
	}
}
