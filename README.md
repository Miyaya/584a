# INF584A
NOTE: ```BT/BT.h```, ```BT/Data.h``` and ```StarterBot.cpp``` should all be modified if you want to add any function.
## Crucial Problem
All the trainings and buildings are going simultaneously, usually there will be 2 larvae morphing into drones together and 2 drones into spawning pools together, which may result in 1 extra drone and 1 extra spawning pool
## Currently vailable functions 
1. Train 6 drones (might be 7 due to the problem above). Related files: ```BT_DECO_CONDITION_NOT_ENOUGH_WORKERS```, ```BT_ACTION_TRAIN_WORKER```
2. ```Currently disabled``` Train overlords when there's not enough control. Related files: ```BT_DECO_CONDITION_NOT_ENOUGH_SUPPLY```, ```BT_ACTION_BUILD_SUPPLY_PROVIDER```
3. Build 1 spawning pool (might be 2 due to the problem above). Related files: ```BT_DECO_CONDITION_NOT_ENOUGH_SPAWNING_POOL```, ```BT_ACTION_BUILD_SPAWNING_POOL```
4. Train 6 Zerglings (might be 4 or 8 due to the problem above). Related files: ```BT_DECO_CONDITION_NOT_ENOUGH_ZERGLINGS```, ```BT_ACTION_TRAIN_ZERGLING```

