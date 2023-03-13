#include "BT_DECO_CONDITION_NOT_ENOUGH_SPAWNING_POOL.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_NOT_ENOUGH_SPAWNING_POOL::BT_DECO_CONDITION_NOT_ENOUGH_SPAWNING_POOL(std::string name, BT_NODE* parent)
	: BT_DECO_CONDITION(name, parent, IsThereNotEnoughSpawningPool)
{
}


std::string BT_DECO_CONDITION_NOT_ENOUGH_SPAWNING_POOL::GetDescription()
{
	return "DECO_CONDITION_NOT_ENOUGH_SUPPLY";
}

bool BT_DECO_CONDITION_NOT_ENOUGH_SPAWNING_POOL::IsThereNotEnoughSpawningPool(void* data)
{
	Data* pData = (Data*)data;

	if (BWAPI::Broodwar->self()->minerals() < 200)
		return false;

	// Get the amount of spawning pool we currently have
	const BWAPI::UnitType unitType = BWAPI::UnitTypes::Zerg_Spawning_Pool;
	const int spawningPoolOwned = Tools::CountUnitsOfType(unitType, BWAPI::Broodwar->self()->getUnits());

	if (spawningPoolOwned < pData->nWantedSpawningPoolTotal)
		return true;

	if(!pData->spawningPoolBuilt)
		pData->spawningPoolBuilt = 1;
	return false;

}
