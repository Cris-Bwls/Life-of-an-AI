#include "GameObject.h"



GameObject::GameObject()
{
}


GameObject::~GameObject()
{
}

void GameObject::Reset()
{
	m_bIsAlive = false;
	m3Transform.Identity();
	SetPos(Vector2(0xFFFFFFFF, 0xFFFFFFFF));
	m_fRot = 0.0f;
}
