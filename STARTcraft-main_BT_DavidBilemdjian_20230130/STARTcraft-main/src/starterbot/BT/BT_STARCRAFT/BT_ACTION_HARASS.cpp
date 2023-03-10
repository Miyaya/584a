#include "BT_ACTION_HARASS.h"
#include "../../Tools.h"
#include "../Data.h"
#include <set>

BT_ACTION_HARASS::BT_ACTION_HARASS(std::string name, BT_NODE* parent)
	: BT_ACTION(name, parent)
{
}

BT_NODE::State BT_ACTION_HARASS::Evaluate(void* data)
{
	return ReturnState(Harass(data));
}

std::string BT_ACTION_HARASS::GetDescription()
{
	return "HARASS";
}


BT_NODE::State BT_ACTION_HARASS::Harass(void* data)
{
	Data* pData = (Data*)data;


	BWAPI::Unitset zerglings;
	BWAPI::Unitset enemyUnits = BWAPI::Broodwar->enemy()->getUnits();

	for (auto& unit : BWAPI::Broodwar->self()->getUnits())
		if (unit->getType() == BWAPI::UnitTypes::Zerg_Zergling)
			zerglings.insert(unit);

	for (auto& unit : zerglings)
		if (unit->getLastCommand().getType() == BWAPI::UnitCommandTypes::Attack_Unit && unit->isVisible())
			continue;
		else if (unit->getLastCommand().getType() == BWAPI::UnitCommandTypes::Patrol)
			continue;
		else
			unit->patrol(pData->enemyLocation);

	//_sleep(10);

	if (zerglings.empty())
		return BT_NODE::SUCCESS;
	return BT_NODE::FAILURE;
}