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
	// Main Debug Mouse Window
	{
		ImGui::Begin("DebugMouseGUI##0");
		// Show FPS
		ImGui::Text("%.1f FPS", ImGui::GetIO().Framerate);		
		ImGui::Separator();

		// Editor Checkboxes
		ImGui::Text("Choose Editor");
		ImGui::Checkbox("BlockerEdit", &(m_pGuiFlags->bBlockerEdit));
		ImGui::Checkbox("ChangeTerrain", &(m_pGuiFlags->bChangeTerrain));
		ImGui::Checkbox("HeatMapEdit", &(m_pGuiFlags->bHeatMapEdit));
		ImGui::Checkbox("PathfindingEdit", &(m_pGuiFlags->bPathfindingEdit));
		ImGui::Separator();

		// Mouse Pos
		ImGui::Text("Mouse Position");

		Vector2 mousePos = CameraManager::GetInstance()->GetWorldMousePos();

		ImGui::Text("X Pos = %f", mousePos.x);
		ImGui::SameLine();
		ImGui::Text("Y Pos = %f", mousePos.y);

		
		ImGui::End();

		// Change Editor bools
		if (m_pGuiFlags->bBlockerEdit)
		{
			m_pGuiFlags->bChangeTerrain = false;
			m_pGuiFlags->bHeatMapEdit = false;
			m_pGuiFlags->bPathfindingEdit = false;
		}
		else if (m_pGuiFlags->bChangeTerrain)
		{
			m_pGuiFlags->bBlockerEdit = false;
			m_pGuiFlags->bHeatMapEdit = false;
			m_pGuiFlags->bPathfindingEdit = false;
		}
		else if (m_pGuiFlags->bHeatMapEdit)
		{
			m_pGuiFlags->bBlockerEdit = false;
			m_pGuiFlags->bChangeTerrain = false;
			m_pGuiFlags->bPathfindingEdit = false;
		}
		else if (m_pGuiFlags->bPathfindingEdit)
		{
			m_pGuiFlags->bBlockerEdit = false;
			m_pGuiFlags->bChangeTerrain = false;
			m_pGuiFlags->bHeatMapEdit = false;
		}
	}

	// Blocker Edit Window
	if (m_pGuiFlags->bBlockerEdit)
	{
		// Open Window
		ImGui::Begin("BlockerEdit##0", &(m_pGuiFlags->bBlockerEdit));

		// CheckBoxes
		ImGui::Text("Choose Edit Type");
		ImGui::Checkbox("BlockerEdit", &(m_pGuiFlags->bPlaceBlocker));
		ImGui::Checkbox("ChangeTerrain", &(m_pGuiFlags->bRemoveBlocker));

		if (m_pGuiFlags->bPlaceBlocker)
			m_pGuiFlags->bRemoveBlocker = false;

		if (m_pGuiFlags->bRemoveBlocker)
			m_pGuiFlags->bPlaceBlocker = false;

		ImGui::End();
	}
}
