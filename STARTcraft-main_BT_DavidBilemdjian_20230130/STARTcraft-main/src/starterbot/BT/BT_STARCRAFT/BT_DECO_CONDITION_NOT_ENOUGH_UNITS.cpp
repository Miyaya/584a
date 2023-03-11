#include "BT_DECO_CONDITION_NOT_ENOUGH_UNITS.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_NOT_ENOUGH_UNITS::BT_DECO_CONDITION_NOT_ENOUGH_UNITS(std::string name, BT_NODE* parent)
	: BT_DECO_CONDITION(name, parent, IsThereNotEnoughUnits)
{
}


std::string BT_DECO_CONDITION_NOT_ENOUGH_UNITS::GetDescription()
{
	return "BT_DECO_CONDITION_NOT_ENOUGH_UNITS";
}

bool BT_DECO_CONDITION_NOT_ENOUGH_UNITS::IsThereNotEnoughUnits(void* data)
{
	Data* pData = (Data*)data;

	const int zerglingsOwned = Tools::CountUnitsOfType(BWAPI::UnitTypes::Zerg_Zergling, BWAPI::Broodwar->self()->getUnits());
	const int mutalisksOwned = Tools::CountUnitsOfType(BWAPI::UnitTypes::Zerg_Mutalisk, BWAPI::Broodwar->self()->getUnits());

	return zerglingsOwned < pData->nWantedZerglingsTotal || mutalisksOwned < pData->nWantedMutalisksTotal;
}
