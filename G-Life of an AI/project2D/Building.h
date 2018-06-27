#pragma once
#include "StaticObject.h"

class ResourceComponent;

class Building :
	public StaticObject
{
public:
	Building();
	virtual ~Building();

	ResourceComponent* GetBuildCost();
	float GetBuildTime();

protected:
	ResourceComponent* m_BuildCost;
	float m_fBuildTime = 0.0f;
};

