#include <iostream>
#include <string>
#include "userProfile.h"
#include "gameSimulation.h"
#include <ctime>
#include <cstdlib>

void runSimulation(userProfile playerProfile) { //chooses simulation that is necessary


	if (playerProfile.getGamePlayed() == "Hearthstone") {
		hearthstoneMidSeasonSimulation(playerProfile);
	}if (playerProfile.getGamePlayed() == "Magic: The Gathering Arena") {
		//mtgaSimulation(playerProfile);
	}if (playerProfile.getGamePlayed() == "Legends of Runeterra") {
		//lorSimulation(playerProfile);
	}
}
int rankNumericalConvert(userProfile playerProfile) { //need to convert rank to a number to properly simulate

	int rankConversion;
	int rankNumerical;

	if (playerProfile.getRank() == "Bronze") {
		rankConversion = 0;
	}if (playerProfile.getRank() == "Silver") {
		rankConversion = 1;
	}if (playerProfile.getRank() == "Gold") {
		rankConversion = 2;
	}if (playerProfile.getRank() == "Platinum") {
		rankConversion = 3;
	}if (playerProfile.getRank() == "Diamond") {
		rankConversion = 4;
	}

	if (playerProfile.getGamePlayed() == "Hearthstone") {

		 rankNumerical = ((rankConversion * 30) + ((10 - playerProfile.getRankNumber()) * 3) + playerProfile.getStarsInRank()); //algorithm to figure out distance to legend

	}

	return rankNumerical;

}
void checkForRankUp(userProfile &simulationProfile) {


	if (simulationProfile.getRankNumerical() > 15) {//bronze 5 floor

		simulationProfile.setRankLowerBound(15);
		simulationProfile.setRankUpperBound(30);
	}
	 if (simulationProfile.getRankNumerical() > 30){//promotion to Silver

		simulationProfile.setRankLowerBound(30);
		simulationProfile.setRankUpperBound(45);
		simulationProfile.setRank("Silver");

	}
	if (simulationProfile.getRankNumerical() > 45) {//silver 5 floor

		simulationProfile.setRankLowerBound(45);
		simulationProfile.setRankUpperBound(60);

	}
	if (simulationProfile.getRankNumerical() > 60) {//promotion to gold

		simulationProfile.setRankLowerBound(60);
		simulationProfile.setRankUpperBound(75);
		simulationProfile.setRank("Gold");

	}if (simulationProfile.getRankNumerical() > 75) {//gold 5 floor

		simulationProfile.setRankLowerBound(75);
		simulationProfile.setRankUpperBound(90);

	}
	if (simulationProfile.getRankNumerical() > 90) {//promotion to plat

		simulationProfile.setRankLowerBound(90);
		simulationProfile.setRankUpperBound(105);
		simulationProfile.setRank("Platinum");

	}
	if (simulationProfile.getRankNumerical() > 105) {//plat 5 floor

		simulationProfile.setRankLowerBound(105);
		simulationProfile.setRankUpperBound(120);

	}
	if (simulationProfile.getRankNumerical() > 120) {//promotion to diamond

		simulationProfile.setRankLowerBound(120);
		simulationProfile.setRankUpperBound(135);
		simulationProfile.setRank("Diamond");

	}
	if (simulationProfile.getRankNumerical() > 135) {//diamond 5 floor

		simulationProfile.setRankLowerBound(135);
		simulationProfile.setRankUpperBound(150);

	}
	

}
void setInitialBounds(userProfile &simulationProfile) {

	if (simulationProfile.getRank() == "Bronze") {

		if (simulationProfile.getRankNumber() > 5) {

			simulationProfile.setRankLowerBound(0);
			simulationProfile.setRankUpperBound(15);
		}
		else {
			simulationProfile.setRankLowerBound(15);
			simulationProfile.setRankUpperBound(30);

		}
	}
	else if (simulationProfile.getRank() == "Silver") {

		if (simulationProfile.getRankNumber() > 5) {

			simulationProfile.setRankLowerBound(30);
			simulationProfile.setRankUpperBound(45);
		}
		else {
			simulationProfile.setRankLowerBound(45);
			simulationProfile.setRankUpperBound(60);

		}

	}
	else if (simulationProfile.getRank() == "Gold") {

		if (simulationProfile.getRankNumber() > 5) {

			simulationProfile.setRankLowerBound(60);
			simulationProfile.setRankUpperBound(75);
		}
		else {
			simulationProfile.setRankLowerBound(75);
			simulationProfile.setRankUpperBound(90);

		}

	}
	else if (simulationProfile.getRank() == "Platinum") {

		if (simulationProfile.getRankNumber() > 5) {

			simulationProfile.setRankLowerBound(90);
			simulationProfile.setRankUpperBound(105);
		}
		else {
			simulationProfile.setRankLowerBound(105);
			simulationProfile.setRankUpperBound(120);

		}
	}
	else if (simulationProfile.getRank() == "Diamond") {

		if (simulationProfile.getRankNumber() > 5) {

			simulationProfile.setRankLowerBound(120);
			simulationProfile.setRankUpperBound(135);
		}
		else {
			simulationProfile.setRankLowerBound(135);
			simulationProfile.setRankUpperBound(150);

		}

	}


}
void gameArrayAverage(int gamesPlayed[], int size) {//get average of games played

	int averageNumberOfGames = 0;

	for (int i = 0; i < size; i++) {

		averageNumberOfGames += gamesPlayed[i];

	}

	std::cout << "Average Number of Games to Hit Legend: " << averageNumberOfGames / size << std::endl;

}

