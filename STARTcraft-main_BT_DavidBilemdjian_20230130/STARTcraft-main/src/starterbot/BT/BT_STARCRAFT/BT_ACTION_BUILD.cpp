#include "BT_ACTION_BUILD.h"
#include "../../Tools.h"
#include "../Data.h"

BT_ACTION_BUILD::BT_ACTION_BUILD(std::string name, BT_NODE* parent)
	: BT_ACTION(name, parent)
{
}

BT_NODE::State BT_ACTION_BUILD::Evaluate(void* data)
{
	return ReturnState(Build(data));
}

std::string BT_ACTION_BUILD::GetDescription()
{
	return "BUILD EXTRACTOR";
}


BT_NODE::State BT_ACTION_BUILD::Build(void* data)
{
	Data* pData = (Data*)data;
	BWAPI::UnitType buildingType;
	bool startedBuilding;

	switch (pData->phase)
	{
		default:
			buildingType = BWAPI::UnitTypes::Zerg_Hatchery;
			startedBuilding = Tools::BuildBuilding(buildingType);
			break;
		case 0:
			buildingType = BWAPI::UnitTypes::Zerg_Spawning_Pool;
			startedBuilding = Tools::BuildBuilding(buildingType);
			break;
		case 1:
			buildingType = BWAPI::UnitTypes::Zerg_Extractor;
			startedBuilding = Tools::BuildBuilding(buildingType);
			break;
		case 2:
			if (pData->Lair)
			{
				buildingType = BWAPI::UnitTypes::Zerg_Spire;
				startedBuilding = Tools::BuildBuilding(buildingType);
			}
			else
				for (auto& unit : BWAPI::Broodwar->self()->getUnits())
					if (unit->getType() == BWAPI::UnitTypes::Zerg_Hatchery && unit->isCompleted())
					{
						buildingType = BWAPI::UnitTypes::Zerg_Lair;
						startedBuilding = unit->morph(buildingType);
						if (startedBuilding)
							pData->Lair = 1;
						break;
					}
			break;
		case 3:
			buildingType = BWAPI::UnitTypes::Zerg_Hatchery;
			startedBuilding = Tools::BuildBuilding(buildingType);
			break;
	}

	if (startedBuilding)
		BWAPI::Broodwar->printf("Started Building %s", buildingType.getName().c_str());

	return startedBuilding ? BT_NODE::SUCCESS : BT_NODE::FAILURE;
}