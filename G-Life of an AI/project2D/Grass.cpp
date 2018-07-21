#include "Grass.h"



Grass::Grass()
{
	m_bIsBlocker = false;

	m_nCharges = 5;
}


Grass::~Grass()
{
}


void Grass::Draw(aie::Renderer2D* pRenderer)
{
	Vector2 v2Pos = m3Transform.GetPosition();

	pRenderer->setRenderColour(0x1d963fFF);
	pRenderer->drawBox(v2Pos.x, v2Pos.y, 16.0f, 16.0f);
	pRenderer->setRenderColour(0xFFFFFFFF);
}