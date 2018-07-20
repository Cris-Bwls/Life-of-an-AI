#include "Flocking.h"

#include "AgentManager.h"
#include "Agent.h"
#include "AI.h"
#include "Deer.h"
#include "SteeringAlignment.h"
#include "SteeringCohesion.h"
#include "SteeringSeperation.h"

#include <iostream>

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

	m_pSteeringBehaviours[0] = new SteeringAlignment();
	m_pSteeringBehaviours[0]->m_fWeighting = 0.05f;

	m_pSteeringBehaviours[1] = new SteeringCohesion();
	m_pSteeringBehaviours[1]->m_fWeighting = 2.0f;

	m_pSteeringBehaviours[2] = new SteeringSeperation();
	m_pSteeringBehaviours[2]->m_fWeighting = 2.0f;
}


Flocking::~Flocking()
{
	delete m_pSteeringBehaviours[0];
	delete m_pSteeringBehaviours[1];
	delete m_pSteeringBehaviours[2];
}

Vector2 Flocking::Update(float fDeltaTime)
{
	//printf("Object\n");

	CalcFlock();

	Vector2 v2TotalVelocity;

	for (int i = 0; i < 3; ++i)
	{
		float fMagnitude = v2TotalVelocity.magnitude();
		float fRemaining = m_pAgent->GetMaxSpeed() - fMagnitude;

		if (fRemaining <= 0.0f)
		{
			break;
		}

		Vector2 v2Force;
		
		if (typeid(*m_pSteeringBehaviours[i]).hash_code() == typeid(SteeringAlignment).hash_code())
		{
			v2Force = ((SteeringAlignment*)m_pSteeringBehaviours[i])->Update(this, m_pAgent, fDeltaTime);
			//printf("SteeringAlignment: x: %f y: %f\n", v2Force.x, v2Force.y);
		}
		else if (typeid(*m_pSteeringBehaviours[i]).hash_code() == typeid(SteeringCohesion).hash_code())
		{
			v2Force = ((SteeringCohesion*)m_pSteeringBehaviours[i])->Update(this, m_pAgent, fDeltaTime);
			//printf("SteeringCohesion: x: %f y: %f\n", v2Force.x, v2Force.y);
		}
		else if (typeid(*m_pSteeringBehaviours[i]).hash_code() == typeid(SteeringSeperation).hash_code())
		{
			v2Force = ((SteeringSeperation*)m_pSteeringBehaviours[i])->Update(this, m_pAgent, fDeltaTime);
			//printf("SteeringSeperation: x: %f y: %f\n", v2Force.x, v2Force.y);
		}

		v2Force *= m_pSteeringBehaviours[i]->m_fWeighting;

		float fForceMag = v2Force.magnitude();
		if (fForceMag < fRemaining)
		{
			v2TotalVelocity += v2Force;
		}
		else
		{
			v2Force.normalise();
			v2Force *= fRemaining;

			v2TotalVelocity += v2Force;
		}
	}

	return v2TotalVelocity;
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
			if (pAIPool->m_ActiveObjects[i] == m_pAgent)
				continue;

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
	else if (m_bAgentIsDeer)
	{
		for (int i = 0; i < pDeerPool->m_ActiveObjects.size(); ++i)
		{
			if (pDeerPool->m_ActiveObjects[i] == m_pAgent)
				continue;

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
