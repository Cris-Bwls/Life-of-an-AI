#pragma once

#include "Renderer2D.h"
#include "Vector2.h"

class Application2D;

class CameraManager
{
public:
	static void Create();
	static void Destroy();
	static CameraManager* GetInstance();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* pRenderer2D);

	Vector2 GetWorldMousePos();

	// Helper Func
	void SetApp2D(Application2D* pApp2d) { m_pApp2d = pApp2d; }
private:
	CameraManager();
	~CameraManager();

	static CameraManager* m_pInstance;

	Vector2 m_v2CameraPos;
	int m_nMouseScroll = 0;
	float m_fScroll = 0.0f;
	float m_fCameraScale = 1.0f;

	Vector2 m_MousePos;

	Application2D* m_pApp2d;
};

