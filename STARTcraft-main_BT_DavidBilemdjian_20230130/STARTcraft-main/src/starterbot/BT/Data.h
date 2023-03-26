#pragma once
#include <unordered_set>
#include <BWAPI.h>

#define THRESHOLD1_MINERALS 200
#define THRESHOLD1_UNUSED_SUPPLY 1

#define NWANTED_WORKERS_TOTAL 5
#define NWANTED_WORKERS_FARMING_MINERALS 6
#define NWANTED_WORKERS_FARMING_GAS 3
#define NWANTED_ZERGLINGS_TOTAL 6
#define NWANTED_HYDRALISKS_TOTAL 6
#define NWANTED_LURKERS_TOTAL 6

#define NWANTED_SPAWNING_POOL_TOTAL 1
#define NWANTED_EXTRACTOR_TOTAL 1
#define NWANTED_HATCHERY_TOTAL 1


class Data
{
public:

	int spawningPoolBuilt;
	int extractorBuilt;
	int upgradeFinished;

	BWAPI::Position selfLocation;
	BWAPI::Position enemyLocation;

	int currMinerals;
	int thresholdMinerals;
	int currSupply;
	int thresholdSupply;
	int thresholdZerglings;

	int nWantedWorkersTotal;
	int nWantedWorkersFarmingMinerals;
	int nWantedWorkersFarmingGas;
	int nWantedZerglingsTotal;
	
	int nWantedExtractorTotal;
	int nWantedSpawningPoolTotal;
	int nWantedHatcheryTotal;

	std::unordered_set<BWAPI::Unit> unitsFarmingMinerals;
	std::unordered_set<BWAPI::Unit> unitsFarmingGas;
};
