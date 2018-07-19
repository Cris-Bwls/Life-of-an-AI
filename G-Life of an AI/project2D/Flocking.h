#pragma once

#include<vector>
#include"Vector2.h"

class Agent;
class SteeringAlignment;
class SteeringCohesion;
class SteeringSeperation;

struct Boid
{
	Agent* pAgent;
	float fMagnitude;
};

class Flocking
{
public:
	Flocking(Agent* pAgent);
	~Flocking();

	Vector2 Update(float fDeltaTime);

	void CalcFlock();
	inline std::vector<Boid> GetFlock() { return m_Flock; };
private:
	Agent* m_pAgent;

	bool m_bAgentIsAI;
	bool m_bAgentIsDeer;

	SteeringAlignment*	m_pSteeringAlignment;
	SteeringCohesion*	m_pSteeringCohesion;
	SteeringSeperation* m_pSteeringSeperation;

	std::vector<Boid> m_Flock;
};

