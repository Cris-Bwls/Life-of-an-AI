#pragma once

enum EGOAPSymbol
{
	// EGOAPSYMBOL_

	// DEFAULT
	EGOAPSYMBOL_DEFAULT = 0,

	// AI State
	EGOAPSYMBOL_FULL,
	EGOAPSYMBOL_WARM,
	EGOAPSYMBOL_RESTED,


	// Generic Symbols (currently unsupported)
	EGOAPSYMBOL_GEN_HAVE_RESOURCE,
	EGOAPSYMBOL_GEN_HAVE_TOOL,
	EGOAPSYMBOL_GEN_HAVE_WEAPON,
	EGOAPSYMBOL_GEN_AVAILABLE_RESOURCE,
	EGOAPSYMBOL_GEN_AVAILABLE_TOOL,
	EGOAPSYMBOL_GEN_AVAILABLE_WEAPON,
	EGOAPSYMBOL_GEN_OBJECT_EXISTS,
	EGOAPSYMBOL_GEN_OBJECT_ACTIVE,
	EGOAPSYMBOL_GEN_OBJECT_IN_RANGE,
	EGOAPSYMBOL_GEN_TARGET_EXISTS,
	EGOAPSYMBOL_GEN_TARGET_IN_RANGE,
	EGOAPSYMBOL_GEN_AT_POS,


	// Resource on AI
	EGOAPSYMBOL_HAVE_WOOD,
	EGOAPSYMBOL_HAVE_STONE,
	EGOAPSYMBOL_HAVE_IRON,
	EGOAPSYMBOL_HAVE_MEAT,
	EGOAPSYMBOL_HAVE_FOOD,

	// Resource in stockpile
	EGOAPSYMBOL_AVAILABLE_WOOD,
	EGOAPSYMBOL_AVAILABLE_STONE,
	EGOAPSYMBOL_AVAILABLE_IRON,
	EGOAPSYMBOL_AVAILABLE_MEAT,
	EGOAPSYMBOL_AVAILABLE_FOOD,

	// Tool on AI
	EGOAPSYMBOL_HAVE_TOOL,
	EGOAPSYMBOL_HAVE_STONE_TOOL,
	EGOAPSYMBOL_HAVE_IRON_TOOL,
	EGOAPSYMBOL_HAVE_WEAPON,

	// Tool at forge
	EGOAPSYMBOL_AVAILABLE_STONE_TOOL,
	EGOAPSYMBOL_AVAILABLE_IRON_TOOL,
	EGOAPSYMBOL_AVAILABLE_WEAPON,

	// Weapon type
	EGOAPSYMBOL_WEAPON_IS_RANGED,

	// Target exists
	EGOAPSYMBOL_TREE_EXISTS,
	EGOAPSYMBOL_ROCK_EXISTS,
	EGOAPSYMBOL_ENEMY_EXISTS,

	// Target in Range
	EGOAPSYMBOL_TARGET_IN_RANGE,

	// Object Exists
	EGOAPSYMBOL_EXISTS_FIRE,
	EGOAPSYMBOL_EXISTS_FORGE,
	EGOAPSYMBOL_EXISTS_CRAFTER,
	EGOAPSYMBOL_EXISTS_TENT,
	EGOAPSYMBOL_EXISTS_HUT,
	EGOAPSYMBOL_EXISTS_CABIN,

	// Object Active
	EGOAPSYMBOL_ACTIVE_FIRE,

	// TOTAL SYMBOLS
	EGOAPSYMBOL_TOTAL
};

// DataTypes
enum EDataType
{
	EDATATYPE_BOOL = 0,
	EDATATYPE_INT,
	EDATATYPE_HASH,
	EDATATYPE_POINTER,

	EDATATYPE_TOTAL
};

// Data Container
struct Data
{
	EDataType eDataType;

	union
	{
		bool bData;
		int nData;
		//float fData;
		void* pVoid;
	};
};

struct WorldStateProperty
{
	inline WorldStateProperty(EGOAPSymbol eSymbol = EGOAPSYMBOL_DEFAULT, bool bData = false)
			: eSymbol(eSymbol), bData(bData) {}

	EGOAPSymbol eSymbol;
	// Data data;
	bool bData = false;
};

struct WorldState
{
	WorldStateProperty WorldStateProperties[EGOAPSYMBOL_TOTAL];
};
