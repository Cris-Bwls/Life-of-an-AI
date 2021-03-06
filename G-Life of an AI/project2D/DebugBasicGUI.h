#pragma once
#include "BaseGUI.h"
class DebugBasicGUI :
	public BaseGUI
{
public:
	DebugBasicGUI();
	~DebugBasicGUI();


	void Setup();
	void Update();
	void Draw();

private:
	bool show_demo_window = true;
	bool show_another_window = false;
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);
};

