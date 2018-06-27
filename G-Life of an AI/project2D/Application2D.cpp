#include "Application2D.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"

#include <iostream>

Application2D::Application2D() {

}

Application2D::~Application2D() {

}

bool Application2D::startup() {
	
	m_2dRenderer = new aie::Renderer2D();

	m_font = new aie::Font("./font/consolas.ttf", 32);
	
	m_cameraX = 0;
	m_cameraY = 0;
	m_timer = 0;

	return true;
}

void Application2D::shutdown() {
	
	delete m_font;
	delete m_2dRenderer;
}

void Application2D::update(float deltaTime) {

	m_timer += deltaTime;

	// input example
	aie::Input* input = aie::Input::getInstance();
	
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

	// DEBUG

	// Scroll wheel testing
	printf("Scroll Wheel: %f\n", (float)input->getMouseScroll());
	system("cls");
}

void Application2D::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// set the camera position before we begin rendering
	m_2dRenderer->setCameraPos(m_cameraX, m_cameraY);

	// begin drawing sprites
	m_2dRenderer->begin();

	bool coloured = true;
	for (int i = 0; i < 100; ++i)
	{
		for (int j = 0; j < 200; ++j)
		{
			float xPos = (j * 32) + 16;
			float yPos = (i * 32) + 16;

			if (coloured)
			{
				coloured = !coloured;
				m_2dRenderer->setRenderColour(0xFF0000FF);
			}
			else
			{
				coloured = !coloured;
				m_2dRenderer->setRenderColour(0x00FF00FF);
			}

			m_2dRenderer->drawBox(xPos, yPos, 32.0f, 32.0f);
		}
		coloured = !coloured;
	}
	m_2dRenderer->setRenderColour(0xFFFFFFFF);
	// output some text, uses the last used colour
	char fps[32];
	sprintf_s(fps, 32, "FPS: %i", getFPS());
	m_2dRenderer->drawText(m_font, fps, 0, 720 - 32);
	m_2dRenderer->drawText(m_font, "Press ESC to quit!", 0, 720 - 64);

	// done drawing sprites
	m_2dRenderer->end();
}