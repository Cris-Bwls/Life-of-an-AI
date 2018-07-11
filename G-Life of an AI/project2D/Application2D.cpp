#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "CameraManager.h"
#include "GUIManager.h"

#include <iostream>

//DEBUG
#include "TerrainTile.h"
#include <vector>
#include "Vector2.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	CameraManager::Create();
	CameraManager::GetInstance()->SetApp2D(this);

	GUIManager::Create();
	//GUIManager::GetInstance()->AddActiveGUI(EGUITYPE_DEBUG_BASIC);
	GUIManager::GetInstance()->AddActiveGUI(EGUITYPE_DEBUG_MOUSE);
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_pMap = new Terrain();
	
	m_v2PathStart = Vector2(100, 100);
	m_v2PathEnd = Vector2(300, 200);
	
	m_timer = 0;

	return true;

	
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_2dRenderer;
	delete m_pMap;

	GUIManager::Destroy();
	CameraManager::Destroy();
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	//Update Camera
	CameraManager::GetInstance()->Update(deltaTime);

	// input example
	aie::Input* input = aie::Input::getInstance();

	//DEBUG
	GUIFlags* pGuiFlags = GUIManager::GetInstance()->GetGuiFlags();


	if (input->isKeyDown(aie::INPUT_KEY_1) || pGuiFlags->heatMapEdit.bRebuildHeatMap)
	{
		m_pMap->ResetAnimalAvoid();
		for (int i = 0; i < m_HeatSourceList.size(); ++i)
		{
			m_pMap->SetAnimalAvoid(m_HeatSourceList[i], 20);
		}

		pGuiFlags->heatMapEdit.bRebuildHeatMap = false;
	}

	if (input->isKeyDown(aie::INPUT_KEY_2) || pGuiFlags->pathFindingEdit.bRebuildPath)
	{
		m_path = m_pMap->GetPath(m_v2PathStart, m_v2PathEnd, true);

		pGuiFlags->pathFindingEdit.bRebuildPath = false;
	}

	if (input->isMouseButtonDown(0))
	{
		SetMouseDownLeft();
		MouseDownLeft();
	}
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {
	
	// wipe the screen to the background colour
	clearScreen();

	// set the camera position and scale before we begin rendering
	CameraManager::GetInstance()->Draw(m_2dRenderer);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_pMap->Draw(m_2dRenderer);
	m_pMap->DrawQuadrants(m_2dRenderer);
	
	//DEBUG

	// Draw Path if it exists
	if (m_path.size() > 0)
	{
		m_2dRenderer->setRenderColour(0xFF0000FF);
		for (int i = 0; i < m_path.size(); ++i)
		{
			m_2dRenderer->drawBox(m_path[i].x, m_path[i].y, TILE_SIZE, TILE_SIZE);
		}
		m_2dRenderer->setRenderColour(0xFFFFFFFF);
	}

	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();

	GUIManager::GetInstance()->Draw();
}

