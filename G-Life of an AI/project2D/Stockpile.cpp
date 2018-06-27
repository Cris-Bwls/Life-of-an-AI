#include "Stockpile.h"
#include "ResourceComponent.h"

Stockpile::Stockpile()
{
	m_BuildCost->nWood = 10;
	m_fBuildTime = 20.0f;

	m_pResourceStockpile = new ResourceComponent();
}


Stockpile::~Stockpile()
{
	delete m_pResourceStockpile;
}
