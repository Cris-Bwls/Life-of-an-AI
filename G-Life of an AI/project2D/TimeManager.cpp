#include "TimeManager.h"

TimeManager* TimeManager::m_pInstance = nullptr;

TimeManager::TimeManager()
{
	m_fdeltaTime = 0.0f;
	m_fGameTime = 0.0f;
}

TimeManager::~TimeManager()
{

}

void TimeManager::Create()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new TimeManager();
	}
}

void TimeManager::Destroy()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

TimeManager* TimeManager::GetInstance()
{
	return m_pInstance;
}

void TimeManager::SetTime(float fDeltaTime)
{
	m_fdeltaTime = fDeltaTime;
	m_fGameTime += fDeltaTime;
}

void TimeManager::ResetGameTime()
{
	m_fGameTime = 0.0f;
}

float TimeManager::GetDeltaTime()
{
	return m_fdeltaTime;
}
float TimeManager::GetGameTime()
{
	return m_fGameTime;
}