void Application2D::SetMouseDownLeft()
{
	bool funcSet = false;

	GUIFlags* pGuiFlags = GUIManager::GetInstance()->GetGuiFlags();

	switch (pGuiFlags->eDebugMouseWindows)
	{
	case GUI_Type_DebugMouse::EWINDOWS_BLOCKER_EDIT:
		// Place Blocker
		if (pGuiFlags->blockerEdit.bPlaceBlocker)
		{
			MouseDownLeft = [this]() 
			{
				Vector2 v2MousePos = CameraManager::GetInstance()->GetWorldMousePos();
				TerrainTile* pTile = m_pMap->GetTileByPos(v2MousePos);

				if (pTile)
				{
					pTile->SetBlocked();
				}
			};
			funcSet = true;
			return;
		}
		// Remove Blocker
		else if (pGuiFlags->blockerEdit.bRemoveBlocker)
		{
			MouseDownLeft = [this]()
			{
				Vector2 v2MousePos = CameraManager::GetInstance()->GetWorldMousePos();
				TerrainTile* pTile = m_pMap->GetTileByPos(v2MousePos);

				if (pTile)
				{
					pTile->RemoveBlocked();
				}
			};
			funcSet = true;
			return;
		}
		break;
	case GUI_Type_DebugMouse::EWINDOWS_CHANGE_TERRAIN:
		// Change terrain to Dirt
		if (pGuiFlags->changeTerrain.bPlaceDirt)
		{
			MouseDownLeft = [this]()
			{
				Vector2 v2MousePos = CameraManager::GetInstance()->GetWorldMousePos();
				TerrainTile* pTile = m_pMap->GetTileByPos(v2MousePos);

				if (pTile)
				{
					pTile->SetTerrainStats(ETERRAINTYPE_DIRT);
				}
			};
			funcSet = true;
			return;
		}

		// Change terrain to Water
		else if (pGuiFlags->changeTerrain.bPlaceWater)
		{
			MouseDownLeft = [this]()
			{
				Vector2 v2MousePos = CameraManager::GetInstance()->GetWorldMousePos();
				TerrainTile* pTile = m_pMap->GetTileByPos(v2MousePos);

				if (pTile)
				{
					pTile->SetTerrainStats(ETERRAINTYPE_WATER);
				}
			};
			funcSet = true;
			return;
		}

		// Change terrain to Mountain
		else if (pGuiFlags->changeTerrain.bPlaceMountain)
		{
			MouseDownLeft = [this]()
			{
				Vector2 v2MousePos = CameraManager::GetInstance()->GetWorldMousePos();
				TerrainTile* pTile = m_pMap->GetTileByPos(v2MousePos);

				if (pTile)
				{
					pTile->SetTerrainStats(ETERRAINTYPE_MOUNTAIN);
				}
			};
			funcSet = true;
			return;
		}
		break;
	case GUI_Type_DebugMouse::EWINDOWS_HEAT_MAP_EDIT:
		// Add heat source
		if (pGuiFlags->heatMapEdit.bPlaceHeatPoint)
		{
			MouseDownLeft = [this]()
			{
				Vector2 v2MousePos = CameraManager::GetInstance()->GetWorldMousePos();
				TerrainTile* pTile = m_pMap->GetTileByPos(v2MousePos);

				if (pTile)
				{
					Vector2 tilePos = pTile->GetPos();

					for (int i = 0; i < m_HeatSourceList.size(); ++i)
					{
						if (m_HeatSourceList[i] == tilePos)
							return;
					}
					
					m_HeatSourceList.push_back(tilePos);
				}
			};
			funcSet = true;
			return;
		}
		// Remove heat source
		else if (pGuiFlags->heatMapEdit.bRemoveHeatPoint)
		{
			MouseDownLeft = [this]()
			{
				Vector2 v2MousePos = CameraManager::GetInstance()->GetWorldMousePos();
				TerrainTile* pTile = m_pMap->GetTileByPos(v2MousePos);

				if (pTile)
				{
					Vector2 tilePos = pTile->GetPos();

					for (int i = 0; i < m_HeatSourceList.size(); ++i)
					{
						if (m_HeatSourceList[i] == tilePos)
						{
							m_HeatSourceList.erase(m_HeatSourceList.begin() + i);
							return;
						}
					}
				}
			};
			funcSet = true;
			return;
		}
		break;
	case GUI_Type_DebugMouse::EWINDOWS_PATHFINDING_EDIT:
		// Move Pathfinding start pos
		if (pGuiFlags->pathFindingEdit.bMoveStart)
		{
			MouseDownLeft = [this]()
			{
				Vector2 v2MousePos = CameraManager::GetInstance()->GetWorldMousePos();
				TerrainTile* pTile = m_pMap->GetTileByPos(v2MousePos);

				if (pTile)
				{
					m_v2PathStart = v2MousePos;
				}
			};
			funcSet = true;
			return;
		}
		// Move Pathfinding end pos
		else if (pGuiFlags->pathFindingEdit.bMoveEnd)
		{
			MouseDownLeft = [this]()
			{
				Vector2 v2MousePos = CameraManager::GetInstance()->GetWorldMousePos();
				TerrainTile* pTile = m_pMap->GetTileByPos(v2MousePos);

				if (pTile)
				{
					m_v2PathEnd = v2MousePos;
				}
			};
			funcSet = true;
			return;
		}
		break;
	case GUI_Type_DebugMouse::EWINDOWS_MISC_EDIT:
		break;
	default:
		break;
	}

	// No Custom Functions applicable
	// Set to default
	MouseDownLeft = []() {};
}
