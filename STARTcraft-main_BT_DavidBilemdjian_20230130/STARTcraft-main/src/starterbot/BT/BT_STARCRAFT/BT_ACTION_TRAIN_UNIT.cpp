#include "BT_ACTION_TRAIN_UNITS.h"
#include "../../Tools.h"
#include "../Data.h"

BT_ACTION_TRAIN_UNITS::BT_ACTION_TRAIN_UNITS(std::string name, BT_NODE* parent)
	: BT_ACTION(name, parent)
{
}

BT_NODE::State BT_ACTION_TRAIN_UNITS::Evaluate(void* data)
{
	return ReturnState(TrainUnit(data));
}

std::string BT_ACTION_TRAIN_UNITS::GetDescription()
{
	return "TRAIN MUTALISK";
}


BT_NODE::State BT_ACTION_TRAIN_UNITS::TrainUnit(void* data)
{
	Data* pData = (Data*)data;
	BWAPI::UnitType unitType = BWAPI::UnitTypes::Zerg_Mutalisk;

	switch (pData->phase)
	{
		default:
			unitType = BWAPI::UnitTypes::Zerg_Mutalisk;
			break;
		case 0:
		case 1:
		case 2: 
			unitType = BWAPI::UnitTypes::Zerg_Zergling;
			break;
		case 3:
			unitType = BWAPI::UnitTypes::Zerg_Mutalisk;
			break;
	}

	const BWAPI::Unit myDepot = Tools::GetDepot();

	// if we have a valid depot unit and it's currently not training something, train a mutalisk

	if (myDepot && !myDepot->isTraining())
	{
		myDepot->train(unitType);
		BWAPI::Error error = BWAPI::Broodwar->getLastError();
		if (error != BWAPI::Errors::None)
			return BT_NODE::FAILURE;
		else return BT_NODE::SUCCESS;
	}

	return BT_NODE::FAILURE;
}