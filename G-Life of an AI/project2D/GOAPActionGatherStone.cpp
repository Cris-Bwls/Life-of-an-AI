#include "GOAPActionGatherStone.h"



GOAPActionGatherStone::GOAPActionGatherStone()
{
	m_ActionName = "GOAPActionGatherStone";

	m_PreConditionList.push_back(WorldStateProperty(EGOAPSYMBOL_ROCK_EXISTS, true));

	m_EffectList.push_back(EGOAPSYMBOL_HAVE_STONE);

}


GOAPActionGatherStone::~GOAPActionGatherStone()
{
}
