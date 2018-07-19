#include "Flocking.h"

#include "AgentManager.h"
#include "Agent.h"
#include "AI.h"
#include "Deer.h"
#include "SteeringAlignment.h"
#include "SteeringCohesion.h"
#include "SteeringSeperation.h"

#define FLOCKING_NEIGHBOUR_RADIUS 160.0f


Flocking::Flocking(Agent* pAgent)
{
	m_pAgent = pAgent;

	m_bAgentIsAI = false;
	m_bAgentIsDeer = false;

	// Determine Agent Type
	if (typeid(*pAgent).hash_code() == typeid(AI).hash_code())
		m_bAgentIsAI = true;
	else if (typeid(*pAgent).hash_code() == typeid(Deer).hash_code())
		m_bAgentIsDeer = true;

	//m_pSteeringAlignment = new SteeringAlignment();
	//m_pSteeringCohesion = new SteeringCohesion();
	//m_pSteeringSeperation = new SteeringSeperation();
}


Flocking::~Flocking()
{
	//delete m_pSteeringAlignment;
	//delete m_pSteeringCohesion;
	//delete m_pSteeringSeperation;
}

Vector2 Flocking::Update(float fDeltaTime)
{
	CalcFlock();
	m_pSteeringAlignment->Update(this, m_pAgent ,fDeltaTime);
	m_pSteeringCohesion->Update(this, m_pAgent, fDeltaTime);
	m_pSteeringSeperation->Update(this, m_pAgent, fDeltaTime);

	return Vector2();
}

void Flocking::CalcFlock()
{
	//Clear Previous Neighbours
	m_Flock.clear();

	// Calc New Neighbours
	auto pAgentManager = AgentManager::GetInstance();
	ObjectPool<AI>* pAIPool = pAgentManager->GetAIPool();
	ObjectPool<Deer>* pDeerPool = pAgentManager->GetDeerPool();

	// For AI type agents
	if (m_bAgentIsAI)
	{
		for (int i = 0; i < pAIPool->m_ActiveObjects.size(); ++i)
		{
			Vector2 v2NeighbourPos = pAIPool->m_ActiveObjects[i]->GetPos();
			Vector2 v2AgentPos = m_pAgent->GetPos();
			Vector2 v2Vector = v2NeighbourPos - v2AgentPos;
			float fMagnitude = v2Vector.magnitude();

			if (fMagnitude < FLOCKING_NEIGHBOUR_RADIUS)
			{
				Boid agentNeighbour;
				agentNeighbour.pAgent = pAIPool->m_ActiveObjects[i];
				agentNeighbour.fMagnitude = fMagnitude;

				m_Flock.push_back(agentNeighbour);
			}
		}
	}

	// For Deer type agents
	if (m_bAgentIsDeer)
	{
		for (int i = 0; i < pDeerPool->m_ActiveObjects.size(); ++i)
		{
			Vector2 v2NeighbourPos = pDeerPool->m_ActiveObjects[i]->GetPos();
			Vector2 v2AgentPos = m_pAgent->GetPos();
			Vector2 v2Vector = v2NeighbourPos - v2AgentPos;
			float fMagnitude = v2Vector.magnitude();

			if (fMagnitude < FLOCKING_NEIGHBOUR_RADIUS)
			{
				Boid agentNeighbour;
				agentNeighbour.pAgent = pDeerPool->m_ActiveObjects[i];
				agentNeighbour.fMagnitude = fMagnitude;

				m_Flock.push_back(agentNeighbour);
			}
		}
	}
}
