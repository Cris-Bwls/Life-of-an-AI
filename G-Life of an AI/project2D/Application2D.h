#pragma once
#include "Terrain.h"
#include "Application.h"
#include "Renderer2D.h"

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

protected:

	Terrain* m_pMap;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	float m_cameraX, m_cameraY;
	float m_timer;

	int m_MouseScroll = 0;
	float m_Scroll = 0.0f;
};