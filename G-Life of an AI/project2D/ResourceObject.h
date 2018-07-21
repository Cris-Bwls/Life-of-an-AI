#pragma once
#include "StaticObject.h"
class ResourceObject :
	public StaticObject
{
public:
	ResourceObject();
	virtual ~ResourceObject();

	void ChangeCharges(int nChargeChange);
	inline int GetCharges() { return m_nCharges; };

protected:
	int m_nCharges;
};

