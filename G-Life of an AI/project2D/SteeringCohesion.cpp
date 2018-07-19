#include "SteeringCohesion.h"

#include "SteeringSeek.h"
#include "Flocking.h"
#include "Agent.h"


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

	Vector2 v2sum;
	// Sum Positions of flock
	Vector2 v2Sum = Vector2(0, 0);
	for (int i = 0; i < nFlockSize; ++i)
	{
		v2Sum += pFlocking->GetFlock()[i].pAgent->GetPos();
	}
	// Average the sum
	Vector2 v2Avg = v2Sum * ((float)1 / (float)nFlockSize);
	
	// SEEK to average Position
	Vector2 result = m_pSeek->Update(pAgent, fDeltaTime, v2Avg);

	// return result with weighting applied
	return result * m_fWeighting;
}
