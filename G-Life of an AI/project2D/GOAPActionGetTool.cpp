#include "GOAPActionGetTool.h"



GOAPActionGetTool::GOAPActionGetTool()
{
	m_ActionName = "GOAPActionGetTool";

	//PreConditions
	m_PreConditions[EGOAPSYMBOL_AVAILABLE_TOOL] = true;

	//Effects
	m_Effects[EGOAPSYMBOL_HAVE_TOOL] = true;
}


GOAPActionGetTool::~GOAPActionGetTool()
{
}