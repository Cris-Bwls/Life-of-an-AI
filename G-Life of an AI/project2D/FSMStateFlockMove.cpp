#include "FSMStateFlockMove.h"
#include "BaseFSM.h"

#include "Agent.h"
#include "Flocking.h"
#include "Terrain.h"
#include "TerrainTile.h"
#include "TileQuadrant.h"
#include "SteeringWander.h"

#define _USE_MATH_DEFINES
#include <math.h>

FSMStateFlockMove::FSMStateFlockMove(Terrain* pTerrain)
{
	m_pTerrain = pTerrain;

	m_pFlocking = nullptr;

	m_pWander = new SteeringWander(10.0f, 20.0f, 3.0f);
	m_pWander->m_fWeighting = 1.0f;
}


FSMStateFlockMove::~FSMStateFlockMove()
{
	if (m_pFlocking)
		delete m_pFlocking;

	delete m_pWander;
}

void FSMStateFlockMove::Update(float fDeltaTime)
{
	// Flocking Creation if nullptr
	if (!m_pFlocking)
		m_pFlocking = new Flocking(m_pAgent);

	// Flee Force
	Vector2 v2FleeForce;
	{
		Vector2 v2AgentPos = m_pAgent->GetPos();
		auto pTile = m_pTerrain->GetTileByPos(v2AgentPos);

		TileQuadrant* pQuadrant;
		if (pTile)
		{
			pQuadrant = pTile->GetAnimalAvoidQuadrant(pTile->GetQuadrantFromPos(v2AgentPos));
			v2FleeForce = pQuadrant->m_v2Vec * (float)pQuadrant->m_nDistance * 0.1f;
		}
		else
		{
			v2FleeForce = Vector2();
		}
	}

	// Flocking Force
	Vector2 v2FlockingForce = m_pFlocking->Update(fDeltaTime);

	// Wander Force
	Vector2 v2WanderForce = m_pWander->Update(m_pAgent, fDeltaTime);

	// Total Force
	Vector2 v2TotalForce = v2FleeForce + v2FlockingForce + v2WanderForce;

	//DEBUG
	//printf("v2FleeForce: x: %f y: %f\n", v2FleeForce.x, v2FleeForce.y);
	//printf("v2FlockingForce: x: %f y: %f\n", v2FlockingForce.x, v2FlockingForce.y);
	//printf("v2WanderForce: x: %f y: %f\n", v2WanderForce.x, v2WanderForce.y);
	//printf("v2TotalForce: x: %f y: %f\n", v2TotalForce.x, v2TotalForce.y);

	// Make sure within Max Speed
	float fMag = v2TotalForce.normalise();
	if (fMag > m_pAgent->GetMaxSpeed())
		v2TotalForce *= m_pAgent->GetMaxSpeed();
	else
		v2TotalForce *= fMag;

	// Determine new Agent velocity
	v2TotalForce += m_pAgent->GetVelocity();

	// Determine new Agent rotation
	float fRotation = atan2f(v2TotalForce.y, v2TotalForce.x);
	fRotation -= (float)M_PI_2;

	// Determine new Agent position
	Vector2 v2Pos = m_pAgent->GetPos();
	v2Pos += v2TotalForce * fDeltaTime;

	// Check if new position is valid
	bool bValidPath = false;
	Vector2 v2NewForce = v2TotalForce;
	Vector2 v2NewPos = v2Pos;
	float fNewRotation = fRotation;

	float fLeftRot = fRotation;
	float fRightRot = fRotation;
	
	// Initial Check
	TerrainTile* pTile = m_pTerrain->GetTileByPos(v2Pos);
	if (pTile)
	{
		// IF NOT blocked
		if (!pTile->GetBlocked())
		{
			bValidPath = true;
		}
	}
	int nCount = 0;
	while (!bValidPath)
	{
		// Check Left
		fLeftRot -= (float)M_PI_4;

		v2NewForce = v2TotalForce;
		v2NewForce *= fLeftRot;
		v2NewPos = m_pAgent->GetPos() + v2NewForce * fDeltaTime;

		// Make sure within Max Speed
		fMag = v2NewForce.normalise();
		if (fMag > m_pAgent->GetMaxSpeed())
			v2NewForce *= m_pAgent->GetMaxSpeed();
		else
			v2NewForce *= fMag;

		pTile = m_pTerrain->GetTileByPos(v2NewPos);
		if (pTile)
		{
			// IF NOT blocked
			if (!pTile->GetBlocked())
			{
				fNewRotation = fLeftRot;

				bValidPath = true;
				continue;
			}
		}

		// Check Right
		fRightRot += (float)M_PI_4;

		v2NewForce = v2TotalForce;
		v2NewForce *= fRightRot;
		v2NewPos = m_pAgent->GetPos() + v2NewForce * fDeltaTime;

		// Make sure within Max Speed
		fMag = v2NewForce.normalise();
		if (fMag > m_pAgent->GetMaxSpeed())
			v2NewForce *= m_pAgent->GetMaxSpeed();
		else
			v2NewForce *= fMag;

		pTile = m_pTerrain->GetTileByPos(v2NewPos);
		if (pTile)
		{
			// IF NOT blocked
			if (!pTile->GetBlocked())
			{
				fNewRotation = fRightRot;

				bValidPath = true;
				continue;
			}
		}
		nCount++;
		if (nCount > 8)
			return;
	}

	// Set new velocity, rotation and position
	m_pAgent->SetVelocity(v2NewForce);
	m_pAgent->SetRotation(fNewRotation);
	m_pAgent->SetPos(v2NewPos);

	if (m_pAgent->GetHunger() > 65)
		m_pFSM->ChangeState("FSMStateFindGrass");
}
