#include <iostream>
#include <string>
#include "userProfile.h"
#include "gameSimulation.h"
#include <ctime>
#include <cstdlib>


int main() {

	int max = 100;//max for random number
	srand(time(0));

	if (simulationProfile.getWinPercentage() >= rand() % max) {

		std::cout << "Win";
	}


	return 0;
}