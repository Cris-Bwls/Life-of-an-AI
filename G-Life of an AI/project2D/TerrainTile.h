#pragma once
#include "TerrainStats.h"
#include "Vector2.h"

struct TileQuadrant;
class StaticObject;

#define TILE_NEIGHBOUR_COUNT 8

struct Index
{
	int x = 0;
	int y = 0;
};

class TerrainTile
{
public:
	TerrainTile(ETerrainType eTerrainType = ETERRAINTYPE_DIRT);
	~TerrainTile();

	void SetPos(Vector2 v2Pos) { m_v2Pos = v2Pos; };
	Vector2 GetPos() { return m_v2Pos; };

	void SetTerrainStats(ETerrainType eTerrainType = ETERRAINTYPE_DIRT) { m_TerrainStats.Setup(eTerrainType); };
	TerrainStats GetTerrainStats() { return m_TerrainStats; };
	
	void SetNeighbour(int nIndex, TerrainTile* neighbour = nullptr) { m_pNeighbours[nIndex] = neighbour; };
	TerrainTile* GetNeighbour(int nIndex) { return m_pNeighbours[nIndex]; };

	void SetPrev(TerrainTile* prev = nullptr) { m_pPrev = prev; };
	TerrainTile* GetPrev() { return m_pPrev; };

	void SetIndex(int nIndexX, int nIndexY) { m_Index.x = nIndexX; m_Index.y = nIndexY; };
	Index GetIndex() { return m_Index; };
	int GetIndexX() { return m_Index.x; };
	int GetIndexY() { return m_Index.y; };

	unsigned int GetCost(int nIndex) {	return m_nCost[nIndex];	};


	void SetFScore(unsigned int nFScore) { m_nFScore = nFScore; };
	unsigned int GetFScore() { return m_nFScore; };

	void SetGScore(unsigned int nGScore) { m_nGScore = nGScore; };
	unsigned int GetGScore() { return m_nGScore; };

	void SetHScore(unsigned int nHScore) { m_nHScore = nHScore; };
	unsigned int GetHScore() { return m_nHScore; };


	void SetBlocked(StaticObject* pBlocker = nullptr) {	m_bBlocked = true; m_pBlocker = pBlocker; SetQuadrantBlocked(); };
	bool GetBlocked() { return m_bBlocked; };
	StaticObject* GetBlocker() { return m_pBlocker; };

	void RemoveBlocked();
	void SetQuadrantBlocked();

	TileQuadrant* GetAnimalAvoidQuadrant(int nIndex) { return m_AnimalAvoidQuadrants[nIndex]; };

	int GetQuadrantFromPos(Vector2 v2Pos);

private:
	Vector2 m_v2Pos;
	TerrainStats m_TerrainStats;

	TerrainTile* m_pNeighbours[TILE_NEIGHBOUR_COUNT];
	TerrainTile* m_pPrev = nullptr;
	Index m_Index;

	unsigned int m_nCost[TILE_NEIGHBOUR_COUNT];
	
	unsigned int m_nFScore = 0;
	unsigned int m_nGScore = 0;
	unsigned int m_nHScore = 0;

	bool m_bBlocked = false;

	StaticObject* m_pBlocker = nullptr;
	TileQuadrant* m_AnimalAvoidQuadrants[4];
};

