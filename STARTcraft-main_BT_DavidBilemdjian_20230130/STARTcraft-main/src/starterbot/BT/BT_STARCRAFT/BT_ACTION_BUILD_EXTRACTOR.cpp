#include "BT_ACTION_BUILD_EXTRACTOR.h"
#include "../../Tools.h"
#include "../Data.h"

BT_ACTION_BUILD_EXTRACTOR::BT_ACTION_BUILD_EXTRACTOR(std::string name, BT_NODE* parent)
	: BT_ACTION(name, parent)
{
}

BT_NODE::State BT_ACTION_BUILD_EXTRACTOR::Evaluate(void* data)
{
	return ReturnState(BuildExtractor(data));
}

std::string BT_ACTION_BUILD_EXTRACTOR::GetDescription()
{
	return "BUILD EXTRACTOR";
}


BT_NODE::State BT_ACTION_BUILD_EXTRACTOR::BuildExtractor(void* data)
{
	Data* pData = (Data*)data;

	// let's build a spawning pool
	const BWAPI::UnitType unitType = BWAPI::UnitTypes::Zerg_Extractor;

	const bool startedBuilding = Tools::BuildBuilding(unitType);

	if (startedBuilding)
	{
		BWAPI::Broodwar->printf("Started Building %s", unitType.getName().c_str());
		if (pData->thresholdSupply < 1)
			pData->thresholdSupply = 1;
	}

	return startedBuilding ? BT_NODE::SUCCESS : BT_NODE::FAILURE;
}