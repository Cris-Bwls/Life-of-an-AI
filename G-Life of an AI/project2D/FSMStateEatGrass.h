#pragma once
#include "BaseFSMState.h"
class FSMStateEatGrass :
	public BaseFSMState
{
public:
	FSMStateEatGrass();
	~FSMStateEatGrass();

	void Update(float fDeltaTime);

private:
	float m_fStartTime;
	float m_fEatTime;
};

