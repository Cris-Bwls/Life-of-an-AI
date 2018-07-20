#pragma once
#include "EStaticObjectType.h"

namespace GUI_Type_DebugMouse
{
	enum EWindows
	{
		EWINDOWS_DEFAULT = 0,

		EWINDOWS_BLOCKER_EDIT,
		EWINDOWS_CHANGE_TERRAIN,
		EWINDOWS_HEAT_MAP_EDIT,
		EWINDOWS_PATHFINDING_EDIT,
		EWINDOWS_STATICOBJECT_PLACE,
		EWINDOWS_MISC_EDIT,
		
		EWINDOWS_TOTAL
	};
} // End Namespace GUI_DebugMouse

namespace GUI_Windows
{
	struct BlockerEdit
	{
		bool bBlock = false;
		bool bUnblock = false;
		bool bForceUnblock = false;
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

		bool bActiveRebuildHeatMap = false;
		bool bRebuildHeatMap = false;

		bool bCursorHeatPoint = false;
	};

	struct PathfindingEdit
	{
		bool bMoveStart = false;
		bool bMoveEnd = false;

		bool bChangeTarget = false;

		bool bObjectPathfind = false;

		bool bRebuildPath = false;
		bool bFullPath = false;
		bool bStepPath = false;
		unsigned int nStepCount = 0;
	};

	struct StaticObjectPlace
	{
		bool bPlaceObject = false;
		bool bRemoveObject = false;

		bool bPlaceResource = false;
		bool bPlaceWorkStation = false;
		bool bPlaceHousing = false;

		EStaticObjectType eStaticObjectType = ESTATICOBJECTTYPE_DEFAULT;
	};

	struct MiscEdit
	{
		bool bDrawTerrain = true;
		bool bDrawStaticObjects = true;
		bool bDrawAgents = true;

		bool bDrawConnections = false;
		bool bDrawPathfinding = false;
		bool bDrawFlowFields = false;
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
	GUI_Windows::StaticObjectPlace staticObjectPlace;
	GUI_Windows::MiscEdit miscEdit;
};