#pragma once
#include "Agent.h"

class BaseFSM;

class Deer :
	public Agent
{
public:
	Deer();
	~Deer();

	void Update(float fDeltaTime);
	void Draw(aie::Renderer2D* pRenderer);

	void SetTerrain(Terrain* pTerrain);

private:
	void SetupFSM();

	BaseFSM* m_FSM;
	//HERENOW
};

