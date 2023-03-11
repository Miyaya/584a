#include "BT_DECO_CONDITION_NOT_ENOUGH_SUPPLY.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_NOT_ENOUGH_SUPPLY::BT_DECO_CONDITION_NOT_ENOUGH_SUPPLY(std::string name, BT_NODE* parent)
    : BT_DECO_CONDITION(name,parent, IsThereNotEnoughSupply) {}


std::string BT_DECO_CONDITION_NOT_ENOUGH_SUPPLY::GetDescription()
{
    return "DECO_CONDITION_NOT_ENOUGH_SUPPLY";
}

bool BT_DECO_CONDITION_NOT_ENOUGH_SUPPLY::IsThereNotEnoughSupply(void *data)
{
    Data* pData = (Data*)data;

    if (BWAPI::Broodwar->self()->minerals() < 100)
        return false;
    else if (pData->morphingOverlord)
        return false;
    else if (Tools::GetTotalSupply(true) - BWAPI::Broodwar->self()->supplyUsed() < pData->thresholdSupply)
        return true;
    else
        pData->morphingOverlord = 0;
    return false;
}
