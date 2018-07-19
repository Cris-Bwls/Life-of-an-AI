#include "Terrain.h"
#include <algorithm>
#include <typeinfo.h>
#include "TerrainTile.h"
#include "TileQuadrant.h"

#include "GUIManager.h"


Terrain::Terrain()
{
	// Create Tiles
	for (int x = 0; x < TERRAIN_SIZE_X; ++x)
	{
		for (int y = 0; y < TERRAIN_SIZE_Y; ++y)
		{
			m_pTiles[x][y] = new TerrainTile(x, y, ETERRAINTYPE_DIRT); 
			m_pTiles[x][y]->SetPos(Vector2((float)(TILE_SIZE * x + TILE_OFFSET), (float)(TILE_SIZE * y + TILE_OFFSET)), (float)TILE_SIZE);
			m_pTiles[x][y]->SetFScore(0xFFFFFFFF);
		}
	}

	// Neighbour Connection Order
	// -------
	// |7|0|4|
	// -------
	// |3|X|1|
	// -------
	// |6|2|5|
	// -------

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
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[4] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[5] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[6] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[7] = nullptr;

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[0] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[1] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[2] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[3] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[4] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[5] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[6] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[7] = nullptr;

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[0] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[1] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[2] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[3] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[4] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[5] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[6] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[7] = nullptr;

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[0] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[1] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[2] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[3] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[4] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[5] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[6] = nullptr;
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[7] = nullptr;

			// Internal Connections
			
			/// Cardinal Connections
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[1] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(1);
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[2] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(2);

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[2] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(3);
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[3] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(0);

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[0] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(0);
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[1] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(3);

			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[0] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(1);
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[3] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(2);

			/// Diagonal Connections
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[5] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(3);
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[6] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(2);
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[4] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(1);
			m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[7] = m_pTiles[x][y]->GetAnimalAvoidQuadrant(0);

			// External Connections

			//UP
			if (m_pTiles[x][y]->GetNeighbour(0))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(0);

				// Cardinal Connections
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[0] = neighbour->GetAnimalAvoidQuadrant(2);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[0] = neighbour->GetAnimalAvoidQuadrant(3);

				// Diagonal Connections
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[4] = neighbour->GetAnimalAvoidQuadrant(3);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[7] = neighbour->GetAnimalAvoidQuadrant(2);
			}

			//RIGHT
			if (m_pTiles[x][y]->GetNeighbour(1))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(1);

				// Cardinal Connections
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[1] = neighbour->GetAnimalAvoidQuadrant(0);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[1] = neighbour->GetAnimalAvoidQuadrant(2);

				// Diagonal Connections
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[5] = neighbour->GetAnimalAvoidQuadrant(2);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[4] = neighbour->GetAnimalAvoidQuadrant(0);
			}

			//DOWN
			if (m_pTiles[x][y]->GetNeighbour(2))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(2);

				// Cardinal Connections
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[2] = neighbour->GetAnimalAvoidQuadrant(0);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[2] = neighbour->GetAnimalAvoidQuadrant(1);

				// Diagonal Connections
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[5] = neighbour->GetAnimalAvoidQuadrant(1);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[6] = neighbour->GetAnimalAvoidQuadrant(0);
			}

			//LEFT
			if (m_pTiles[x][y]->GetNeighbour(3))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(3);

				// Cardinal Connections
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[3] = neighbour->GetAnimalAvoidQuadrant(1);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[3] = neighbour->GetAnimalAvoidQuadrant(3);

				// Diagonal Connections
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[6] = neighbour->GetAnimalAvoidQuadrant(3);
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[7] = neighbour->GetAnimalAvoidQuadrant(1);
			}

			//UP-RIGHT
			if (m_pTiles[x][y]->GetNeighbour(4))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(4);

				// Diagonal Connection
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_pNeighbours[4] = neighbour->GetAnimalAvoidQuadrant(2);
			}

			//DOWN-RIGHT
			if (m_pTiles[x][y]->GetNeighbour(5))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(5);

				// Diagonal Connection
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_pNeighbours[5] = neighbour->GetAnimalAvoidQuadrant(0);
			}

			//DOWN-LEFT
			if (m_pTiles[x][y]->GetNeighbour(6))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(6);

				// Diagonal Connection
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_pNeighbours[6] = neighbour->GetAnimalAvoidQuadrant(1);
			}

			//UP-LEFT
			if (m_pTiles[x][y]->GetNeighbour(7))
			{
				auto neighbour = m_pTiles[x][y]->GetNeighbour(7);

				// Diagonal Connection
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_pNeighbours[7] = neighbour->GetAnimalAvoidQuadrant(3);
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

void Terrain::ResetAnimalAvoid()
{
	TileQuadrant* pCurrentQuadrant = m_pTiles[0][0]->GetAnimalAvoidQuadrant(2);
	while (pCurrentQuadrant)
	{
		pCurrentQuadrant->m_nDistance = 0;

		TileQuadrant* pRightQuadrant = pCurrentQuadrant->m_pNeighbours[1];
		while (pRightQuadrant)
		{
			pRightQuadrant->m_nDistance = 0;
			pRightQuadrant = pRightQuadrant->m_pNeighbours[1];
		}

		pCurrentQuadrant = pCurrentQuadrant->m_pNeighbours[0];
	}
}

void Terrain::SetAnimalAvoid(Vector2 v2Pos, int nNoiseLevel)
{
	TerrainTile* pTileAtPos = GetTileByPos(v2Pos);
	//Pathfinding

	for (int i = 0; i < 4; ++i)
	{
		TileQuadrant* pStartTile = pTileAtPos->GetAnimalAvoidQuadrant(i);
		m_AnimalAvoidOpenList.clear();
		memset(m_AnimalAvoidClosedList, 0, sizeof(bool) * TERRAIN_SIZE_X * TERRAIN_SIZE_Y * 4);

		pStartTile->m_nDistance = nNoiseLevel * 10;
		m_AnimalAvoidOpenList.push_back(pStartTile);

		while (m_AnimalAvoidOpenList.size() > 0)
		{
			// Remove lowest node from open list and add to closed list
			TileQuadrant* pCurrent = m_AnimalAvoidOpenList[0];


			m_AnimalAvoidOpenList.erase(m_AnimalAvoidOpenList.begin());
			m_AnimalAvoidClosedList[pCurrent->index.x][pCurrent->index.y][pCurrent->m_nQuadrant] = true;

			if (pCurrent->m_nDistance == 0)
				continue;
			//Loop through all neighbours and add them to open list
			for (int j = 0; j < 8; ++j)
			{
				TileQuadrant* pNeighbour = pCurrent->m_pNeighbours[j];

				//Skip null neighbours
				if (!pNeighbour)
					continue;

				//Skip blocked neighbours
				if (pNeighbour->m_bBlocked)
					continue;

				//Skip closed list neighbours
				if (m_AnimalAvoidClosedList[pNeighbour->index.x][pNeighbour->index.y][pNeighbour->m_nQuadrant])
					continue;

				//Check if this is a better path
				int nDistance = pCurrent->m_nDistance - pCurrent->m_anCost[j];
				if (nDistance > pNeighbour->m_nDistance)
				{
					//Update to use the better path
					pNeighbour->m_nDistance = nDistance;

					m_AnimalAvoidOpenList.push_back(pNeighbour);
				}
			}
		}
	}
}

std::vector<Vector2> Terrain::GetPathToPos(Vector2 v2Start, Vector2 v2End, bool bAStar)
{
	SetSortHeap([](TerrainTile* lhs, TerrainTile* rhs) {return lhs->GetFScore() > rhs->GetFScore(); });

	std::vector<Vector2> path;
	TerrainTile* pStart = GetTileByPos(v2Start);
	TerrainTile* pEnd = GetTileByPos(v2End);

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
	std::push_heap(m_OpenList.begin(), m_OpenList.end(), SortHeapFunc);

	while (m_OpenList.size() > 0)
	{
		// Remove lowest node from open list and add to closed list
		TerrainTile* pCurrent = m_OpenList[0];

		std::pop_heap(m_OpenList.begin(), m_OpenList.end(), SortHeapFunc);
		m_OpenList.pop_back();

		m_ClosedList[pCurrent->GetIndexX()][pCurrent->GetIndexY()] = true;

		//Complete path here
		if (pCurrent == pEnd)
		{
			//Path is complete
			path.insert(path.begin(), pCurrent->GetPos());

			//While current's prev is not null
			while (pCurrent->GetPrev())
			{
				//Make current currents prev
				pCurrent = pCurrent->GetPrev();
				path.insert(path.begin(), pCurrent->GetPos());
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
					std::push_heap(m_OpenList.begin(), m_OpenList.end(), SortHeapFunc);
				}
			}
			//ELSE add node to open list and calculate scores
			else
			{
				//Calculate Gscore
				pNeighbour->SetGScore(pCurrent->GetGScore() + pCurrent->GetCost(i));

				// Calculate H score (if A*)
				if (bAStar)
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
				std::push_heap(m_OpenList.begin(), m_OpenList.end(), SortHeapFunc);
			}
		}
	}

	// Returns if no path found
	return path;
}

