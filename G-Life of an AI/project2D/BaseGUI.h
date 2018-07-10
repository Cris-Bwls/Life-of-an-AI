#pragma once

#include "EGuiType.h"
#include "GuiFlags.h"

#include <imgui.h>
#include <imgui_glfw3.h>

class BaseGUI
{
public:
	BaseGUI();
	virtual ~BaseGUI();

	virtual void Setup(GUIFlags* pGuiFlags = nullptr);
	virtual void Update() = 0;
	virtual void Draw() = 0;

	GUIFlags* m_pGuiFlags;
	EGuiType m_EGuiType = EGUITYPE_TOTAL;
};

