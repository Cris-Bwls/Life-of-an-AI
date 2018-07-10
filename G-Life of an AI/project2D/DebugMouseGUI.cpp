#include "DebugMouseGUI.h"
#include "CameraManager.h"

DebugMouseGUI::DebugMouseGUI()
{
	m_EGuiType = EGUITYPE_DEBUG_MOUSE;
}


DebugMouseGUI::~DebugMouseGUI()
{
}

void DebugMouseGUI::Setup(GUIFlags* pGuiFlags)
{
	m_pGuiFlags = pGuiFlags;
}

void DebugMouseGUI::Update()
{
}

void DebugMouseGUI::Draw()
{
	// 1. Show a simple window.
	// Tip: if we don't call ImGui::Begin()/ImGui::End() the widgets automatically appears in a window called "Debug".
	{
		ImGui::Begin("DebugMouseGUI##0");
		ImGui::Text("%.1f FPS", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		
		
		bool a;
		ImGui::Checkbox("ChangeTerrain", &(a));

		ImGui::Text("Mouse Position");                           // Display some text (you can use a format string too)  

		Vector2 mousePos = CameraManager::GetInstance()->GetWorldMousePos();

		ImGui::Text("X Pos = %f", mousePos.x);
		ImGui::SameLine();
		ImGui::Text("Y Pos = %f", mousePos.y);

		
		ImGui::End();
	}

	// 2. Show another simple window. In most cases you will use an explicit Begin/End pair to name your windows.
	if (show_another_window)
	{
		ImGui::Begin("DebugMouseGUI##1", &show_another_window);
		ImGui::Text("Hello from another window!");
		if (ImGui::Button("Close Me"))
			show_another_window = false;
		ImGui::End();
	}

	// 3. Show the ImGui demo window. Most of the sample code is in ImGui::ShowDemoWindow(). Read its code to learn more about Dear ImGui!
	if (show_demo_window)
	{
		ImGui::SetNextWindowPos(ImVec2(650, 20), ImGuiSetCond_FirstUseEver); // Normally user code doesn't need/want to call this because positions are saved in .ini file anyway. Here we just want to make the demo initial state a bit more friendly!
		//ImGui::ShowTestWindow(&show_demo_window);
	}
}