std::vector<Vector2> Terrain::GetPathToObject(Vector2 v2Start, StaticObject* target, bool bAStar)
{
	SetSortHeap([](TerrainTile* lhs, TerrainTile* rhs) {return lhs->GetFScore() > rhs->GetFScore(); });
	
	std::vector<Vector2> path;
	TerrainTile* pStart = GetTileByPos(v2Start);
	TerrainTile* pEnd = GetTileByPos(target->GetPos());

	auto targetTypeHash = typeid(*target).hash_code();

	// Safety Checks
	if (!pStart || !pEnd)
		return path;

	if (pStart->GetBlocked())
		return path;

	//Pathfinding
	m_OpenList.clear();
	memset(m_ClosedList, 0, sizeof(bool) * TERRAIN_SIZE_X * TERRAIN_SIZE_Y);

	pStart->SetGScore(0);
	pStart->SetPrev(nullptr);
	m_OpenList.push_back(pStart);
	std::push_heap(m_OpenList.begin(), m_OpenList.end(), SortHeapFunc);

	while (m_OpenList.size() > 0)
	{
		// Remove lowest node from open list and add to closed list
		TerrainTile* pCurrent = m_OpenList[0];

		std::pop_heap(m_OpenList.begin(), m_OpenList.end(), SortHeapFunc);
		m_OpenList.pop_back();

		m_ClosedList[pCurrent->GetIndexX()][pCurrent->GetIndexY()] = true;

		size_t currentTypeHash;
		if (pCurrent->GetStaticObject())
			currentTypeHash = typeid(*(pCurrent->GetStaticObject())).hash_code();
		else
			currentTypeHash = 0;

		//Complete path here
		if (pCurrent == pEnd || currentTypeHash == targetTypeHash)
		{
			target = pCurrent->GetStaticObject();

			//Path is complete
			if (pCurrent->GetBlocked() == false)
				path.insert(path.begin(), pCurrent->GetPos());

			//While current's prev is not null
			while (pCurrent->GetPrev())
			{
				//Make current currents prev
				pCurrent = pCurrent->GetPrev();
				path.insert(path.begin(), pCurrent->GetPos());
			}
			// Return Path
			return path;
		}

		//Loop through all neighbours and add them to open list
		for (int i = 0; i < TILE_NEIGHBOUR_COUNT; ++i)
		{
			bool bAllowBlocked = false;

			TerrainTile* pNeighbour = pCurrent->GetNeighbour(i);

			//Skip null neighbours
			if (!pNeighbour)
				continue;

			if (pNeighbour->GetStaticObject())
			{
				auto neighbourTypeHash = typeid(*(pNeighbour->GetStaticObject())).hash_code();

				if (neighbourTypeHash == targetTypeHash)
					bAllowBlocked = true;
			}

			//Skip blocked neighbours
			if (pNeighbour->GetBlocked() && bAllowBlocked == false)
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
					std::push_heap(m_OpenList.begin(), m_OpenList.end(), SortHeapFunc);
				}
			}
			//ELSE add node to open list and calculate scores
			else
			{
				//Calculate Gscore
				pNeighbour->SetGScore(pCurrent->GetGScore() + pCurrent->GetCost(i));

				// Calculate H score (if A*)
				if (bAStar)
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
				std::push_heap(m_OpenList.begin(), m_OpenList.end(), SortHeapFunc);
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

	// Checks if the floats are -ve
	// This means terrain cant be less than game world origin
	if (v2Pos.x < 0 || v2Pos.y < 0)
		return nullptr;

	if (x < 0)
		return nullptr;

	if (y < 0)
		return nullptr;

	if (x >= TERRAIN_SIZE_X)
		return nullptr;

	if (y >= TERRAIN_SIZE_Y)
		return nullptr;

	return m_pTiles[x][y];
}

void Terrain::UpdateAnimalAvoidVector()
{
	for (int x = 0; x < TERRAIN_SIZE_X; ++x)
	{
		for (int y = 0; y < TERRAIN_SIZE_Y; ++y)
		{
			if (m_pTiles[x][y]->GetBlocked())
			{
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(0)->m_v2Vec.Zero();
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(1)->m_v2Vec.Zero();
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(2)->m_v2Vec.Zero();
				m_pTiles[x][y]->GetAnimalAvoidQuadrant(3)->m_v2Vec.Zero();
				continue;
			}

			for (int i = 0; i < 4; ++i)
			{
				TileQuadrant* pQuadrant = m_pTiles[x][y]->GetAnimalAvoidQuadrant(i);
				Vector2 v2Vec;
				for (int j = 0; j < 8; ++j)
				{
					if (pQuadrant->m_pNeighbours[j])
					{
						if (pQuadrant->m_pNeighbours[j]->m_bBlocked)
							continue;

						Vector2 deltaPos = pQuadrant->m_pNeighbours[j]->m_v2Pos - pQuadrant->m_v2Pos;
						int deltaDistance = pQuadrant->m_pNeighbours[j]->m_nDistance - pQuadrant->m_nDistance;
						v2Vec += (deltaPos * deltaDistance);
					}
				}
				v2Vec.normalise();
				pQuadrant->m_v2Vec = -v2Vec;
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

			if (m_pTiles[x][y]->GetBlocked())
				continue;

			// Draw Connections (if allowed)
			if (GUIManager::GetInstance()->GetGuiFlags()->miscEdit.bDrawConnections)
			{
				for (int i = 0; i < TILE_NEIGHBOUR_COUNT; ++i)
				{
					auto neighbour = m_pTiles[x][y]->GetNeighbour(i);
					if (neighbour)
					{
						if (neighbour->GetBlocked())
							continue;

						Vector2 v2NeighbourPos = neighbour->GetPos();

						pRenderer->drawLine(v2Pos.x, v2Pos.y, v2NeighbourPos.x, v2NeighbourPos.y, 3);
					}
				}
			}
		}
	}

	pRenderer->setRenderColour(0xFFFFFFFF);
}

void Terrain::DrawQuadrants(aie::Renderer2D * pRenderer)
{
	float fAlphaOffset;

	for (int x = 0; x < TERRAIN_SIZE_X; ++x)
	{
		for (int y = 0; y < TERRAIN_SIZE_Y; ++y)
		{
			for (int i = 0; i < 4; ++i)
			{
				auto pQuadrant = m_pTiles[x][y]->GetAnimalAvoidQuadrant(i);

				// Show Distance
				fAlphaOffset = 0.05f * (float)(pQuadrant->m_nDistance) * 0.1f;
				pRenderer->setRenderColour(0.0f, 1.0f, 0.0f, (fAlphaOffset));
				pRenderer->drawBox(pQuadrant->m_v2Pos.x, pQuadrant->m_v2Pos.y, (float)TILE_SIZE / 4, (float)TILE_SIZE / 4);

				// Show Vector
				pRenderer->setRenderColour(0xFF0000FF);
				Vector2 v2Vec = pQuadrant->m_v2Pos + (pQuadrant->m_v2Vec * (float)TILE_SIZE * 0.25f);
				pRenderer->drawLine(pQuadrant->m_v2Pos.x, pQuadrant->m_v2Pos.y, v2Vec.x, v2Vec.y, 0.5f);
			}
		}
	}

	pRenderer->setRenderColour(0xFFFFFFFF);
}
