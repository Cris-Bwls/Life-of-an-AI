#pragma once

#include <map>
#include <darray.h>

enum ActionStatus
{
	ACTION_NOT_RUNNING = 0,
	ACTION_RUNNING,
	ACTION_DONE,
	ACTION_FAILED
};

typedef std::map<std::string, bool> NiceMap;

class GoapAction
{
public:
	GoapAction();
	virtual ~GoapAction() = default;

	NiceMap* getPreconditions() { return &m_preconditions; }
	NiceMap* getEffects() { return &m_effects; }

	float getRunningCost() const { return m_runningCost; }
	float getCost() const { return m_baseCost; }
	std::string getName() const { return m_name; }

	ActionStatus getStatus() const { return m_status; }
	void setStatus(ActionStatus status) { m_status = status; }

	void resetRunningCost() { m_runningCost = m_baseCost; }
	void addRunningCost(float c) { m_runningCost += c; }

	DArray<std::string> getCostModifiers() { return m_costModifiers; }

	virtual void start();
	virtual void perform(float delta);
	virtual void finish();

protected:
	NiceMap m_preconditions;
	NiceMap m_effects;

	DArray<std::string> m_costModifiers;

	std::string m_name;

	float m_baseCost;
	float m_runningCost;
	ActionStatus m_status;
};