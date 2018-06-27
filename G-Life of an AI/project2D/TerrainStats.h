#pragma once
#include "ETerrainType.h"

struct TerrainStats
{
	void Setup(ETerrainType eTerrainType)
	{
		switch (eTerrainType)
		{
		case ETERRAINTYPE_DIRT:
			m_bIsPassable = true;
			break;
		case ETERRAINTYPE_WATER:
			m_bIsPassable = false;
			break;
		case ETERRAINTYPE_MOUNTAIN:
			m_bIsPassable = false;
			break;
		case ETERRAINTYPE_TOTAL:
			break;
		default:
			break;
		}
	}

	//Variables
	ETerrainType m_eTerrainType = ETERRAINTYPE_DIRT;
	bool		 m_bIsPassable = true;
};