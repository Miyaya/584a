#pragma once
#include <unordered_set>
#include <BWAPI.h>

#define THRESHOLD1_MINERALS 200
#define THRESHOLD1_UNUSED_SUPPLY 1

#define NWANTED_WORKERS_TOTAL 12
#define NWANTED_OVERLORDS_TOTAL 1
#define NWANTED_WORKERS_FARMING_MINERALS 9
#define NWANTED_WORKERS_FARMING_GAS 3
#define NWANTED_ZERGLINGS_TOTAL 6
#define NWANTED_MUTALISKS_TOTAL 6

#define NWANTED_SPAWNING_POOL_TOTAL 1
#define NWANTED_EXTRACTOR_TOTAL 1
#define NWANTED_SPIRE_TOTAL 1


class Data
{
public:

	int phase;
	/*
	phase == 0: initial;
	phase == 1: start building spawning pool;
	phase == 2: start building extractor;
	phase == 3: start morphing hatchery to lair;
	phase == 4: start building spire;
	*/
	BWAPI::Position selfLocation;
	BWAPI::Position enemyLocation;
	int currMinerals;
	int thresholdMinerals;
	int currSupply;
	int thresholdSupply;

	int nWantedWorkersTotal;
	int nWantedOverlordsTotal;
	int nWantedWorkersFarmingMinerals;
	int nWantedWorkersFarmingGas;
	int nWantedZerglingsTotal;
	int nWantedMutalisksTotal;

	int nWantedSpawningPoolTotal;
	int nWantedExtractorTotal;
	int nWantedSpireTotal;

	std::unordered_set<BWAPI::Unit> unitsFarmingMinerals;
	std::unordered_set<BWAPI::Unit> unitsFarmingGas;
};
