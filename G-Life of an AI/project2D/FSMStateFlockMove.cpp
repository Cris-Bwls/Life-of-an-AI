#include "FSMStateFlockMove.h"
#include "BaseFSM.h"

#include "Agent.h"
#include "Flocking.h"
#include "Terrain.h"
#include "TerrainTile.h"
#include "TileQuadrant.h"

#define _USE_MATH_DEFINES
#include <math.h>

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
	Vector2 v2AgentPos = m_pAgent->GetPos();
	auto tile = m_pTerrain->GetTileByPos(v2AgentPos);
	auto quadrant = tile->GetAnimalAvoidQuadrant(tile->GetQuadrantFromPos(v2AgentPos));

	Vector2 v2FleeForce = quadrant->m_v2Vec * quadrant->m_nDistance;

	// Flocking Force
	Vector2 v2FlockingForce = m_pFlocking->Update(fDeltaTime);

	// Total Force
	Vector2 v2TotalForce = v2FleeForce + v2FlockingForce;

	// Make sure within Max Speed
	float fMag = v2TotalForce.normalise();
	if (fMag > m_pAgent->GetMaxSpeed())
		v2TotalForce * m_pAgent->GetMaxSpeed();
	else
		v2TotalForce * fMag;

	// Set Agent velocity
	v2TotalForce += m_pAgent->GetVelocity();
	m_pAgent->SetVelocity(v2TotalForce);

	// Set Agent rotation
	float m_fRotation = atan2f(v2TotalForce.y, v2TotalForce.x);
	m_fRotation -= M_PI_2;
	m_pAgent->SetRotation(m_fRotation);

	// Set Agent position
	Vector2 v2Pos = m_pAgent->GetPos();
	v2Pos += v2TotalForce * fDeltaTime;
	m_pAgent->SetPos(v2Pos);
}
