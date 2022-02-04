#include <iostream>
#include <string>
#include "userProfile.h"

userProfile::userProfile(){

	std::string playerName = "Test";
	std::string gamePlayed = "Hearthstone";
	std::string rank = "Bronze";
	std::string oldRank = "Bronze";
	int rankNumber = 10;
	int starsInRank = 0;
	int distanceToLegend = 151;
	double winPercentage = 0;
	int rankLowerBound = 0;
	int rankUpperBound = 150;
	int rankNumerical = 0;
	int winStreakCounter = 0;

}
userProfile::userProfile(std::string playerNameInput, std::string gamePlayedInput, std::string oldRankInput, std::string rankInput, int rankNumberInput, int starsinRankInput, double winPercentageInput) {

		playerName = playerNameInput;
		gamePlayed = gamePlayedInput;
		oldRank = oldRankInput;
		rank = rankInput;
		rankNumber = rankNumberInput;
		starsInRank = starsinRankInput;
		winPercentage = winPercentageInput;

		setInitialBounds();
		winstreakCounter = 0;
		
	}
void userProfile::setInitialBounds() {

	if (getRank() == "Bronze") {

		if (getRankNumber() > 5) {

			setRankLowerBound(0);
			setRankUpperBound(15);
		}
		else {
			setRankLowerBound(15);
			setRankUpperBound(30);

		}
	}
	else if (getRank() == "Silver") {

		if (getRankNumber() > 5) {

			setRankLowerBound(30);
			setRankUpperBound(45);
		}
		else {
			setRankLowerBound(45);
			setRankUpperBound(60);

		}

	}
	else if (getRank() == "Gold") {

		if (getRankNumber() > 5) {

			setRankLowerBound(60);
			setRankUpperBound(75);
		}
		else {
			setRankLowerBound(75);
			setRankUpperBound(90);

		}

	}
	else if (getRank() == "Platinum") {

		if (getRankNumber() > 5) {

			setRankLowerBound(90);
			setRankUpperBound(105);
		}
		else {
			setRankLowerBound(105);
			setRankUpperBound(120);

		}
	}
	else if (getRank() == "Diamond") {

		if (getRankNumber() > 5) {

			setRankLowerBound(120);
			setRankUpperBound(135);
		}
		else {
			setRankLowerBound(135);
			setRankUpperBound(150);

		}

	}


}
	std::string userProfile::getPlayerName() {

		return playerName;
	}
	std::string userProfile::getGamePlayed() {

		return gamePlayed;
	}
	std::string userProfile::getRank() {

		return rank;
	}
	std::string userProfile::getOldRank() {

		return oldRank;
	}
	int userProfile::getRankNumber() {

		return rankNumber;
	}
	int userProfile::getStarsInRank() {

		return starsInRank;
	}
	int userProfile::getdistanceToLegend() {

		return distanceToLegend;
	}
	double userProfile::getWinPercentage() {

		return winPercentage;
	}
	int userProfile::getRankLowerBound() {
		return rankLowerBound;
	}
	int userProfile::getRankUpperBound() {
		return rankUpperBound;
	}
	int userProfile::getWinStreakCounter() {
		return winstreakCounter;
	}
	int userProfile::getRankNumerical() {
		return rankNumerical;

	}
	void userProfile::setPlayerName(std::string input) {

		playerName = input;
	}
	void userProfile::setGamePlayed(std::string input) {

		gamePlayed = input;
	}
	void userProfile::setRank(std::string input) {

		rank = input;
	}	
	void userProfile::setOldRank(std::string input) {

		oldRank = input;
	}
	void userProfile::setRankNumber(int input) {

		rankNumber = input;
	}
	void userProfile::setStarsInRank(int input) {

		starsInRank = input;
	}
	void userProfile::setDistanceToLegend(int input) {

		distanceToLegend = input;
	}
	void userProfile::setWinPercentage(double input) {

		winPercentage = input;
	}
	void userProfile::setRankLowerBound(int input) {
		rankLowerBound = input;
	}
	void userProfile::setRankUpperBound(int input) {
		rankUpperBound = input;
	}
	void userProfile::setWinStreakCounter(int input) {
		winstreakCounter = input;
	}
	void userProfile::setRankNumerical(int input) {
		rankNumerical = input;
	}
	void userProfile::incrementWinStreakCounter() {
		winstreakCounter++;
	}
	void userProfile::incrementRankNumerical() {
		rankNumerical++;
	}
	void userProfile::decrementRankNumerical() {
		rankNumerical--;
		winstreakCounter = 0;
	}
	void userProfile::calculateDistanceToLegend(std::string game, std::string rank, int rankNumber, int starsInRank) {

		int distanceToLegendCalculation;
		int rankConversion;

		if (rank == "Bronze") {
			rankConversion = 0;
		}if (rank == "Silver") {
			rankConversion = 1;
		}if (rank == "Gold") {
			rankConversion = 2;
		}if (rank == "Platinum"){
			rankConversion = 3;
		}if (rank == "Diamond") {
			rankConversion = 4;
		}

		if (game == "Hearthstone") {

			distanceToLegendCalculation = 151 - ((rankConversion * 30) + ((10 - rankNumber) * 3) + starsInRank); //algorithm to figure out distance to legend
			
		}


		distanceToLegend = distanceToLegendCalculation;


	}
	void userProfile::printProfile() {

		calculateDistanceToLegend(gamePlayed, rank, rankNumber, starsInRank);

		std::cout << "\nPlayer Name: " << playerName << std::endl;
		std::cout << "Game Played: " << gamePlayed << std::endl;
		std::cout << "Rank: " << rank << std::endl;
		std::cout << "Old Rank: " << oldRank << std::endl;
		std::cout << "Rank Number: " << rankNumber << std::endl;
		std::cout << "Stars In Rank: " << starsInRank << std::endl;
		std::cout << "Distance to Legend: " << distanceToLegend << std::endl;
		std::cout << "Win Percentage: " << winPercentage << "%" << std::endl;
		std::cout << "Lower Bound: " << rankLowerBound << std::endl;
		std::cout << "Upper Bound: " << rankUpperBound << std::endl;

	};







