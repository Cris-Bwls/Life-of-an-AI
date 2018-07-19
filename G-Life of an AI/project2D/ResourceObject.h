#pragma once
#include "StaticObject.h"
class ResourceObject :
	public StaticObject
{
public:
	ResourceObject();
	virtual ~ResourceObject();

	inline int ChangeCharges(int nChargeChange) { m_nCharges += nChargeChange; };
	inline int GetCharges() { return m_nCharges; };

protected:
	int m_nCharges;
};

