#pragma once

struct GUIFlags
{
	bool bBlockerEdit = false;
	bool bPlaceBlocker = false;
	bool bRemoveBlocker = false;

	bool bChangeTerrain = false;
	bool bPlaceWater = false;

	bool bHeatMapEdit = false;
	bool bPlaceHeatPoint = false;
	bool bRemoveHeatPoint = false;

	bool bPathfindingEdit = false;
	bool bPlaceStart = false;
	bool bPlaceEnd = false;
};