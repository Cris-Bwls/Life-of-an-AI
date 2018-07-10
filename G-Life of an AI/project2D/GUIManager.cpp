#include "GUIManager.h"

#include "BaseGUI.h"
#include "DebugBasicGUI.h"
#include "DebugMouseGUI.h"

GUIManager* GUIManager::m_pInstance = nullptr;

GUIManager::GUIManager()
{
	m_pGuiFlags = new GUIFlags();

	m_AllGUI.push_back(new DebugBasicGUI);
	m_AllGUI.back()->Setup(m_pGuiFlags);
	m_AllGUI.push_back(new DebugMouseGUI);
	m_AllGUI.back()->Setup(m_pGuiFlags);
}


GUIManager::~GUIManager()
{
	while (m_AllGUI.size() > 0)
	{
		delete m_AllGUI.back();
		m_AllGUI.pop_back();
	}
}


void GUIManager::Create()
{
	if (m_pInstance == nullptr)
	{
		m_pInstance = new GUIManager();
	}
}

void GUIManager::Destroy()
{
	if (m_pInstance != nullptr)
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}
}

GUIManager* GUIManager::GetInstance()
{
	return m_pInstance;
}

void GUIManager::AddActiveGUI(EGuiType eGuiType)
{
	m_ActiveGUI.push_back(m_AllGUI[eGuiType]);
}

void GUIManager::RemoveActiveGUI(EGuiType eGuiType)
{
	auto iter = m_ActiveGUI.begin();

	for (int i = 0; i < m_ActiveGUI.size(); ++i)
	{
		++iter;
		if (eGuiType == m_ActiveGUI[i]->m_EGuiType)
		{
			m_ActiveGUI.erase(iter);
			return;
		}
	}
}

void GUIManager::ClearActiveGUI()
{
	m_ActiveGUI.clear();
}

void GUIManager::Update()
{
	for (int i = 0; i < m_ActiveGUI.size(); ++i)
	{
		m_ActiveGUI[i]->Update();
	}
}

void GUIManager::Draw()
{
	for (int i = 0; i < m_ActiveGUI.size(); ++i)
	{
		m_ActiveGUI[i]->Draw();
	}
}
