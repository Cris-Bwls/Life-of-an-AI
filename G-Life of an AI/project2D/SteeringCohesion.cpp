#include "SteeringCohesion.h"

#include "SteeringSeek.h"
#include "Flocking.h"
#include "Agent.h"

#include <iostream>

SteeringCohesion::SteeringCohesion()
{
	m_pSeek = new SteeringSeek();
}


SteeringCohesion::~SteeringCohesion()
{
	delete m_pSeek;
}

Vector2 SteeringCohesion::Update(Flocking* pFlocking, Agent* pAgent, float fDeltaTime)
{
	int nFlockSize = pFlocking->GetFlock().size();
	
	if (nFlockSize == 0)
		return Vector2();

	Vector2 v2sum;
	// Sum Positions of flock
	Vector2 v2Sum = Vector2(0, 0);
	for (int i = 0; i < nFlockSize; ++i)
	{
		Vector2 v2BoidPos = pFlocking->GetFlock()[i].pAgent->GetPos();

		Vector2 v2Dist = v2BoidPos - pAgent->GetPos();
		float fDistMag = v2Dist.magnitude();

		float fNormalisedMag = 0.0f; //(FLOCKING_NEIGHBOUR_RADIUS - fDistMag) * (1.0f / FLOCKING_NEIGHBOUR_RADIUS);

		v2Sum += v2BoidPos * (1.0f - fNormalisedMag);
	}
	// Average the sum
	Vector2 v2Avg = v2Sum * ((float)1 / (float)nFlockSize);
	
	// SEEK to average Position
	Vector2 result = v2Avg - pAgent->GetPos();

	// Normalise result
	result.normalise();

	// return result with weighting applied
	return result * m_fWeighting;
}
