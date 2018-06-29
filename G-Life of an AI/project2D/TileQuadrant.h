#pragma once
#include "Vector2.h"

struct TileQuadrant
{
	TileQuadrant* m_pNeighbours[4];
	TileQuadrant* m_pPrev = nullptr;

	bool m_bBlocked = false;

	Vector2 m_v2Vec;
	int m_nDistance = 0;
};

