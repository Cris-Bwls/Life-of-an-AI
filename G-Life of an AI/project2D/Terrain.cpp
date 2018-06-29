#include "Terrain.h"
#include "TerrainTile.h"
#include "TileQuadrant.h"


Terrain::Terrain()
{
	// Create Tiles
	for (int x = 0; x < TERRAIN_SIZE_X; ++x)
	{
		for (int y = 0; y < TERRAIN_SIZE_Y; ++y)
		{
			m_pTiles[x][y] = new TerrainTile();
			m_pTiles[x][y]->SetPos(Vector2(TILE_SIZE * x, TILE_SIZE * y));
			m_pTiles[x][y]->SetIndex(x, y);
			m_pTiles[x][y]->SetFScore(0xFFFFFFFF);
		}
	}

	// Neighbour Connection Order
	// |------
	// |7|0|4|
	// |------
	// |3|X|1|
	// |------
	// |6|2|5|
	// |------

	// Connect Tiles
	for (int x = 0; x < TERRAIN_SIZE_X; ++x)
	{
		for (int y = 0; y < TERRAIN_SIZE_Y; ++y)
		{
			m_pTiles[x][y]->SetNeighbour(0);
			m_pTiles[x][y]->SetNeighbour(1);
			m_pTiles[x][y]->SetNeighbour(2);
			m_pTiles[x][y]->SetNeighbour(3);
			m_pTiles[x][y]->SetNeighbour(4);
			m_pTiles[x][y]->SetNeighbour(5);
			m_pTiles[x][y]->SetNeighbour(6);
			m_pTiles[x][y]->SetNeighbour(7);
			
			// Cardinal

			// Up
			if (y < TERRAIN_SIZE_Y - 1)
				m_pTiles[x][y]->SetNeighbour(0, m_pTiles[x][y + 1]);

			// Right
			if (x < TERRAIN_SIZE_X - 1)
				m_pTiles[x][y]->SetNeighbour(1, m_pTiles[x + 1][y]);

			// Down
			if (y > 0)
				m_pTiles[x][y]->SetNeighbour(2, m_pTiles[x][y - 1]);

			// Left
			if (x > 0)
				m_pTiles[x][y]->SetNeighbour(3, m_pTiles[x - 1][y]);

			// Diagonals

			// Top Right
			if (y < TERRAIN_SIZE_Y - 1 && x < TERRAIN_SIZE_X - 1)
				m_pTiles[x][y]->SetNeighbour(4, m_pTiles[x + 1][y + 1]);

			// Bottom Right
			if (y > 0 && x < TERRAIN_SIZE_X - 1)
				m_pTiles[x][y]->SetNeighbour(5, m_pTiles[x + 1][y - 1]);

			// Bottom Left
			if (y > 0 && x > 0)
				m_pTiles[x][y]->SetNeighbour(6, m_pTiles[x - 1][y - 1]);

			// Top Left
			if (y < TERRAIN_SIZE_Y - 1 && x > 0)
				m_pTiles[x][y]->SetNeighbour(7, m_pTiles[x - 1][y + 1]);


		}
	}
	// Connect TileQuadrants
	for (int x = 0; x < TERRAIN_SIZE_X; ++x)
	{
		for (int y = 0; y < TERRAIN_SIZE_Y; ++y)
		{
			// Set Quadrant Neighbours to nullptr
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[0] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[1] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[2] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[3] = nullptr;

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[0] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[1] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[2] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[3] = nullptr;

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[0] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[1] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[2] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[3] = nullptr;

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[0] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[1] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[2] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[3] = nullptr;

			// Internal Connections
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[1] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(1);
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[2] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(2);

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[2] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(3);
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[3] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(0);

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[0] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(0);
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[1] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(3);

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[0] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(1);
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[3] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(2);

			// External Connections
			///UP
			if (m_pTiles[x][y]->GetNeighbour(0))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(0);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[0] = neighbour->GetAnimalAvoidQuadrant(2);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[0] = neighbour->GetAnimalAvoidQuadrant(3);
			}

			///RIGHT
			if (m_pTiles[x][y]->GetNeighbour(1))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(1);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[1] = neighbour->GetAnimalAvoidQuadrant(0);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[1] = neighbour->GetAnimalAvoidQuadrant(2);
			}

			///DOWN
			if (m_pTiles[x][y]->GetNeighbour(2))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(2);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[2] = neighbour->GetAnimalAvoidQuadrant(0);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[2] = neighbour->GetAnimalAvoidQuadrant(1);
			}

			///LEFT
			if (m_pTiles[x][y]->GetNeighbour(3))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(3);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[3] = neighbour->GetAnimalAvoidQuadrant(1);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[3] = neighbour->GetAnimalAvoidQuadrant(3);
			}
		}
	}
}


Terrain::~Terrain()
{
	// Delete Tiles
	for (int x = 0; x < TERRAIN_SIZE_X; ++x)
	{
		for (int y = 0; y < TERRAIN_SIZE_Y; ++y)
		{
			delete m_pTiles[x][y];
		}
	}
}

