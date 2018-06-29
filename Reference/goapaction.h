#pragma once

#include <map>

class GoapAction
{
public:
	GoapAction();
	virtual ~GoapAction() = default;

	std::map<std::string, bool>* getPreconditions() { return &m_preconditions; }
	std::map<std::string, bool>* getEffects() { return &m_effects; }

	float getCost() { return m_cost; }
	std::string getName() { return m_name; }

protected:
	std::map<std::string, bool> m_preconditions;
	std::map<std::string, bool> m_effects;

	std::string m_name;

	float m_cost;
};