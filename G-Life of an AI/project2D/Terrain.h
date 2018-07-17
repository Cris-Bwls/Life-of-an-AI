#pragma once
#include <vector>
#include <functional>
#include "Vector2.h"
#include "Renderer2D.h"
#include "StaticObject.h"

class TerrainTile;
struct TileQuadrant;

#define TERRAIN_SIZE_X 50
#define TERRAIN_SIZE_Y 30

#define TILE_SIZE 16
#define TILE_OFFSET (TILE_SIZE/2)

class Terrain
{
public:
	Terrain();
	~Terrain();

	void ResetAnimalAvoid();
	void SetAnimalAvoid(Vector2 v2Pos, int nNoiseLevel);

	std::vector<Vector2> GetPathToPos(Vector2 v2Start, Vector2 v2End, bool bAStar);
	std::vector<Vector2> GetPathToObject(Vector2 v2Start, StaticObject* target, bool bAStar);
	TerrainTile* GetTileByPos(Vector2 v2Pos);


	void UpdateAnimalAvoidVector();

	void Draw(aie::Renderer2D* pRenderer);
	void DrawQuadrants(aie::Renderer2D* pRenderer);

private:
	inline void SetSortHeap(std::function<bool(TerrainTile* lhs, TerrainTile* rhs)> NewSortHeapFunc) { SortHeapFunc = NewSortHeapFunc; };
	//Variables
	TerrainTile* m_pTiles[TERRAIN_SIZE_X][TERRAIN_SIZE_Y];

	std::vector<TerrainTile*> m_OpenList;
	bool m_ClosedList[TERRAIN_SIZE_X][TERRAIN_SIZE_Y];

	std::vector<TileQuadrant*> m_AnimalAvoidOpenList;
	bool m_AnimalAvoidClosedList[TERRAIN_SIZE_X][TERRAIN_SIZE_Y][4];

	std::function<bool(TerrainTile* lhs, TerrainTile* rhs)> SortHeapFunc;
};

