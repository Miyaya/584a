#include "BT_ACTION_BUILD_SPIRE.h"
#include "../../Tools.h"
#include "../Data.h"

BT_ACTION_BUILD_SPIRE::BT_ACTION_BUILD_SPIRE(std::string name, BT_NODE* parent)
	: BT_ACTION(name, parent)
{
}

BT_NODE::State BT_ACTION_BUILD_SPIRE::Evaluate(void* data)
{
	return ReturnState(BuildSpire(data));
}

std::string BT_ACTION_BUILD_SPIRE::GetDescription()
{
	return "BUILD EXTRACTOR";
}


BT_NODE::State BT_ACTION_BUILD_SPIRE::BuildSpire(void* data)
{
	Data* pData = (Data*)data;

	// let's build a spire
	const BWAPI::UnitType unitType = BWAPI::UnitTypes::Zerg_Spire;

	const bool startedBuilding = Tools::BuildBuilding(unitType);

	if (startedBuilding)
		BWAPI::Broodwar->printf("Started Building %s", unitType.getName().c_str());

	return startedBuilding ? BT_NODE::SUCCESS : BT_NODE::FAILURE;
}