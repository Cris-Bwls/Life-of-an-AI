#pragma once
#include "Building.h"
class Construction :
	public Building
{
public:
	Construction(Building* pNewBuilding, Vector2 pos);
	~Construction();

	ResourceComponent GetResourcesRequired();

	bool CheckCanBuild();
	bool GetCanBuild();

	void SetBuildTime(float fBuildTime);
	float GetBuildTime();

private:
	Building* m_pNewBuilding;
	ResourceComponent* m_pResources;

	bool m_bCanBuild;
};

