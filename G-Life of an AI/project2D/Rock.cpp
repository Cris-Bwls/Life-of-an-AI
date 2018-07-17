#include "Rock.h"



Rock::Rock()
{
	m_bIsBlocker = true;
}


Rock::~Rock()
{
}

void Rock::Draw(aie::Renderer2D* pRenderer)
{
	Vector2 v2Pos = m3Transform.GetPosition();

	pRenderer->setRenderColour(0xb97a56FF);
	pRenderer->drawCircle(v2Pos.x, v2Pos.y, 8.0f);
	pRenderer->setRenderColour(0xFFFFFFFF);
}