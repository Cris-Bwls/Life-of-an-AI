#pragma once
#include "StaticObject.h"
class ResourceObject :
	public StaticObject
{
public:
	ResourceObject();
	virtual ~ResourceObject();

protected:
	int m_nCharges;
};

