#pragma once

enum EGOAPSymbols
{
	// EGOAPSYMBOLS_

	EGOAPSYMBOLS_DEFAULT = 0,

	EGOAPSYMBOLS_HAVE_RESOURCE,
	EGOAPSYMBOLS_HAVE_TOOL,
	EGOAPSYMBOLS_HAVE_WEAPON,
	EGOAPSYMBOLS_WEAPON_IS_RANGED,
	EGOAPSYMBOLS_TARGET_IN_RANGE,
	EGOAPSYMBOLS_TARGET_IS_DEAD,
	EGOAPSYMBOLS_HUNGRY,

	EGOAPSYMBOLS_TOTAL
};

struct WorldStateProperty
{
	EGOAPSymbols eSymbol;

	union value
	{
		bool bValue;
		int nValue;
		//float fValue;
		void* pVoid;
	};
};

struct WorldState
{
	WorldStateProperty WorldStateProperties[EGOAPSYMBOLS_TOTAL];
};
