#include <iostream>
#include <string>
#include "userProfile.h"
#ifndef GAMESIMULATION_H_
#define GAMESIMULATION_H_

	void runSimulation(userProfile playerProfile);
	void hearthstoneMidSeasonSimulation(userProfile playerProfile);
	//void mtgaSimulation(userProfile playerProfile);
	//void lorSimulation(userProfile playerProfile);
	int rankNumericalConvert(userProfile playerProfile);
	void checkForRankUp(userProfile &simulationProfile);
	void setInitialBounds(userProfile &simulationProfile);
	void gameArrayAverage(int gamesPlayed[], const int size);
	

#endif
