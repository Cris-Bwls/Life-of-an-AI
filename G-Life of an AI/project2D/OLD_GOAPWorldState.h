#pragma once

enum OLD_EGOAPSymbols
{
	// EGOAPSYMBOLS_

	EGOAPSYMBOLS_DEFAULT = 0,

	EGOAPSYMBOLS_HAVE_RESOURCE,
	EGOAPSYMBOLS_HAVE_WOOD,
	EGOAPSYMBOLS_HAVE_STONE,
	EGOAPSYMBOLS_HAVE_TOOL,
	EGOAPSYMBOLS_HAVE_WEAPON,
	EGOAPSYMBOLS_FIRE_LIT,
	EGOAPSYMBOLS_WEAPON_IS_RANGED,
	EGOAPSYMBOLS_TARGET_IN_RANGE,
	EGOAPSYMBOLS_TARGET_IS_DEAD,
	EGOAPSYMBOLS_HUNGRY,

	EGOAPSYMBOLS_TOTAL
};

union Data
{
	bool bData;
	int nData;
	//float fData;
	void* pVoid;
};


struct OLD_WorldStateProperty
{
	OLD_EGOAPSymbols eSymbol;
	// Data data;
	bool bData = false;
};

struct OLD_WorldState
{
	OLD_WorldStateProperty WorldStateProperties[EGOAPSYMBOLS_TOTAL];
};
