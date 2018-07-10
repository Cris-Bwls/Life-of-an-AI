#pragma once
#include "BaseGUI.h"

class DebugMouseGUI :
	public BaseGUI
{
public:
	DebugMouseGUI();
	~DebugMouseGUI();

	void Setup(GUIFlags* pGuiFlags);
	void Update();
	void Draw();
};

