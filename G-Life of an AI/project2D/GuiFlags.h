#pragma once

namespace GUI_Type_DebugMouse
{
	enum EWindows
	{
		EWINDOWS_DEFAULT = 0,

		EWINDOWS_BLOCKER_EDIT,
		EWINDOWS_CHANGE_TERRAIN,
		EWINDOWS_HEAT_MAP_EDIT,
		EWINDOWS_PATHFINDING_EDIT,
		EWINDOWS_MISC_EDIT,
		
		EWINDOWS_TOTAL
	};
} // End Namespace GUI_DebugMouse

namespace GUI_Windows
{
	struct BlockerEdit
	{
		bool bPlaceBlocker = false;
		bool bRemoveBlocker = false;
	};

	struct ChangeTerrain
	{
		bool bPlaceDirt = false;
		bool bPlaceWater = false;
		bool bPlaceMountain = false;
	};

	struct HeatMapEdit
	{
		bool bPlaceHeatPoint = false;
		bool bRemoveHeatPoint = false;
		bool bRebuildHeatMap = false;
	};

	struct PathfindingEdit
	{
		bool bMoveStart = false;
		bool bMoveEnd = false;
		bool bRebuildPath = false;
	};
} // End Namespace GUI_Windows

struct GUIFlags
{
	bool bFlagChange = false;

	GUI_Type_DebugMouse::EWindows eDebugMouseWindows = GUI_Type_DebugMouse::EWINDOWS_DEFAULT;
	GUI_Windows::BlockerEdit blockerEdit;
	GUI_Windows::ChangeTerrain changeTerrain;
	GUI_Windows::HeatMapEdit heatMapEdit;
	GUI_Windows::PathfindingEdit pathFindingEdit;
};