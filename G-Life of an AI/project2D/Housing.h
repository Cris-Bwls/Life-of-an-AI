#pragma once
#include "Building.h"
class Housing :
	public Building
{
public:
	Housing();
	virtual ~Housing();

	inline bool GetIsFull() { return m_bIsFull; };

protected:
	bool m_bIsFull;
	int m_nMaxOccupants;
	int m_nCurrentOccupants;

};

