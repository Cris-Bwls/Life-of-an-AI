#include "SteeringAlignment.h"

#include "Flocking.h"
#include "Agent.h"


SteeringAlignment::SteeringAlignment()
{
}


SteeringAlignment::~SteeringAlignment()
{
}

Vector2 SteeringAlignment::Update(Flocking* pFlocking, Agent* pAgent, float fDeltaTime)
{
	int nFlockSize = pFlocking->GetFlock().size();

	// Sum Velocities of flock
	Vector2 v2Sum = Vector2(0,0);
	for (int i = 0; i < nFlockSize; ++i)
	{
		v2Sum += pFlocking->GetFlock()[i].pAgent->GetVelocity();
	}
	// Average the sum
	Vector2 v2Avg = v2Sum * ((float)1 / (float)nFlockSize);

	// Subtract current velocity from average
	Vector2 result = v2Avg - pAgent->GetVelocity();

	// return result with weighting applied
	return result * m_fWeighting;
}
