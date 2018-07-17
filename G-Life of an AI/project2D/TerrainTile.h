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
	TerrainTile(int nIndexX, int nIndexY, ETerrainType eTerrainType = ETERRAINTYPE_DIRT);
	~TerrainTile();

	void SetTerrainStats(ETerrainType eTerrainType = ETERRAINTYPE_DIRT);

	void SetStaticObject(StaticObject* pBlocker = nullptr);
	void RemoveStaticObject();
	void Unblock();
	void SetQuadrantBlocked();

	int GetQuadrantFromPos(Vector2 v2Pos);

	void SetPos(Vector2 v2Pos, int tileSize);
	inline Vector2 GetPos() { return m_v2Pos; };

	inline TerrainStats GetTerrainStats() { return m_TerrainStats; };
	
	inline void SetNeighbour(int nIndex, TerrainTile* neighbour = nullptr) { m_pNeighbours[nIndex] = neighbour; };
	inline TerrainTile* GetNeighbour(int nIndex) { return m_pNeighbours[nIndex]; };

	inline void SetPrev(TerrainTile* prev = nullptr) { m_pPrev = prev; };
	inline TerrainTile* GetPrev() { return m_pPrev; };

	inline void SetIndex(int nIndexX, int nIndexY) { m_Index.x = nIndexX; m_Index.y = nIndexY; };
	inline Index GetIndex() { return m_Index; };
	inline int GetIndexX() { return m_Index.x; };
	inline int GetIndexY() { return m_Index.y; };

	inline unsigned int GetCost(int nIndex) {	return m_nCost[nIndex];	};


	inline void SetFScore(unsigned int nFScore) { m_nFScore = nFScore; };
	inline unsigned int GetFScore() { return m_nFScore; };

	inline void SetGScore(unsigned int nGScore) { m_nGScore = nGScore; };
	inline unsigned int GetGScore() { return m_nGScore; };

	inline void SetHScore(unsigned int nHScore) { m_nHScore = nHScore; };
	inline unsigned int GetHScore() { return m_nHScore; };


	inline void Block() { m_bBlocked = true; SetQuadrantBlocked(); };
	inline bool GetBlocked() { return m_bBlocked; };
	StaticObject* GetStaticObject();

	inline TileQuadrant* GetAnimalAvoidQuadrant(int nIndex) { return m_AnimalAvoidQuadrants[nIndex]; };


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

	StaticObject* m_pStaticObject = nullptr;
	TileQuadrant* m_AnimalAvoidQuadrants[4];
};

