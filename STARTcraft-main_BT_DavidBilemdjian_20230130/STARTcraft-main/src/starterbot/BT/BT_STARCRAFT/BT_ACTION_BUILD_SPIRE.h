#pragma once
#include <cassert>
#include "../BT_ACTION.h"
#include <vector>
#include <BWAPI.h>

//--------------------
class BT_ACTION_BUILD_SPIRE : public BT_ACTION
{
public:
	BT_ACTION_BUILD_SPIRE(std::string name, BT_NODE* parent);

private:
	State Evaluate(void* data) override;
	std::string GetDescription() override;
	static BT_NODE::State BuildSpire(void* data);
};
//----------#pragma once
