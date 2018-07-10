#include "DebugMouseGUI.h"
#include "CameraManager.h"

using namespace GUI_Type_DebugMouse;

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
		if (ImGui::Button("Blocker Edit"))
		{
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_BLOCKER_EDIT;
		}
		if (ImGui::Button("Change Terrain"))
		{
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_CHANGE_TERRAIN;
		}
		if (ImGui::Button("Heat Map Edit"))
		{
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_HEAT_MAP_EDIT;
		}
		if (ImGui::Button("Pathfinding Edit"))
		{
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_PATHFINDING_EDIT;
		}
		if (ImGui::Button("Misc Edit"))
		{
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_MISC_EDIT;
		}
		ImGui::Separator();

		// Currently Selected
		char* selected;

		switch (m_pGuiFlags->eDebugMouseWindows)
		{
		case EWINDOWS_BLOCKER_EDIT:
			selected = "Blocker Edit";
			break;
		case EWINDOWS_CHANGE_TERRAIN:
			selected = "Change Terrain";
			break;
		case EWINDOWS_HEAT_MAP_EDIT:
			selected = "Heat Map Edit";
			break;
		case EWINDOWS_PATHFINDING_EDIT:
			selected = "Pathfinding Edit";
			break;
		case EWINDOWS_MISC_EDIT:
			selected = "Misc Edit";
			break;
		default:
			selected = "NONE";
			break;
		}

		ImGui::Text("Selected : %s", selected);
		ImGui::Separator();

		// Mouse Pos
		ImGui::Text("Mouse Position");

		Vector2 mousePos = CameraManager::GetInstance()->GetWorldMousePos();

		ImGui::Text("X Pos = %f", mousePos.x);
		ImGui::SameLine();
		ImGui::Text("Y Pos = %f", mousePos.y);

		
		ImGui::End();
	}

	// Blocker Edit Window
	if (m_pGuiFlags->eDebugMouseWindows == EWINDOWS_BLOCKER_EDIT)
	{
		bool open = true;

		// Open Window
		ImGui::Begin("BlockerEdit##0", &open);

		// CheckBoxes
		ImGui::Text("Choose Edit Type");
		if (ImGui::Button("Place Blocker"))
		{
			m_pGuiFlags->blockerEdit.bPlaceBlocker = true;

			m_pGuiFlags->blockerEdit.bRemoveBlocker = false;
		}
		if (ImGui::Button("Remove Blocker"))
		{
			m_pGuiFlags->blockerEdit.bRemoveBlocker = true;

			m_pGuiFlags->blockerEdit.bPlaceBlocker = false;
		}
		ImGui::Separator();

		// Currently Selected
		char* selected;

		if (m_pGuiFlags->blockerEdit.bPlaceBlocker)
			selected = "Place Blocker";
		else if (m_pGuiFlags->blockerEdit.bRemoveBlocker)
			selected = "Remove Blocker";
		else
			selected = "NONE";

		ImGui::Text("Selected : %s", selected);
		ImGui::Separator();

		ImGui::End();

		if (!open)
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_DEFAULT;
	}

	// Change Terrain Window
	if (m_pGuiFlags->eDebugMouseWindows == EWINDOWS_CHANGE_TERRAIN)
	{
		bool open = true;

		// Open Window
		ImGui::Begin("ChangeTerrain##0", &open);

		// CheckBoxes
		ImGui::Text("Choose Edit Type");
		if (ImGui::Button("Place Dirt"))
		{
			m_pGuiFlags->changeTerrain.bPlaceDirt = true;

			m_pGuiFlags->changeTerrain.bPlaceWater = false;
			m_pGuiFlags->changeTerrain.bPlaceMountain = false;
		}
		if (ImGui::Button("Place Water"))
		{
			m_pGuiFlags->changeTerrain.bPlaceWater = true;

			m_pGuiFlags->changeTerrain.bPlaceDirt = false;
			m_pGuiFlags->changeTerrain.bPlaceMountain = false;
		}
		if (ImGui::Button("Place Mountain"))
		{
			m_pGuiFlags->changeTerrain.bPlaceMountain = true;

			m_pGuiFlags->changeTerrain.bPlaceDirt = false;
			m_pGuiFlags->changeTerrain.bPlaceWater = false;
		}
		ImGui::Separator();

		// Currently Selected
		char* selected;

		if (m_pGuiFlags->changeTerrain.bPlaceDirt)
			selected = "Place Dirt";
		else if (m_pGuiFlags->changeTerrain.bPlaceWater)
			selected = "Place Water";
		else if (m_pGuiFlags->changeTerrain.bPlaceMountain)
			selected = "Place Mountain";
		else
			selected = "NONE";

		ImGui::Text("Selected : %s", selected);
		ImGui::Separator();

		ImGui::End();

		if (!open)
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_DEFAULT;
	}

	// Heat Map Edit Window
	if (m_pGuiFlags->eDebugMouseWindows == EWINDOWS_HEAT_MAP_EDIT)
	{
		bool open = true;

		// Open Window
		ImGui::Begin("HeatMapEdit##0", &open);

		// CheckBoxes
		ImGui::Text("Choose Edit Type");
		if (ImGui::Button("Place Heat Source"))
		{
			m_pGuiFlags->heatMapEdit.bPlaceHeatPoint = true;

			m_pGuiFlags->heatMapEdit.bRemoveHeatPoint = false;
		}
		if (ImGui::Button("Remove Heat Source"))
		{
			m_pGuiFlags->heatMapEdit.bRemoveHeatPoint = true;

			m_pGuiFlags->heatMapEdit.bPlaceHeatPoint = false;
		}
		ImGui::Separator();

		// Currently Selected
		char* selected;

		if (m_pGuiFlags->heatMapEdit.bPlaceHeatPoint)
			selected = "Place Heat Source";
		else if (m_pGuiFlags->heatMapEdit.bRemoveHeatPoint)
			selected = "Remove Heat Source";
		else
			selected = "NONE";

		ImGui::Text("Selected : %s", selected);
		ImGui::Separator();

		ImGui::End();

		if (!open)
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_DEFAULT;
	}

	// Pathfinding Edit Window
	if (m_pGuiFlags->eDebugMouseWindows == EWINDOWS_PATHFINDING_EDIT)
	{
		bool open = true;

		// Open Window
		ImGui::Begin("PathfindingEdit##0", &open);

		// CheckBoxes
		ImGui::Text("Choose Edit Type");
		if (ImGui::Button("Move Start"))
		{
			m_pGuiFlags->pathFindingEdit.bMoveStart = true;

			m_pGuiFlags->pathFindingEdit.bMoveEnd = false;
		}
		if (ImGui::Button("Move End"))
		{
			m_pGuiFlags->pathFindingEdit.bMoveEnd = true;

			m_pGuiFlags->pathFindingEdit.bMoveStart = false;
		}
		ImGui::Separator();

		// Currently Selected
		char* selected;

		if (m_pGuiFlags->pathFindingEdit.bMoveStart)
			selected = "Move Start";
		else if (m_pGuiFlags->pathFindingEdit.bMoveEnd)
			selected = "Move End";
		else
			selected = "NONE";

		ImGui::Text("Selected : %s", selected);
		ImGui::Separator();

		ImGui::End();

		if (!open)
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_DEFAULT;
	}
}
