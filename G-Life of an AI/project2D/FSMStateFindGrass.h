#pragma once
#include "BaseFSMState.h"
class FSMStateFindGrass :
	public BaseFSMState
{
public:
	FSMStateFindGrass();
	~FSMStateFindGrass();

	void Update(float fDeltaTime);
};

