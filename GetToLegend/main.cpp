#include <iostream>
#include <string>
#include "userInput.h"
#include "userProfile.h"
#include "gameSimulation.h"

int main(void) {

	userProfile playerProfile = introduction(); //create user profile	
	runSimulation(playerProfile); //starts choosing the correct simulation and then runs simulation
	
	return 0;

}