#include "ResourceComponent.h"



ResourceComponent::ResourceComponent()
{
	Reset();
}


ResourceComponent::~ResourceComponent()
{
}

//--------------------------------------------------------
// Reset
//		Resets Variables to '0'
//--------------------------------------------------------
void ResourceComponent::Reset()
{
	nWood = 0;
	nStone = 0;
	nIron = 0;
	nFood = 0;
	nMeat = 0;
	nVeg = 0;
}

//--------------------------------------------------------
// TakeAll
//		Takes all of specified resource from component
//
//		return (int):
//			amount of resource that was in component
//--------------------------------------------------------
int ResourceComponent::TakeAll(EResourceType eResourceType)
{
	int result;
	switch (eResourceType)
	{
	case ERESOURCETYPE_WOOD:
		result = nWood;
		nWood = 0;

		break;
	case ERESOURCETYPE_STONE:
		result = nStone;
		nStone = 0;

		break;
	case ERESOURCETYPE_IRON:
		result = nIron;
		nIron = 0;

		break;
	case ERESOURCETYPE_FOOD:
		result = nFood;
		nFood = 0;

		break;
	case ERESOURCETYPE_MEAT:
		result = nMeat;
		nMeat = 0;

		break;
	case ERESOURCETYPE_VEG:
		result = nVeg;
		nVeg = 0;

		break;
	case ERESOURCETYPE_TOTAL:
		break;

	default:
		break;
	}

	return result;
}

//--------------------------------------------------------
// TakeAmount
//		Takes specified amount of specified resource from component
//		if able otherwise takes as much as able
//
//		return (int):
//			amount of resource that was successfully taken
//--------------------------------------------------------
int ResourceComponent::TakeAmount(EResourceType eResourceType, int nAmount)
{
	int result;
	switch (eResourceType)
	{
	case ERESOURCETYPE_WOOD:
		if (nWood > nAmount)
		{
			result = nAmount;
			nWood -= nAmount;
		}
		else
		{
		result = nWood;
		nWood = 0;
		}

		break;
	case ERESOURCETYPE_STONE:
		if (nStone > nAmount)
		{
			result = nAmount;
			nStone -= nAmount;
		}
		else
		{
			result = nStone;
			nStone = 0;
		}

		break;
	case ERESOURCETYPE_IRON:
		if (nIron > nAmount)
		{
			result = nAmount;
			nIron -= nAmount;
		}
		else
		{
			result = nIron;
			nIron = 0;
		}

		break;
	case ERESOURCETYPE_FOOD:
		if (nFood > nAmount)
		{
			result = nAmount;
			nFood -= nAmount;
		}
		else
		{
			result = nFood;
			nFood = 0;
		}

		break;
	case ERESOURCETYPE_MEAT:
		if (nMeat > nAmount)
		{
			result = nAmount;
			nMeat -= nAmount;
		}
		else
		{
			result = nMeat;
			nMeat = 0;
		}

		break;
	case ERESOURCETYPE_VEG:
		if (nVeg > nAmount)
		{
			result = nAmount;
			nVeg -= nAmount;
		}
		else
		{
			result = nVeg;
			nVeg = 0;
		}

		break;
	case ERESOURCETYPE_TOTAL:
		break;

	default:
		break;
	}

	return result;
}

//--------------------------------------------------------
// GiveAmount
//		Gives specified amount of specified resource
//		to component
//--------------------------------------------------------
void ResourceComponent::GiveAmount(EResourceType eResourceType, int nAmount)
{
	switch (eResourceType)
	{
	case ERESOURCETYPE_WOOD:
		nWood += nAmount;

		break;
	case ERESOURCETYPE_STONE:
		nStone += nAmount;

		break;
	case ERESOURCETYPE_IRON:
		nIron += nAmount;

		break;
	case ERESOURCETYPE_FOOD:
		nFood += nAmount;

		break;
	case ERESOURCETYPE_MEAT:
		nMeat += nAmount;

		break;
	case ERESOURCETYPE_VEG:
		nVeg += nAmount;

		break;
	case ERESOURCETYPE_TOTAL:
		break;

	default:
		break;
	}
}

//--------------------------------------------------------
// TransferAllResources
//		Transfers all resources in current component to 
//		'destination' component, then resets current component
//--------------------------------------------------------
void ResourceComponent::TransferAllResources(ResourceComponent* destination)
{
	destination->nFood	+= nFood;
	destination->nStone += nStone;
	destination->nIron	+= nIron;
	destination->nFood	+= nFood;
	destination->nMeat	+= nMeat;
	destination->nVeg	+= nVeg;

	this->Reset();
}