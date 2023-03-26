#include "BT_DECO_CONDITION_NOT_ENOUGH_HATCHERY.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_NOT_ENOUGH_HATCHERY::BT_DECO_CONDITION_NOT_ENOUGH_HATCHERY(std::string name, BT_NODE* parent)
	: BT_DECO_CONDITION(name, parent, IsThereNotEnoughHatchery)
{
}


std::string BT_DECO_CONDITION_NOT_ENOUGH_HATCHERY::GetDescription()
{
	return "DECO_CONDITION_NOT_ENOUGH_SUPPLY";
}

bool BT_DECO_CONDITION_NOT_ENOUGH_HATCHERY::IsThereNotEnoughHatchery(void* data)
{
	Data* pData = (Data*)data;

	return (BWAPI::Broodwar->self()->minerals() > 350);
}
