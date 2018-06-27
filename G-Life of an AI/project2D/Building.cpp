#include "Building.h"
#include "ResourceComponent.h"



Building::Building()
{
	m_BuildCost = new ResourceComponent();
	m_bIsAlive = false;
}


Building::~Building()
{
	delete m_BuildCost;
}

ResourceComponent* Building::GetBuildCost()
{
	return m_BuildCost;
}

float Building::GetBuildTime()
{
	return m_fBuildTime;
}