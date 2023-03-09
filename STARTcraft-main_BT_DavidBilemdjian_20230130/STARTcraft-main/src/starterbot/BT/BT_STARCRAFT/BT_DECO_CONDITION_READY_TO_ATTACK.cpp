#include "BT_DECO_CONDITION_READY_TO_ATTACK.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_READY_TO_ATTACK::BT_DECO_CONDITION_READY_TO_ATTACK(std::string name, BT_NODE* parent)
	: BT_DECO_CONDITION(name, parent, IsReadyToAttack)
{
}


std::string BT_DECO_CONDITION_READY_TO_ATTACK::GetDescription()
{
	return "BT_DECO_CONDITION_READY_TO_ATTACK";
}

bool BT_DECO_CONDITION_READY_TO_ATTACK::IsReadyToAttack(void* data)
{
	Data* pData = (Data*)data;

	const BWAPI::UnitType zerglings = BWAPI::UnitTypes::Zerg_Zergling;
	const int zerglingsOwned = Tools::CountUnitsOfType(zerglings, BWAPI::Broodwar->self()->getUnits());
	switch (pData->phase)
	{
		default:
			return false;
		case 0:
			return false;
		case 1:
			if (zerglingsOwned >= pData->nWantedZerglingsTotal)
			{
				pData->phase = 2;
				pData->nWantedWorkersTotal = 12;
				pData->thresholdSupply = 1;
				return true;
			}
			return false;
		case 2:
			if (zerglingsOwned >= pData->nWantedZerglingsTotal)
			{
				pData->phase = 2;
				pData->nWantedWorkersTotal = 16;
				pData->thresholdSupply = 2;
				return true;
			}
			return false;
	}
}