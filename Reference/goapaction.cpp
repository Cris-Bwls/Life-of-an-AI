#include "goapaction.h"

GoapAction::GoapAction()
{
	m_baseCost = 1.0f;
	m_runningCost = 1.0f;
	m_name = "Default Action";
	m_status = ACTION_FAILED;
}

void GoapAction::start()
{
	m_status = ACTION_RUNNING;
}

void GoapAction::perform(float delta)
{
	if (m_status == ACTION_NOT_RUNNING)
		start();
}

void GoapAction::finish()
{
	m_status = ACTION_DONE;
}
