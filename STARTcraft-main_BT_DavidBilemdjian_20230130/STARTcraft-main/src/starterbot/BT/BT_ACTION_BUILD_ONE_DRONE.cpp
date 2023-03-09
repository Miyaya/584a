#include "BT_ACTION_BUILD_ONE_DRONE.h"
#include "Tools.h"
#include "Data.h"

BT_ACTION_BUILD_ONE_DRONE::BT_ACTION_BUILD_ONE_DRONE(std::string name,BT_NODE* parent)
    :  BT_ACTION(name,parent) {}

BT_NODE::State BT_ACTION_BUILD_ONE_DRONE::Evaluate(void* data)
{
    return ReturnState(BuildOneDrone(data));
}

std::string BT_ACTION_BUILD_ONE_DRONE::GetDescription()
{
    return "BUILD A DRONE";
}


BT_NODE::State BT_ACTION_BUILD_ONE_DRONE::BuildOneDrone(void* data)
{
    Data* pData = (Data*)data;

    // TODO: build a drone

    BWAPI::Unit larva = NULL;
    for(auto &u: BWAPI::Broodwar->self()->getUnits()){
        if(u->getType() == BWAPI::UnitTypes::Zerg_Larva){
            larva = u;
            break;
        }
    }

    // Morph drone from larva
    if(larva!=NULL && larva->isIdle()){
        larva->morph(BWAPI::UnitTypes::Zerg_Drone);
    }
 
    /*
    const BWAPI::UnitType supplyProviderType = BWAPI::Broodwar->self()->getRace().getSupplyProvider();
    const bool startedBuilding = Tools::BuildBuilding(supplyProviderType);

    if (startedBuilding)
        BWAPI::Broodwar->printf("Started Building %s", supplyProviderType.getName().c_str());

    return startedBuilding ? BT_NODE::SUCCESS:BT_NODE::FAILURE;
    */
}