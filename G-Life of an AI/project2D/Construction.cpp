#include "Construction.h"
#include "ResourceComponent.h"
#include "Vector2.h"


Construction::Construction(Building* pNewBuilding, Vector2 pos)
{
	m_bIsAlive = true;
	m3Transform.SetPosition(pos);

	m_fBuildTime = pNewBuilding->GetBuildTime();
	m_BuildCost = pNewBuilding->GetBuildCost();
	m_pNewBuilding = pNewBuilding;

	m_pResources = new ResourceComponent();

	m_bCanBuild = false;
}


Construction::~Construction()
{
	delete m_pResources;
}

ResourceComponent Construction::GetResourcesRequired()
{
	ResourceComponent result;
	result.nWood = m_BuildCost->nWood - m_pResources->nWood;
	result.nStone = m_BuildCost->nStone - m_pResources->nStone;
	result.nIron = m_BuildCost->nIron - m_pResources->nIron;
	result.nFood = m_BuildCost->nFood - m_pResources->nFood;
	result.nMeat = m_BuildCost->nMeat - m_pResources->nMeat;
	result.nVeg = m_BuildCost->nVeg - m_pResources->nVeg;

	return result;
}

bool Construction::CheckCanBuild()
{
	// If CanBuild == FALSE
	if (!m_bCanBuild)
	{
		// Find total required resources 
		ResourceComponent result;
		result.nWood = m_BuildCost->nWood - m_pResources->nWood;
		result.nStone = m_BuildCost->nStone - m_pResources->nStone;
		result.nIron = m_BuildCost->nIron - m_pResources->nIron;
		result.nFood = m_BuildCost->nFood - m_pResources->nFood;
		result.nMeat = m_BuildCost->nMeat - m_pResources->nMeat;
		result.nVeg = m_BuildCost->nVeg - m_pResources->nVeg;

		int nRemaining = result.nWood + result.nStone + result.nIron
			+ result.nFood + result.nMeat + result.nVeg;

		// If no required resources 
		if (nRemaining == 0)
		{
			m_bCanBuild = true;
		}
	}

	return m_bCanBuild;
}

bool Construction::GetCanBuild()
{
	return m_bCanBuild;
}

void Construction::SetBuildTime(float fBuildTime)
{
	m_fBuildTime = fBuildTime;
}

float Construction::GetBuildTime()
{
	return m_fBuildTime;
}
