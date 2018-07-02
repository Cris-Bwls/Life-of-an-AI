#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include "CameraManager.h"

#include <iostream>

//DEBUG
#include <vector>
#include "Vector2.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {

	CameraManager::Create();
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_pMap = new Terrain();
	
	//DEBUG
	m_pMap->ResetAnimalAvoid();
	m_pMap->SetAnimalAvoid(Vector2(300, 300), 20);

	m_timer = 0;

	return true;

	
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_2dRenderer;
	delete m_pMap;

	CameraManager::Destroy();
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	//Update Camera
	CameraManager::GetInstance()->Update(deltaTime);

	// input example
	aie::Input* input = aie::Input::getInstance();
	
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

	if ((int)(getTime()) % 10 > 5)
	{
		auto path = m_pMap->GetPath(Vector2(100, 100), Vector2(300, 200), true);

		m_2dRenderer->setRenderColour(0xFF0000FF);
		for (int i = 0; i < path.size(); ++i)
		{
			m_2dRenderer->drawBox(path[i].x, path[i].y, TILE_SIZE, TILE_SIZE);

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
}