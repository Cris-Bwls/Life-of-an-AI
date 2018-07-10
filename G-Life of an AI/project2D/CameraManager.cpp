#include "CameraManager.h"
#include "Input.h"
#include "Application2D.h"

CameraManager* CameraManager::m_pInstance = nullptr;

CameraManager::CameraManager()
{
	m_v2CameraPos.Zero();
	m_nMouseScroll = 0;
	m_fScroll = 0.0f;
	m_fCameraScale = 1.0f;
}

CameraManager::~CameraManager()
{

}

void CameraManager::Create()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new CameraManager();
	}
}

void CameraManager::Destroy()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

CameraManager* CameraManager::GetInstance()
{
	return m_pInstance;
}

void CameraManager::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();

	// Zoom
	if (m_nMouseScroll == (int)input->getMouseScroll())
	{
		m_fScroll = 0.0f;
	}
	else if (m_nMouseScroll > (int)input->getMouseScroll())
	{
		m_nMouseScroll = (int)input->getMouseScroll();
		m_fScroll = 0.1f;
	}
	else if (m_nMouseScroll < (int)input->getMouseScroll())
	{
		m_nMouseScroll = (int)input->getMouseScroll();
		m_fScroll = -0.1f;
	}

	// use arrow keys to move camera

	if (input->isKeyDown(aie::INPUT_KEY_UP))
		m_v2CameraPos.y += 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		m_v2CameraPos.y -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_LEFT))
		m_v2CameraPos.x -= 500.0f * deltaTime;

	if (input->isKeyDown(aie::INPUT_KEY_RIGHT))
		m_v2CameraPos.x += 500.0f * deltaTime;

	// Store Screen Mouse Pos
	int nMouseX, nMouseY;
	input->getMouseXY(&nMouseX, &nMouseY);
	
	m_MousePos.x = (float)nMouseX;
	m_MousePos.y = (float)nMouseY;
}

void CameraManager::Draw(aie::Renderer2D* pRenderer2D)
{
	// set the camera position before we begin rendering
	pRenderer2D->setCameraPos(m_v2CameraPos.x, m_v2CameraPos.y);

	// Set Camera Zoom Level (camera Scale)
	m_fCameraScale += m_fScroll;

	if (m_fCameraScale < 0.1f)
		m_fCameraScale = 0.1f;

	else if (m_fCameraScale > 10.0f)
		m_fCameraScale = 10.0f;

	pRenderer2D->setCameraScale(m_fCameraScale);
}

// Courtesy of Cameron Brown
Vector2 CameraManager::GetWorldMousePos()
{
	float fScreenWidth = (float)m_pApp2d->getWindowWidth();
	float fScreenHeight = (float)m_pApp2d->getWindowHeight();

	float fXPercentage = m_MousePos.x / fScreenWidth;
	float fYPercentage = m_MousePos.y / fScreenHeight;

	float fScaledWidth = fScreenWidth * m_fCameraScale;
	float fScaledHeight = fScreenHeight * m_fCameraScale;

	float fMidX = m_v2CameraPos.x + (fScreenWidth / 2.0f);
	float fMidY = m_v2CameraPos.y + (fScreenHeight / 2.0f);

	float fLeft = fMidX - (fScaledWidth / 2.0f);
	float fBottom = fMidY - (fScaledHeight / 2.0f);

	Vector2 OutMousePos;

	OutMousePos.x = fLeft + (fXPercentage * fScaledWidth);
	OutMousePos.y = fBottom + (fYPercentage * fScaledHeight);
	
	return OutMousePos;
}