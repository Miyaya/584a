#pragma once
#include <cassert>
#include ""
#include <vector>
#include <BWAPI.h>

//--------------------
class BT_ACTION_BUILD_ONE_DRONE: public BT_ACTION {
public:
    BT_ACTION_BUILD_ONE_DRONE(std::string name, BT_NODE* parent);

private:
    State Evaluate(void* data) override;
    std::string GetDescription() override;
    static BT_NODE::State BuildOneDrone(void* data);
};
//----------
