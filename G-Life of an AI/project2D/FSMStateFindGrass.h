#pragma once
#include "BaseFSMState.h"
#include "Vector2.h"
#include <vector>

class Terrain;
class SteeringSeek;
class Grass;

class FSMStateFindGrass :
	public BaseFSMState
{
public:
	FSMStateFindGrass(Terrain* pTerrain);
	~FSMStateFindGrass();

	void Update(float fDeltaTime);

private:
	SteeringSeek* m_pSeek;

	Terrain* m_pTerrain;
	Grass* m_pTarget;
	
	bool m_bHavePathToGrass;
	int m_nAttemptCount;
	float m_fTimeOutStart;

	std::vector<Vector2> m_Path;
};

