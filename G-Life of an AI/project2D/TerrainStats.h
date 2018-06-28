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
			m_nColour = 0x603913; // Dark Brown
			break;
		case ETERRAINTYPE_WATER:
			m_bIsPassable = false;
			m_nColour = 0x2b89b4; // Light Blue
			break;
		case ETERRAINTYPE_MOUNTAIN:
			m_bIsPassable = false;
			m_nColour = 0x3d392f; // Grey Brown
			
			break;
		case ETERRAINTYPE_TOTAL:
			break;
		default:
			break;
		}
	}

	//Variables
	ETerrainType m_eTerrainType = ETERRAINTYPE_DIRT;
	int			 m_nColour;
	bool		 m_bIsPassable = true;
};