#include "TerrainTile.h"
#include "TileQuadrant.h"
#include "StaticObject.h"



TerrainTile::TerrainTile(int nIndexX, int nIndexY, ETerrainType eTerrainType)
{
	m_TerrainStats.Setup(eTerrainType);
	SetIndex(nIndexX, nIndexY);

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

void TerrainTile::SetTerrainStats(ETerrainType eTerrainType)
{
	// Change Terrain Type
	m_TerrainStats.Setup(eTerrainType);

	// Change Blocked Status
	Unblock();
}

void TerrainTile::SetStaticObject(StaticObject* pStaticObject)
{
	m_pStaticObject = pStaticObject;

	if (pStaticObject)
	{
		if (pStaticObject->GetIsBlocker())
		{
			m_bBlocked = true;
			SetQuadrantBlocked();
			return;
		}
	}

	Unblock();
}

void TerrainTile::RemoveStaticObject()
{
	m_pStaticObject = nullptr;
	SetQuadrantBlocked();
}

void TerrainTile::Unblock()
{
	if (m_TerrainStats.m_bIsPassable)
	{
		m_bBlocked = false;

		// If there is no object above
		if (GetStaticObject() == nullptr)
		{
			SetQuadrantBlocked();
			return;
		}

		// If the object above isnt a blocker
		if (m_pStaticObject->GetIsBlocker() == false)
		{
			SetQuadrantBlocked();
			return;
		}
	}
	
	m_bBlocked = true;
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

void TerrainTile::SetPos(Vector2 v2Pos, int tileSize)
{
	m_v2Pos = v2Pos;

	int offset = tileSize * 0.25;
	m_AnimalAvoidQuadrants[0]->m_v2Pos = Vector2(v2Pos.x - offset, v2Pos.y + offset);
	m_AnimalAvoidQuadrants[1]->m_v2Pos = Vector2(v2Pos.x + offset, v2Pos.y + offset);
	m_AnimalAvoidQuadrants[2]->m_v2Pos = Vector2(v2Pos.x - offset, v2Pos.y - offset);
	m_AnimalAvoidQuadrants[3]->m_v2Pos = Vector2(v2Pos.x + offset, v2Pos.y - offset);
}

StaticObject * TerrainTile::GetStaticObject()
{
	// If object exists
	if (m_pStaticObject)
		// AND is NOT alive
		if (m_pStaticObject->GetIsAlive() == false)
			// reset pointer
			m_pStaticObject = nullptr;

	return m_pStaticObject;
}

