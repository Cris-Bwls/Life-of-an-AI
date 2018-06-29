#include "TerrainTile.h"
#include "TileQuadrant.h"
#include "StaticObject.h"



TerrainTile::TerrainTile(ETerrainType eTerrainType)
{
	m_TerrainStats.Setup(eTerrainType);

	if (!(m_TerrainStats.m_bIsPassable))
		m_bBlocked = true;

	m_AnimalAvoidQuadrants[0] = new TileQuadrant();
	m_AnimalAvoidQuadrants[1] = new TileQuadrant();
	m_AnimalAvoidQuadrants[2] = new TileQuadrant();
	m_AnimalAvoidQuadrants[3] = new TileQuadrant();

	m_AnimalAvoidQuadrants[0]->index = m_Index;
	m_AnimalAvoidQuadrants[0]->m_nQuadrant = 0;
	m_AnimalAvoidQuadrants[1]->index = m_Index;
	m_AnimalAvoidQuadrants[1]->m_nQuadrant = 1;
	m_AnimalAvoidQuadrants[2]->index = m_Index;
	m_AnimalAvoidQuadrants[2]->m_nQuadrant = 2;
	m_AnimalAvoidQuadrants[3]->index = m_Index;
	m_AnimalAvoidQuadrants[3]->m_nQuadrant = 3;

	// Costs
	m_nCost[0] = 10;
	m_nCost[1] = 10;
	m_nCost[2] = 10;
	m_nCost[3] = 10;
	m_nCost[4] = 14;
	m_nCost[5] = 14;
	m_nCost[6] = 14;
	m_nCost[7] = 14;
}


TerrainTile::~TerrainTile()
{
	delete m_AnimalAvoidQuadrants[0];
	delete m_AnimalAvoidQuadrants[1];
	delete m_AnimalAvoidQuadrants[2];
	delete m_AnimalAvoidQuadrants[3];
}

void TerrainTile::RemoveBlocked()
{
	if (m_TerrainStats.m_bIsPassable)
		m_bBlocked = false;
	else
		m_bBlocked = true;

	m_pBlocker = nullptr;
	SetQuadrantBlocked();
}

void TerrainTile::SetQuadrantBlocked()
{
	m_AnimalAvoidQuadrants[0]->m_bBlocked = m_bBlocked;
	m_AnimalAvoidQuadrants[1]->m_bBlocked = m_bBlocked;
	m_AnimalAvoidQuadrants[2]->m_bBlocked = m_bBlocked;
	m_AnimalAvoidQuadrants[3]->m_bBlocked = m_bBlocked;
}

int TerrainTile::GetQuadrantFromPos(Vector2 v2Pos)
{
	if (v2Pos.x > m_v2Pos.x)
	{
		if (v2Pos.y > m_v2Pos.y)
		{
			return 1;
		}
		return 3;
	}
	//ELSE
	if (v2Pos.y > m_v2Pos.y)
	{
		return 0;
	}
	return 2;
}
