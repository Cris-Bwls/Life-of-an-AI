#pragma once
#include "Vector2.h"

struct TileQuadrant
{
	TileQuadrant* m_pNeighbours[8];
	int m_anCost[8] = { 10, 10, 10, 10,		// Cardinal Neighbour cost
						14, 14, 14, 14 };	// Diagonal Neighbour cost

	TileQuadrant* m_pPrev = nullptr;

	Index index;
	int m_nQuadrant;

	bool m_bBlocked = false;
	
	Vector2 m_v2Vec;
	int m_nDistance = 0;
};

