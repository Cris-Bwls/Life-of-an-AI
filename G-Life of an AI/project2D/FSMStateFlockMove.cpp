#include "FSMStateFlockMove.h"
#include "BaseFSM.h"

#include "Agent.h"
#include "Flocking.h"
#include "Terrain.h"
#include "TerrainTile.h"
#include "TileQuadrant.h"

#define _USE_MATH_DEFINES
#include <math.h>

#include <iostream>

FSMStateFlockMove::FSMStateFlockMove(Terrain* pTerrain)
{
	m_pTerrain = pTerrain;

	m_pFlocking = nullptr;
}


FSMStateFlockMove::~FSMStateFlockMove()
{
	if (m_pFlocking)
		delete m_pFlocking;
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
	printf("Flocking x: %f, y: %f\n", v2FlockingForce.x, v2FlockingForce.y);

	// Total Force
	Vector2 v2TotalForce = v2FleeForce + v2FlockingForce;

	// Make sure within Max Speed
	float fMag = v2TotalForce.normalise();
	if (fMag > m_pAgent->GetMaxSpeed())
		v2TotalForce * m_pAgent->GetMaxSpeed();
	else
		v2TotalForce * fMag;

	// Determine new Agent velocity
	v2TotalForce += m_pAgent->GetVelocity();

	// Determine new Agent rotation
	float m_fRotation = atan2f(v2TotalForce.y, v2TotalForce.x);
	m_fRotation -= (float)M_PI_2;

	// Determine new Agent position
	Vector2 v2Pos = m_pAgent->GetPos();
	v2Pos += v2TotalForce * fDeltaTime;

	// Check if new position is valid
	TerrainTile* pTile = m_pTerrain->GetTileByPos(v2Pos);
	if (pTile)
	{
		// IF NOT blocked
		if (!pTile->GetBlocked())
		{
			// Set new velocity, rotation and position
			m_pAgent->SetVelocity(v2TotalForce);
			m_pAgent->SetRotation(m_fRotation);
			m_pAgent->SetPos(v2Pos);
		}
	}

}
