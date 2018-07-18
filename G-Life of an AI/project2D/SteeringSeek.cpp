#include "SteeringSeek.h"
#include "Input.h"
#include "Vector2.h"
#include "Agent.h"

SteeringSeek::SteeringSeek()
{
}


SteeringSeek::~SteeringSeek()
{
}

Vector2 SteeringSeek::Update(Agent* pAgent, float fDeltaTime)
{
	//auto input = aie::Input::getInstance();

	//Vector2 v2Dest;
	//v2Dest.x = input->getMouseX();
	//v2Dest.y = input->getMouseY();

	//Vector2 v2Dir = v2Dest - pAgent->GetPosition();
	//v2Dir.normalise();
	//v2Dir *= pAgent->GetMaxSpeed();

	//Vector2 v2Accel = v2Dir - pAgent->GetVelocity();

	//Vector2 v2Vel = v2Accel * fDeltaTime;

	//return v2Vel;

	return Vector2();
}