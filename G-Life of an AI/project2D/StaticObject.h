#pragma once
#include "GameObject.h"
class StaticObject :
	public GameObject
{
public:
	StaticObject();
	virtual ~StaticObject();

	inline bool GetIsBlocker() { return m_bIsBlocker; }
protected:
	bool m_bIsBlocker;
};

