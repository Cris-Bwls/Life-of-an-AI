#pragma once
#include "Component.h"
#include "EResourceType.h"

class ResourceComponent :
	public Component
{
public:
	ResourceComponent();
	~ResourceComponent();

	void Reset();

	int TakeAll(EResourceType eResourceType);
	int TakeAmount(EResourceType eResourceType, int nAmount);

	void GiveAmount(EResourceType eResourceType, int nAmount);

	void TransferAllResources(ResourceComponent* destination);

	//Variables
	int nWood;
	int nStone;
	int nIron;
	int nFood;
	int nMeat;
	int nVeg;
};

