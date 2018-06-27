#pragma once
#include "Building.h"

class Stockpile :
	public Building
{
public:
	Stockpile();
	~Stockpile();

private:
	ResourceComponent* m_pResourceStockpile;
};

