#pragma once

#include<vector>
#include"Vector2.h"

class Agent;
class SteeringBase;

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
	
	SteeringBase* m_pSteeringBehaviours[3];

	std::vector<Boid> m_Flock;
};

