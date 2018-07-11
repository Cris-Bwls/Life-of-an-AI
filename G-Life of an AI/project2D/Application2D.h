#pragma once
#include "Terrain.h"
#include "Application.h"
#include "Renderer2D.h"
#include <functional>

class Application2D : public aie::Application {
public:

	Application2D();
	virtual ~Application2D();

	virtual bool startup();
	virtual void shutdown();

	virtual void update(float deltaTime);
	virtual void draw();

	void SetMouseDownLeft();
protected:

	std::function<void()> MouseDownLeft = []() {};

	Vector2 m_v2PathStart;
	Vector2 m_v2PathEnd;
	std::vector<Vector2> m_HeatSourceList;

	Terrain* m_pMap;
	std::vector<Vector2> m_path;

	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;

	float m_timer;
};