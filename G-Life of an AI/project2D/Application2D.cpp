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

	if (input->isKeyDown(aie::INPUT_KEY_1))
	{
		m_pMap->ResetAnimalAvoid();
		m_pMap->SetAnimalAvoid(Vector2(300, 300), 20);
	}

	if (input->isKeyDown(aie::INPUT_KEY_2))
		m_path = m_pMap->GetPath(Vector2(100, 100), Vector2(300, 200), true);

	if (input->isMouseButtonDown(0))
	{
		Vector2 v2MousePos = CameraManager::GetInstance()->GetWorldMousePos();
		TerrainTile* pTile = m_pMap->GetTileByPos(v2MousePos);

		if (pTile)
		{
			pTile->SetTerrainStats(ETERRAINTYPE_WATER);
		}
	}
	else if (input->isMouseButtonDown(1))
	{
		Vector2 v2MousePos = CameraManager::GetInstance()->GetWorldMousePos();
		TerrainTile* pTile = m_pMap->GetTileByPos(v2MousePos);

		if (pTile)
		{
			pTile->SetTerrainStats(ETERRAINTYPE_DIRT);
		}
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