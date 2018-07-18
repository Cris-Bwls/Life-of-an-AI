#pragma once

enum EStaticObjectType
{
	/// ESTATICOBJECTTYPE_

	ESTATICOBJECTTYPE_DEFAULT = 0,
	
	// ResourceObjects
	/// ESTATICOBJECTTYPE_RESOURCE_OBJECT_

	ESTATICOBJECTTYPE_RESOURCE_OBJECT_GRASS,
	ESTATICOBJECTTYPE_RESOURCE_OBJECT_ROCK,
	ESTATICOBJECTTYPE_RESOURCE_OBJECT_TREE,

	// Buildings
	/// ESTATICOBJECTTYPE_BUILDING_

	ESTATICOBJECTTYPE_BUILDING_CONSTRUCTION,
	ESTATICOBJECTTYPE_BUILDING_CRAFTER,
	ESTATICOBJECTTYPE_BUILDING_FORGE,
	ESTATICOBJECTTYPE_BUILDING_STOCKPILE,

	// Buildings - Housing
	/// ESTATICOBJECTTYPE_BUILDING_HOUSING_

	ESTATICOBJECTTYPE_BUILDING_HOUSING_CABIN,
	ESTATICOBJECTTYPE_BUILDING_HOUSING_HUT,
	ESTATICOBJECTTYPE_BUILDING_HOUSING_TENT,

	ESTATICOBJECTTYPE_TOTAL
};