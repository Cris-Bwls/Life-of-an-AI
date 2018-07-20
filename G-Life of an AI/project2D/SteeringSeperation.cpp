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

	if (nFlockSize == 0)
		return Vector2();

	Vector2 v2AgentPos = pAgent->GetPos();

	// Sum Force of flock
	Vector2 v2Sum = Vector2(0, 0);
	for (int i = 0; i < nFlockSize; ++i)
	{
		// Get Boid Position
		Vector2 v2BoidPos = pFlocking->GetFlock()[i].pAgent->GetPos();

		// Add Force Between Boid Pos and Agent Pos to Sum
		Vector2 v2Force = v2BoidPos - v2AgentPos;
		float fForceMag = v2Force.magnitude();

		float fNormalisedMag = (FLOCKING_NEIGHBOUR_RADIUS - fForceMag) * (1.0f / FLOCKING_NEIGHBOUR_RADIUS);
		v2Sum += v2Force * (fNormalisedMag - 0.5f) * 3.5f;
	}
	// Average the sum
	Vector2 v2Avg = v2Sum * (1.0f / (float)nFlockSize);

	// Invert and normalise avg
	Vector2 v2Result = v2Avg * -1;
	v2Result.normalise();

	// return result with weighting applied
	return v2Result * m_fWeighting;
}