std::vector<Vector2> Terrain::GetPath(Vector2 v2Start, Vector2 v2End, bool AStar)
{
	std::vector<Vector2> path;
	TerrainTile* pStart = GetTileByPos(v2End);
	TerrainTile* pEnd = GetTileByPos(v2Start);

	// Safety Checks
	if (!pStart || !pEnd)
		return path;

	if (pStart->GetBlocked() || pEnd->GetBlocked())
		return path;

	//Pathfinding
	m_OpenList.clear();
	memset(m_ClosedList, 0, sizeof(bool) * TERRAIN_SIZE_X * TERRAIN_SIZE_Y);

	pStart->SetGScore(0);
	pStart->SetPrev(nullptr);
	m_OpenList.push_back(pStart);

	while (m_OpenList.size() > 0)
	{
		SortOpenList();

		// Remove lowest node from open list and add to closed list
		TerrainTile* pCurrent = m_OpenList[0];
		m_OpenList.erase(m_OpenList.begin());
		m_ClosedList[pCurrent->GetIndexX()][pCurrent->GetIndexY()] = true;

		//Complete path here
		if (pCurrent == pEnd)
		{
			//Path is complete
			path.push_back(pCurrent->GetPos());

			//While current's prev is not null
			while (pCurrent->GetPrev())
			{
				//Make current currents prev
				pCurrent = pCurrent->GetPrev();
				path.push_back(pCurrent->GetPos());
			}
			// Return Path
			return path;
		}

		//Loop through all neighbours and add them to open list
		for (int i = 0; i < TILE_NEIGHBOUR_COUNT; ++i)
		{
			TerrainTile* pNeighbour = pCurrent->GetNeighbour(i);

			//Skip null neighbours
			if (!pNeighbour)
				continue;

			//Skip blocked neighbours
			if (pNeighbour->GetBlocked())
				continue;

			//Skip closed list neighbours
			if (m_ClosedList[pNeighbour->GetIndexX()][pNeighbour->GetIndexY()])
				continue;

			//If neighbour is already in open list
			if (std::find(m_OpenList.begin(), m_OpenList.end(), pNeighbour) != m_OpenList.end())
			{
				//Check if this is a better path
				unsigned int newGScore = pCurrent->GetGScore() + pCurrent->GetCost(i);
				if (newGScore < pNeighbour->GetGScore())
				{
					//Update to use the better path
					pNeighbour->SetGScore(newGScore);
					pNeighbour->SetFScore(pNeighbour->GetGScore() + pNeighbour->GetHScore());

					pNeighbour->SetPrev(pCurrent);

					m_OpenList.push_back(pNeighbour);
				}
			}
			//ELSE add node to open list and calculate scores
			else
			{
				//Calculate Gscore
				pNeighbour->SetGScore(pCurrent->GetGScore() + pCurrent->GetCost(i));

				// Calculate H score (if A*)
				if (AStar)
				{
					int diffX = abs(pEnd->GetIndexX() - pNeighbour->GetIndexX());
					int diffY = abs(pEnd->GetIndexY() - pNeighbour->GetIndexY());
					if (diffX > diffY)
					{
						pNeighbour->SetHScore((diffY * 14) + ((diffX - diffY) * 10));
					}
					else
					{
						pNeighbour->SetHScore((diffX * 14) + ((diffY - diffX) * 10));
					}
				}
				else
				{
					pNeighbour->SetHScore(0);
				}

				// Calculate F Score
				pNeighbour->SetFScore(pNeighbour->GetGScore() + pNeighbour->GetHScore());

				pNeighbour->SetPrev(pCurrent);

				m_OpenList.push_back(pNeighbour);
			}
		}
	}

	// Returns if no path found
	return path;
}

TerrainTile* Terrain::GetTileByPos(Vector2 v2Pos)
{
	int x = (int)((v2Pos.x) / TILE_SIZE);
	int y = (int)((v2Pos.y) / TILE_SIZE);

	if (x < 0)
		return nullptr;

	if (y < 0)
		return nullptr;

	if (x > TERRAIN_SIZE_X)
		return nullptr;

	if (y > TERRAIN_SIZE_Y)
		return nullptr;

	return m_pTiles[x][y];
}

void Terrain::SortOpenList()
{
	for (int i = 0; i < m_OpenList.size(); ++i)
	{
		for (int j = 0; j < m_OpenList.size() - 1; ++j)
		{
			if (m_OpenList[j]->GetFScore() > m_OpenList[j + 1]->GetFScore())
			{
				TerrainTile* swap = m_OpenList[j];
				m_OpenList[j] = m_OpenList[j + 1];
				m_OpenList[j + 1] = swap;
			}
		}
	}
}

void Terrain::Draw(aie::Renderer2D * pRenderer)
{
	for (int x = 0; x < TERRAIN_SIZE_X; ++x)
	{
		for (int y = 0; y < TERRAIN_SIZE_Y; ++y)
		{
			pRenderer->setRenderColour(m_pTiles[x][y]->GetTerrainStats().m_nColour);

			Vector2 v2Pos = m_pTiles[x][y]->GetPos();

			pRenderer->drawBox(v2Pos.x, v2Pos.y, TILE_SIZE, TILE_SIZE);

			pRenderer->setRenderColour(0x0000FFFF);
			for (int i = 0; i < TILE_NEIGHBOUR_COUNT; ++i)
			{
				if (m_pTiles[x][y]->GetNeighbour(i))
				{
					if (m_pTiles[x][y]->GetNeighbour(i)->GetBlocked())
						continue;

					Vector2 v2NeighbourPos = m_pTiles[x][y]->GetNeighbour(i)->GetPos();

					pRenderer->drawLine(v2Pos.x, v2Pos.y, v2NeighbourPos.x, v2NeighbourPos.y, 3);
				}
			}
		}
	}

	pRenderer->setRenderColour(0xFFFFFFFF);
}
