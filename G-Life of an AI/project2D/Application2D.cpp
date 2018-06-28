#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

#include <iostream>

//DEBUG
#include <vector>
#include "Vector2.h"

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);

	m_pMap = new Terrain();
	
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_2dRenderer;
	delete m_pMap;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();

	// Zoom
	if (m_MouseScroll == (int)input->getMouseScroll())
	{
		m_Scroll = 0.0f;
	}
	else if (m_MouseScroll > (int)input->getMouseScroll())
	{
		m_MouseScroll = (int)input->getMouseScroll();
		m_Scroll = 0.1f;
	}
	else if (m_MouseScroll < (int)input->getMouseScroll())
	{
		m_MouseScroll = (int)input->getMouseScroll();
		m_Scroll = -0.1f;
	}

	// use arrow keys to move camera

	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_cameraY += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_cameraY -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_cameraX -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_cameraX += 500.0f * deltaTime;
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// Set Camera Zoom Level (camera Scale)
	float scale = m_2dRenderer->getCameraScale();
	scale += m_Scroll;

	if (scale < 0.1f)
		scale = 0.1f;

	if (scale > 10.0f)
		scale = 10.0f;

	m_2dRenderer->setCameraScale(scale);

	// begin drawing sprites
	m_2dRenderer->begin();

	m_pMap->Draw(m_2dRenderer);

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