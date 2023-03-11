#include "BT_DECO_CONDITION_NOT_ENOUGH_MUTALISKS.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_NOT_ENOUGH_MUTALISKS::BT_DECO_CONDITION_NOT_ENOUGH_MUTALISKS(std::string name, BT_NODE* parent)
	: BT_DECO_CONDITION(name, parent, IsThereNotEnoughMutalisks)
{
}


std::string BT_DECO_CONDITION_NOT_ENOUGH_MUTALISKS::GetDescription()
{
	return "BT_DECO_CONDITION_NOT_ENOUGH_MUTALISKS";
}

bool BT_DECO_CONDITION_NOT_ENOUGH_MUTALISKS::IsThereNotEnoughMutalisks(void* data)
{
	Data* pData = (Data*)data;

	switch (pData->phase)
	{
		default:
			break;
		case 0:
		case 1:
		case 2:
		case 3:
			return false;
	}

	const BWAPI::UnitType unitType = BWAPI::UnitTypes::Zerg_Mutalisk;
	const int mutaliskOwned = Tools::CountUnitsOfType(unitType, BWAPI::Broodwar->self()->getUnits());

	return mutaliskOwned < pData->nWantedMutalisksTotal;
}
