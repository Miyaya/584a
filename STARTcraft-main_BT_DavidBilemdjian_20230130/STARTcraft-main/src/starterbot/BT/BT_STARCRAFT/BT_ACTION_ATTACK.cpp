#include "BT_ACTION_ATTACK.h"
#include "../../Tools.h"
#include "../Data.h"
#include <set>

BT_ACTION_ATTACK::BT_ACTION_ATTACK(std::string name, BT_NODE* parent)
	: BT_ACTION(name, parent)
{
}

BT_NODE::State BT_ACTION_ATTACK::Evaluate(void* data)
{
	return ReturnState(Attack(data));
}

std::string BT_ACTION_ATTACK::GetDescription()
{
	return "ATTACK";
}


BT_NODE::State BT_ACTION_ATTACK::Attack(void* data)
{
	Data* pData = (Data*)data;


	BWAPI::Unitset combatUnits;

	for (auto& unit : BWAPI::Broodwar->self()->getUnits())
		if (unit->getType().canAttack() && unit->getType().canMove() && !unit->getType().isWorker())
			combatUnits.insert(unit);



	for (auto& unit : combatUnits)
		if (unit->getLastCommand().getType() == BWAPI::UnitCommandTypes::Attack_Unit && unit->isVisible())
			continue;
		else if (unit->getLastCommand().getType() == BWAPI::UnitCommandTypes::Patrol)
			continue;
		else
			unit->patrol(pData->enemyLocation);
	combatUnits.move(pData->enemyLocation);

	if (combatUnits.empty())
		return BT_NODE::SUCCESS;
	return BT_NODE::FAILURE;
}