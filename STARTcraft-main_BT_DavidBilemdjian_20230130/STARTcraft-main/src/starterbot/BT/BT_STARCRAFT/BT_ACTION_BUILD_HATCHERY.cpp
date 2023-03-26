#include "BT_ACTION_BUILD_HATCHERY.h"
#include "../../Tools.h"
#include "../Data.h"

BT_ACTION_BUILD_HATCHERY::BT_ACTION_BUILD_HATCHERY(std::string name, BT_NODE* parent)
	: BT_ACTION(name, parent)
{
}

BT_NODE::State BT_ACTION_BUILD_HATCHERY::Evaluate(void* data)
{
	return ReturnState(BuildHatchery(data));
}

std::string BT_ACTION_BUILD_HATCHERY::GetDescription()
{
	return "BT_ACTION_BUILD_HATCHERY";
}


BT_NODE::State BT_ACTION_BUILD_HATCHERY::BuildHatchery(void* data)
{
	Data* pData = (Data*)data;

	// let's build a hatchery
	const BWAPI::UnitType unitType = BWAPI::UnitTypes::Zerg_Hatchery;
	const bool startedBuilding = Tools::BuildBuilding(unitType);

	if (startedBuilding)
	{
		BWAPI::Broodwar->printf("Started Building %s", unitType.getName().c_str());
		pData->nWantedWorkersTotal += 1;
	}

	return startedBuilding ? BT_NODE::SUCCESS : BT_NODE::FAILURE;
}