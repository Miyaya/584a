#include "BT_ACTION_BUILD_SUPPLY_PROVIDER.h"
#include "../../Tools.h"
#include "../Data.h"

BT_ACTION_BUILD_SUPPLY_PROVIDER::BT_ACTION_BUILD_SUPPLY_PROVIDER(std::string name,BT_NODE* parent)
    :  BT_ACTION(name,parent) {}

BT_NODE::State BT_ACTION_BUILD_SUPPLY_PROVIDER::Evaluate(void* data)
{
    return ReturnState(BuildSupplyProvider(data));
}

std::string BT_ACTION_BUILD_SUPPLY_PROVIDER::GetDescription()
{
    return "BUILD SUPPLY PROVIDER";
}


BT_NODE::State BT_ACTION_BUILD_SUPPLY_PROVIDER::BuildSupplyProvider(void* data)
{
    Data* pData = (Data*)data;

    // let's build a supply provider
    const BWAPI::UnitType supplyProviderType = BWAPI::Broodwar->self()->getRace().getSupplyProvider();
    const BWAPI::Unit myDepot = Tools::GetDepot();

    if (myDepot && !myDepot->isTraining())
    {
        myDepot->train(supplyProviderType);
        BWAPI::Error error = BWAPI::Broodwar->getLastError();
        if (error != BWAPI::Errors::None)
            return BT_NODE::FAILURE;
        else
        {
            BWAPI::Broodwar->printf("Started Building %s", supplyProviderType.getName().c_str());
            pData->nWantedZerglingsTotal += 16;
            pData->nWantedHatcheryTotal += 1;
            return BT_NODE::SUCCESS;
        }
    }
    return BT_NODE::FAILURE;
}