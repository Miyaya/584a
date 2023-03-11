#include "BT_ACTION_TRAIN_MUTALISK.h"
#include "../../Tools.h"
#include "../Data.h"

BT_ACTION_TRAIN_MUTALISK::BT_ACTION_TRAIN_MUTALISK(std::string name, BT_NODE* parent)
    : BT_ACTION(name, parent)
{
}

BT_NODE::State BT_ACTION_TRAIN_MUTALISK::Evaluate(void* data)
{
    return ReturnState(TrainMutalisk(data));
}

std::string BT_ACTION_TRAIN_MUTALISK::GetDescription()
{
    return "TRAIN MUTALISK";
}


BT_NODE::State BT_ACTION_TRAIN_MUTALISK::TrainMutalisk(void* data)
{
    Data* pData = (Data*)data;

    const BWAPI::UnitType unitType = BWAPI::UnitTypes::Zerg_Mutalisk;
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