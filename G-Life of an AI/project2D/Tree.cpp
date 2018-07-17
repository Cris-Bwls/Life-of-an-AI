#include "Tree.h"



Tree::Tree()
{
	m_bIsBlocker = true;
}


Tree::~Tree()
{
}

void Tree::Draw(aie::Renderer2D* pRenderer)
{
	Vector2 v2Pos = m3Transform.GetPosition();

	pRenderer->setRenderColour(0xc4ff0eFF);
	pRenderer->drawCircle(v2Pos.x, v2Pos.y, 8.0f);
	pRenderer->setRenderColour(0xFFFFFFFF);
}