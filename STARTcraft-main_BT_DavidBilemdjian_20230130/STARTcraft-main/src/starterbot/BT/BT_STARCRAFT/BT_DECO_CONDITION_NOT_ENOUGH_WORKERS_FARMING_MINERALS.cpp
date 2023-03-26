#include "BT_DECO_CONDITION_NOT_ENOUGH_WORKERS_FARMING_MINERALS.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_NOT_ENOUGH_WORKERS_FARMING_MINERALS::BT_DECO_CONDITION_NOT_ENOUGH_WORKERS_FARMING_MINERALS(std::string name, BT_NODE* parent)
    : BT_DECO_CONDITION(name,parent, IsThereNotEnoughWorkersFarmingMinerals) {}


std::string BT_DECO_CONDITION_NOT_ENOUGH_WORKERS_FARMING_MINERALS::GetDescription()
{
    return "DECO_CONDITION_NOT_ENOUGH_WORKERS_FARMING_MINERALS";
}

bool BT_DECO_CONDITION_NOT_ENOUGH_WORKERS_FARMING_MINERALS::IsThereNotEnoughWorkersFarmingMinerals(void *data)
{
    Data* pData = (Data*)data;

	if ((BWAPI::Broodwar->self()->gas() >= 100) && (BWAPI::Broodwar->self()->minerals() >= 100))
	{
		for (auto& unit : BWAPI::Broodwar->self()->getUnits())
			if (unit->getType() == BWAPI::UnitTypes::Zerg_Spawning_Pool)
			{
				unit->upgrade(BWAPI::UpgradeTypes::Metabolic_Boost);
				pData->upgradeFinished = 1;
				break;
			}

		for (auto& unit : pData->unitsFarmingGas)
			unit->stop();

		pData->nWantedWorkersFarmingMinerals += pData->nWantedWorkersFarmingGas;
		pData->nWantedWorkersFarmingGas = 0;
		pData->unitsFarmingGas.clear();

	}
    return (int)pData->unitsFarmingMinerals.size() < pData->nWantedWorkersFarmingMinerals;
}
