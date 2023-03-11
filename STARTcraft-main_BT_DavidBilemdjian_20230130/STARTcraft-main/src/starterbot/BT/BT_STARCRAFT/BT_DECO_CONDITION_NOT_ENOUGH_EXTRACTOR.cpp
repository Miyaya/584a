#include "BT_DECO_CONDITION_NOT_ENOUGH_EXTRACTOR.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_NOT_ENOUGH_EXTRACTOR::BT_DECO_CONDITION_NOT_ENOUGH_EXTRACTOR(std::string name, BT_NODE* parent)
	: BT_DECO_CONDITION(name, parent, IsThereNotEnoughExtractor)
{
}


std::string BT_DECO_CONDITION_NOT_ENOUGH_EXTRACTOR::GetDescription()
{
	return "DECO_CONDITION_NOT_EXTRACTOR";
}

bool BT_DECO_CONDITION_NOT_ENOUGH_EXTRACTOR::IsThereNotEnoughExtractor(void* data)
{
	Data* pData = (Data*)data;

	switch (pData->phase)
	{
		default:
			break;
		case 0:
			return false;
	}

	if (BWAPI::Broodwar->self()->minerals() < 50)
		return false;

	// Get the amount of extractor we currently have
	const BWAPI::UnitType unitType = BWAPI::UnitTypes::Zerg_Extractor;
	const int extractorOwned = Tools::CountUnitsOfType(unitType, BWAPI::Broodwar->self()->getUnits());

	if (extractorOwned < pData->nWantedExtractorTotal)
		return true;
	
	if (pData->phase < 2)
		pData->phase = 2;

	return false;

}
