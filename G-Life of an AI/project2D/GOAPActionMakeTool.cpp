#include "GOAPActionMakeTool.h"



GOAPActionMakeTool::GOAPActionMakeTool()
{
	m_ActionName = "GOAPActionMakeTool";

	//PreConditions
	m_PreConditions[EGOAPSYMBOL_HAVE_WOOD] = true;
	m_PreConditions[EGOAPSYMBOL_HAVE_STONE] = true;

	//Effects
	m_Effects[EGOAPSYMBOL_AVAILABLE_TOOL] = true;
}


GOAPActionMakeTool::~GOAPActionMakeTool()
{
}