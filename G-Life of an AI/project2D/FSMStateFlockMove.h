#pragma once
#include "BaseFSMState.h"

class Flocking;
class Terrain;

class FSMStateFlockMove :
	public BaseFSMState
{
public:
	FSMStateFlockMove(Terrain* pTerrain);
	~FSMStateFlockMove();

	void Update(float fDeltaTime);

private:
	Terrain* m_pTerrain;
	Flocking* m_pFlocking;
};