void hearthstoneMidSeasonSimulation(userProfile playerProfile) {

	userProfile simulationProfile = playerProfile;
	simulationProfile.setRankNumerical(rankNumericalConvert(playerProfile));
	int baseNumerical = simulationProfile.getRankNumerical();
	const int simulationsRan = 1000;//number of times simulations been performed
	int numberOfGames = 0;
	int gameCountArray[simulationsRan];
	int averageNumberOfGames = 0;
	int medianNumberOfGames = 0;
	int max = 100;//max for random number
	srand(time(0));
	
	simulationProfile.printProfile();

	for (int i = 0; i < simulationsRan; i++) {	
		
		setInitialBounds(simulationProfile);	
		numberOfGames = 0;
		

		while (simulationProfile.getRankNumerical() < 151) {//keep looping until it hits legend


			if (simulationProfile.getWinPercentage() >= rand()%max) { //when winpercentage > than or = to the random 1-100 it counts as a win

				simulationProfile.incrementRankNumerical();
				simulationProfile.incrementWinStreakCounter();

				if (simulationProfile.getWinStreakCounter() >= 3 && simulationProfile.getRankUpperBound() != 150) {//if player is winstreaking get an additional win (make sure doesnt happen after d5)
					
					simulationProfile.incrementRankNumerical();

				}

				if (simulationProfile.getRankNumerical() > simulationProfile.getRankUpperBound()) {

					checkForRankUp(simulationProfile);//check to see if player ranked up - if they did set new lower and upper bound
				}
			}
			else {
				if (simulationProfile.getRankNumerical() == simulationProfile.getRankLowerBound()) { //if the player is at the rank floor they do not lose points

					simulationProfile.setWinStreakCounter(0);//reset winstreak counter on loss
				}

				else {

					simulationProfile.decrementRankNumerical();

				}

			}
			
			numberOfGames++;

		}

		gameCountArray[i] = numberOfGames;//collects number of games played for each simulation
		simulationProfile.setRankNumerical(baseNumerical);
		
	}

	gameArrayAverage(gameCountArray, simulationsRan);

}
void mtgaSimulation(userProfile playerProfile){}
void lorSimulation(userProfile playerProfile){}