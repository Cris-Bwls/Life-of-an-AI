#include "FSMStateFindGrass.h"
#include "BaseFSM.h"
#include "Agent.h"
#include "Grass.h"


FSMStateFindGrass::FSMStateFindGrass()
{
}


FSMStateFindGrass::~FSMStateFindGrass()
{
}

void FSMStateFindGrass::Update(float fDeltaTime)
{
	m_pFSM->ChangeState("FSMStateFlockMove");
}
