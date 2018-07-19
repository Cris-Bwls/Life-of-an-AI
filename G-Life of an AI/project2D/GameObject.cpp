#include "GameObject.h"



GameObject::GameObject()
{
	m_pTexture = nullptr;
}


GameObject::~GameObject()
{
}

void GameObject::Reset()
{
	m_bIsAlive = false;
	m3Transform.Identity();
	SetPos(Vector2((float)0xFFFFFFFF, (float)0xFFFFFFFF));
	m_fRotation = 0.0f;
}
