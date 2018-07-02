#include "CameraManager.h"
#include "Input.h"

CameraManager* CameraManager::m_pInstance = nullptr;

CameraManager::CameraManager()
{
	m_v2CameraPos.Zero();
	m_nMouseScroll = 0;
	m_fScroll = 0.0f;
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
}

void CameraManager::Draw(aie::Renderer2D* pRenderer2D)
{
	// set the camera position before we begin rendering
	pRenderer2D->setCameraPos(m_v2CameraPos.x, m_v2CameraPos.y);

	// Set Camera Zoom Level (camera Scale)
	float scale = pRenderer2D->getCameraScale();
	scale += m_fScroll;

	if (scale < 0.1f)
		scale = 0.1f;

	else if (scale > 10.0f)
		scale = 10.0f;

	pRenderer2D->setCameraScale(scale);
}
