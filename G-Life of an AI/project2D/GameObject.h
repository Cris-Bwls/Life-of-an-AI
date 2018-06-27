#pragma once
#include "Matrix3.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

protected:
	Matrix3 m3Transform;
	bool	m_bIsAlive;

};

