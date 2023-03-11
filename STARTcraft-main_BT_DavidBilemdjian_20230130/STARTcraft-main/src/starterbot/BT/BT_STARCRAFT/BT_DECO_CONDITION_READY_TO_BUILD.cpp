#include "BT_DECO_CONDITION_READY_TO_BUILD.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_READY_TO_BUILD::BT_DECO_CONDITION_READY_TO_BUILD(std::string name, BT_NODE* parent)
	: BT_DECO_CONDITION(name, parent, IsReadyToBuild)
{
}


std::string BT_DECO_CONDITION_READY_TO_BUILD::GetDescription()
{
	return "DECO_CONDITION_NOT_EXTRACTOR";
}

bool BT_DECO_CONDITION_READY_TO_BUILD::IsReadyToBuild(void* data)
{
	Data* pData = (Data*)data;
	//BWAPI::Broodwar->printf("PHASE: %d", pData->phase);

	if (Tools::CountUnitsOfType(BWAPI::UnitTypes::Zerg_Spawning_Pool, BWAPI::Broodwar->self()->getUnits()))
		pData->thresholdSupply = 1;

	if (!Tools::CountUnitsOfType(BWAPI::UnitTypes::Zerg_Spawning_Pool, BWAPI::Broodwar->self()->getUnits()))
		pData->phase = 0;
	else if (!Tools::CountUnitsOfType(BWAPI::UnitTypes::Zerg_Extractor, BWAPI::Broodwar->self()->getUnits()))
		pData->phase = 1;
	else if (!Tools::CountUnitsOfType(BWAPI::UnitTypes::Zerg_Spire, BWAPI::Broodwar->self()->getUnits()))
		pData->phase = 2;
	else
		pData->phase = 3;

	return pData->phase != 3;

}
