#include "SteeringSeperation.h"

#include "Flocking.h"
#include "Agent.h"


SteeringSeperation::SteeringSeperation()
{
}


SteeringSeperation::~SteeringSeperation()
{
}

Vector2 SteeringSeperation::Update(Flocking* pFlocking, Agent* pAgent, float fDeltaTime)
{
	int nFlockSize = pFlocking->GetFlock().size();
	Vector2 v2AgentPos = pAgent->GetPos();


	// Sum Force of flock
	Vector2 v2Sum = Vector2(0, 0);
	for (int i = 0; i < nFlockSize; ++i)
	{
		// Get Boid Position
		Vector2 v2BoidPos = pFlocking->GetFlock()[i].pAgent->GetPos();

		// Add Force Between Boid Pos and Agent Pos to Sum
		v2Sum += (v2BoidPos - v2AgentPos);
	}
	// Average the sum
	Vector2 v2Avg = v2Sum * ((float)1 / (float)nFlockSize);

	// return average with weighting applied
	return v2Avg * m_fWeighting;
}
