#include "OLD_GOAPActionBase.h"

GOAPActionBase::GOAPActionBase()
{
	m_bUsed = false;
	m_nCost = 10;

	m_nFScore = 0;
	m_nGScore = 0;
	m_nHScore = 0;
}


GOAPActionBase::~GOAPActionBase()
{
}

bool GOAPActionBase::CheckProceduralPreconditions()
{
	return true;
}
