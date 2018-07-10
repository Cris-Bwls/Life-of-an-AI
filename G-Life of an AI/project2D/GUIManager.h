#pragma once

#include <vector>
#include "EGuiType.h"
#include "GuiFlags.h"

class BaseGUI;

class GUIManager
{
public:
	static void Create();
	static void Destroy();
	static GUIManager* GetInstance();

	GUIFlags* GetGuiFlags() { return m_pGuiFlags; };

	void AddActiveGUI(EGuiType eGuiType);
	void RemoveActiveGUI(EGuiType eGuiType);
	void ClearActiveGUI();

	void Update();
	void Draw();

private:
	GUIManager();
	~GUIManager();

	static GUIManager* m_pInstance;

	GUIFlags* m_pGuiFlags;

	std::vector<BaseGUI*> m_AllGUI;
	std::vector<BaseGUI*> m_ActiveGUI;
};

