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
	m_pGuiFlags->bFlagChange = false;

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
		if (ImGui::Button("StaticObject Place"))
		{
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_STATICOBJECT_PLACE;
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
		case EWINDOWS_STATICOBJECT_PLACE:
			selected = "StaticObject Place";
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
			m_pGuiFlags->blockerEdit.bBlock = true;

			m_pGuiFlags->blockerEdit.bUnblock = false;
		}
		if (ImGui::Button("Remove Blocker"))
		{
			m_pGuiFlags->blockerEdit.bUnblock = true;

			m_pGuiFlags->blockerEdit.bBlock = false;
		}
		ImGui::Separator();

		// Currently Selected
		char* selected;

		if (m_pGuiFlags->blockerEdit.bBlock)
			selected = "Place Blocker";
		else if (m_pGuiFlags->blockerEdit.bUnblock)
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

		if (ImGui::Button("Rebuild Heat Map"))
		{
			m_pGuiFlags->heatMapEdit.bRebuildHeatMap = true;
		}
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

		// Object Pathinfinding check
		ImGui::Checkbox("Object Pathfinding", &(m_pGuiFlags->pathFindingEdit.bObjectPathfind));

		if (ImGui::Button("Move Start"))
		{
			m_pGuiFlags->pathFindingEdit.bMoveStart = true;

			m_pGuiFlags->pathFindingEdit.bMoveEnd = false;
			m_pGuiFlags->pathFindingEdit.bChangeTarget = false;
		}

		if (m_pGuiFlags->pathFindingEdit.bObjectPathfind)
		{
			if (ImGui::Button("Change Target"))
			{
				m_pGuiFlags->pathFindingEdit.bChangeTarget = true;

				m_pGuiFlags->pathFindingEdit.bMoveStart = false;
				m_pGuiFlags->pathFindingEdit.bMoveEnd = false;
			}
		}
		else
		{
			if (ImGui::Button("Move End"))
			{
				m_pGuiFlags->pathFindingEdit.bMoveEnd = true;

				m_pGuiFlags->pathFindingEdit.bMoveStart = false;
				m_pGuiFlags->pathFindingEdit.bChangeTarget = false;
			}
		}
		ImGui::Separator();

		// Currently Selected
		char* selected;

		if (m_pGuiFlags->pathFindingEdit.bMoveStart)
			selected = "Move Start";
		else if (m_pGuiFlags->pathFindingEdit.bChangeTarget)
			selected = "Change Target";
		else if (m_pGuiFlags->pathFindingEdit.bMoveEnd)
			selected = "Move End";
		else
			selected = "NONE";

		ImGui::Text("Selected : %s", selected);
		ImGui::Separator();

		if (ImGui::Button("Rebuild Path"))
		{
			m_pGuiFlags->pathFindingEdit.bRebuildPath = true;
		}
		ImGui::Separator();

		if (ImGui::Button("Draw full Path"))
		{
			m_pGuiFlags->pathFindingEdit.bFullPath = true;

			m_pGuiFlags->pathFindingEdit.bStepPath = false;
		}

		if (ImGui::Button("Step through Path"))
		{
			m_pGuiFlags->pathFindingEdit.bStepPath = true;
			++(m_pGuiFlags->pathFindingEdit.nStepCount);

			m_pGuiFlags->pathFindingEdit.bFullPath = false;
		}
		ImGui::SameLine();
		ImGui::Text("Count : %i", m_pGuiFlags->pathFindingEdit.nStepCount);
		ImGui::Separator();

		ImGui::End();

		if (!open)
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_DEFAULT;
	}

	// StaticObject Place Window
	if (m_pGuiFlags->eDebugMouseWindows == EWINDOWS_STATICOBJECT_PLACE)
	{
		bool open = true;

		// Open Window
		ImGui::Begin("StaticObjectPlace##0", &open);

		// CheckBoxes
		ImGui::Text("Choose Edit Type");
		if (ImGui::Button("Place Static Object"))
		{
			m_pGuiFlags->staticObjectPlace.bPlaceObject = true;

			m_pGuiFlags->staticObjectPlace.bRemoveObject = false;
		}
		if (ImGui::Button("Remove Static Object"))
		{
			m_pGuiFlags->staticObjectPlace.bRemoveObject = true;

			m_pGuiFlags->staticObjectPlace.bPlaceObject = false;
		}
		ImGui::Separator();

		// Currently Selected
		char* selected;

		if (m_pGuiFlags->staticObjectPlace.bPlaceObject)
			selected = "Place Static Object";
		else if (m_pGuiFlags->staticObjectPlace.bRemoveObject)
			selected = "Remove Static Object";
		else
			selected = "NONE";

		ImGui::Text("Selected : %s", selected);
		ImGui::Separator();

		ImGui::End();

		if (!open)
		{
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_DEFAULT;
			m_pGuiFlags->staticObjectPlace.bPlaceObject = false;
		}
	}

	// StaticObject Place Window 1
	if (m_pGuiFlags->staticObjectPlace.bPlaceObject)
	{
		// Open Window
		ImGui::Begin("StaticObjectPlace##1", &(m_pGuiFlags->staticObjectPlace.bPlaceObject));

		// CheckBoxes
		ImGui::Text("Choose Type of Object to Place");
		if (ImGui::Button("Place Resource"))
		{
			m_pGuiFlags->staticObjectPlace.bPlaceResource = true;

			m_pGuiFlags->staticObjectPlace.bPlaceWorkStation = false;
			m_pGuiFlags->staticObjectPlace.bPlaceHousing = false;
		}
		ImGui::SameLine();
		if (ImGui::Button("Place WorkStation"))
		{
			m_pGuiFlags->staticObjectPlace.bPlaceWorkStation = true;

			m_pGuiFlags->staticObjectPlace.bPlaceResource = false;
			m_pGuiFlags->staticObjectPlace.bPlaceHousing = false;
		}
		ImGui::SameLine();
		if (ImGui::Button("Place Housing"))
		{
			m_pGuiFlags->staticObjectPlace.bPlaceHousing = true;

			m_pGuiFlags->staticObjectPlace.bPlaceResource = false;
			m_pGuiFlags->staticObjectPlace.bPlaceWorkStation = false;
		}
		ImGui::Separator();

		// IF  Place resource
		if (m_pGuiFlags->staticObjectPlace.bPlaceResource)
		{
			if (ImGui::Button("Grass"))
				m_pGuiFlags->staticObjectPlace.eStaticObjectType = ESTATICOBJECTTYPE_RESOURCE_OBJECT_GRASS;
			ImGui::SameLine();
			if (ImGui::Button("Rock"))
				m_pGuiFlags->staticObjectPlace.eStaticObjectType = ESTATICOBJECTTYPE_RESOURCE_OBJECT_ROCK;
			ImGui::SameLine();
			if (ImGui::Button("Tree"))
				m_pGuiFlags->staticObjectPlace.eStaticObjectType = ESTATICOBJECTTYPE_RESOURCE_OBJECT_TREE;
		}
		// ELSE IF Place Workstation
		else if (m_pGuiFlags->staticObjectPlace.bPlaceWorkStation)
		{
			if (ImGui::Button("Crafter"))
				m_pGuiFlags->staticObjectPlace.eStaticObjectType = ESTATICOBJECTTYPE_BUILDING_CRAFTER;
			ImGui::SameLine();
			if (ImGui::Button("Forge"))
				m_pGuiFlags->staticObjectPlace.eStaticObjectType = ESTATICOBJECTTYPE_BUILDING_FORGE;
			ImGui::SameLine();
			if (ImGui::Button("Stockpile"))
				m_pGuiFlags->staticObjectPlace.eStaticObjectType = ESTATICOBJECTTYPE_BUILDING_STOCKPILE;
		}
		// ELSE IF Place Housing
		else if (m_pGuiFlags->staticObjectPlace.bPlaceHousing)
		{
			if (ImGui::Button("Cabin"))
				m_pGuiFlags->staticObjectPlace.eStaticObjectType = ESTATICOBJECTTYPE_BUILDING_HOUSING_CABIN;
			ImGui::SameLine();
			if (ImGui::Button("Hut"))
				m_pGuiFlags->staticObjectPlace.eStaticObjectType = ESTATICOBJECTTYPE_BUILDING_HOUSING_HUT;
			ImGui::SameLine();
			if (ImGui::Button("Tent"))
				m_pGuiFlags->staticObjectPlace.eStaticObjectType = ESTATICOBJECTTYPE_BUILDING_HOUSING_TENT;
		}
		// ELSE none
		else
			m_pGuiFlags->staticObjectPlace.eStaticObjectType = ESTATICOBJECTTYPE_DEFAULT;

		// Currently Selected
		char* selected;

		switch (m_pGuiFlags->staticObjectPlace.eStaticObjectType)
		{
		case ESTATICOBJECTTYPE_DEFAULT:
			selected = "NONE";
			break;
		case ESTATICOBJECTTYPE_RESOURCE_OBJECT_GRASS:
			selected = "Grass";
			break;
		case ESTATICOBJECTTYPE_RESOURCE_OBJECT_ROCK:
			selected = "Rock";
			break;
		case ESTATICOBJECTTYPE_RESOURCE_OBJECT_TREE:
			selected = "Tree";
			break;
		case ESTATICOBJECTTYPE_BUILDING_CRAFTER:
			selected = "Crafter";
			break;
		case ESTATICOBJECTTYPE_BUILDING_FORGE:
			selected = "Forge";
			break;
		case ESTATICOBJECTTYPE_BUILDING_STOCKPILE:
			selected = "Stockpile";
			break;
		case ESTATICOBJECTTYPE_BUILDING_HOUSING_CABIN:
			selected = "Cabin";
			break;
		case ESTATICOBJECTTYPE_BUILDING_HOUSING_HUT:
			selected = "Hut";
			break;
		case ESTATICOBJECTTYPE_BUILDING_HOUSING_TENT:
			selected = "Tent";
			break;
		default:
			selected = "NONE";
			break;
		}

		ImGui::Separator();
		ImGui::Text("Selected : %s", selected);
		ImGui::Separator();

		ImGui::End();
	}

	// Misc Edit Window
	if (m_pGuiFlags->eDebugMouseWindows == EWINDOWS_MISC_EDIT)
	{
		bool open = true;

		// Open Window
		ImGui::Begin("MiscEdit##0", &open);

		ImGui::Separator();
		ImGui::Checkbox("Draw Terrain", &(m_pGuiFlags->miscEdit.bDrawTerrain));
		ImGui::Checkbox("Draw Static Objects", &(m_pGuiFlags->miscEdit.bDrawStaticObjects));
		ImGui::Checkbox("Draw Agents", &(m_pGuiFlags->miscEdit.bDrawAgents));
		ImGui::Separator();
		ImGui::Checkbox("Draw Connections", &(m_pGuiFlags->miscEdit.bDrawConnections));
		ImGui::Checkbox("Draw Pathfinding", &(m_pGuiFlags->miscEdit.bDrawPathfinding));
		ImGui::Checkbox("Draw Flow Fields", &(m_pGuiFlags->miscEdit.bDrawFlowFields));
		ImGui::Separator();

		ImGui::End();

		if (!open)
			m_pGuiFlags->eDebugMouseWindows = EWINDOWS_DEFAULT;
	}
}
