#pragma once
#include <vector>
#include "Vector2.h"
#include "Renderer2D.h"

class TerrainTile;
class TileQuadrant;

#define TERRAIN_SIZE_X 50
#define TERRAIN_SIZE_Y 30

#define TILE_SIZE 15

class Terrain
{
public:
	Terrain();
	~Terrain();

	void ResetAnimalAvoid();
	void SetAnimalAvoid(Vector2 v2Pos, int nNoiseLevel);

	std::vector<Vector2> GetPath(Vector2 v2Start, Vector2 v2End, bool AStar);
	TerrainTile* GetTileByPos(Vector2 v2Pos);

	void SortOpenList();
	void SortAnimalAvoidOpenList();

	void Draw(aie::Renderer2D* pRenderer);

private:
	TerrainTile* m_pTiles[TERRAIN_SIZE_X][TERRAIN_SIZE_Y];

	std::vector<TerrainTile*> m_OpenList;
	bool m_ClosedList[TERRAIN_SIZE_X][TERRAIN_SIZE_Y];

	std::vector<TileQuadrant*> m_AnimalAvoidOpenList;
	bool m_AnimalAvoidClosedList[TERRAIN_SIZE_X][TERRAIN_SIZE_Y][4];
};

