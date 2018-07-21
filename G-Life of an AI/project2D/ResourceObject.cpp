#include "ResourceObject.h"



ResourceObject::ResourceObject()
{
}


ResourceObject::~ResourceObject()
{
}

void ResourceObject::ChangeCharges(int nChargeChange)
{
	m_nCharges += nChargeChange;

	if (m_nCharges < 1)
		m_bIsAlive = false;
}
