#include "AI.h"

#include "GOAPActionBase.h"
#include <typeinfo>

AI::AI()
{
}


AI::~AI()
{
	while (m_ActionList.size() > 0)
	{
		delete m_ActionList.back();
		m_ActionList.pop_back();
	}
}

void AI::AddAction(GOAPActionBase* pAction)
{
	for (int i = 0; i < m_ActionList.size(); ++i)
	{
		if (typeid(*(m_ActionList[i])).hash_code() == typeid(*(pAction)).hash_code())
			return;
	}

	m_ActionList.push_back(pAction);
}
