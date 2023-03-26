#include "BT_ACTION_SEND_IDLE_WORKER_TO_GAS.h"
#include "../../Tools.h"
#include "../Data.h"

BT_ACTION_SEND_IDLE_WORKER_TO_GAS::BT_ACTION_SEND_IDLE_WORKER_TO_GAS(std::string name, BT_NODE* parent)
	: BT_ACTION(name, parent)
{
}

BT_NODE::State BT_ACTION_SEND_IDLE_WORKER_TO_GAS::Evaluate(void* data)
{
	return ReturnState(SendIdleWorkerToGas(data));
}

std::string BT_ACTION_SEND_IDLE_WORKER_TO_GAS::GetDescription()
{
	return "SEND IDLE WORKER TO MINERAL";
}


BT_NODE::State BT_ACTION_SEND_IDLE_WORKER_TO_GAS::SendIdleWorkerToGas(void* data)
{
	Data* pData = (Data*)data;

	const BWAPI::Unitset& myUnits = BWAPI::Broodwar->self()->getUnits();
	BWAPI::Unit extractor = nullptr;

	for (auto& unit : myUnits)
		if (unit->getType() == BWAPI::UnitTypes::Zerg_Extractor)
		{
			extractor = unit;
			break;
		}

	if (extractor == nullptr)
	{
		pData->extractorBuilt = 0;
		return BT_NODE::FAILURE;
	 }

	for (auto& unit : myUnits)
		// Check the unit type, if it is an idle worker, then we want to send it somewhere
		if (unit->getType().isWorker() && unit->isIdle() && extractor->isCompleted())
		{
			unit->rightClick(extractor);
			pData->unitsFarmingGas.insert(unit);
			return BT_NODE::SUCCESS;
		}


	return BT_NODE::FAILURE;
}
