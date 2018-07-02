#pragma once

#include "Renderer2D.h"
#include "Vector2.h"

class CameraManager
{
public:
	static void Create();
	static void Destroy();
	static CameraManager* GetInstance();

	void Update(float deltaTime);
	void Draw(aie::Renderer2D* pRenderer2D);
private:
	CameraManager();
	~CameraManager();

	static CameraManager* m_pInstance;

	Vector2 m_v2CameraPos;
	int m_nMouseScroll = 0;
	float m_fScroll = 0.0f;
};

