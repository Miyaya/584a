#include "BT_DECO_CONDITION_NOT_ENOUGH_SPIRE.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_NOT_ENOUGH_SPIRE::BT_DECO_CONDITION_NOT_ENOUGH_SPIRE(std::string name, BT_NODE* parent)
	: BT_DECO_CONDITION(name, parent, IsThereNotEnoughSpire)
{
}


std::string BT_DECO_CONDITION_NOT_ENOUGH_SPIRE::GetDescription()
{
	return "BT_DECO_CONDITION_NOT_ENOUGH_SPIRE";
}

bool BT_DECO_CONDITION_NOT_ENOUGH_SPIRE::IsThereNotEnoughSpire(void* data)
{
	Data* pData = (Data*)data;

	switch (pData->phase)
	{
		default:
			break;
		case 0:
		case 1:
		case 2:
			return false;
	}

	if (BWAPI::Broodwar->self()->minerals() < 200 ||
		BWAPI::Broodwar->self()->gas() < 150)
		return false;

	// Get the amount of spawning pool we currently have
	const BWAPI::UnitType unitType = BWAPI::UnitTypes::Zerg_Spire;
	const int spireOwned = Tools::CountUnitsOfType(unitType, BWAPI::Broodwar->self()->getUnits());

	if (spireOwned < pData->nWantedSpireTotal)
		return true;

	if (pData->phase < 4)
		pData->phase = 4;
	return false;

}
