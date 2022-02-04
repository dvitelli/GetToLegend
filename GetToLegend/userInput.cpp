#include <iostream>
#include <string>
#include "userInput.h"
#include "userProfile.h"

std::string game(int userChoice) {

	std::string gameName;

	switch (userChoice) {
	case 1:
		gameName = "Hearthstone";
		break;
	case 2:
		gameName = "Magic: the Gathering Arena";
		break;
	case 3:
		gameName = "Legends of Runeterra";
		break;

	}
		 
		return gameName;

	}
	std::string lastSeasonRank(int userChoice) {

		std::string oldRank;

		switch (userChoice) {
		case '1':
			oldRank = "Bronze";
			break;
		case '2':
			oldRank = "Silver";
			break;
		case '3':
			oldRank = "Gold";
			break;
		case '4':
			oldRank = "Platinum";
			break;
		case '5':
			oldRank = "Diamond";
			break;
		case '6':
			oldRank = "Legend";
			break;
		}

		return oldRank;
	}
	std::string currentRank(int userChoice) {

		std::string rank;

		switch (userChoice) {
		case 1:
			rank = "Bronze";
			break;
		case 2:
			rank = "Silver";
			break;
		case 3:
			rank = "Gold";
			break;
		case 4:
			rank = "Platinum";
			break;
		case 5:
			rank = "Diamond";
			break;
		}

		return rank;
	}

	userProfile introduction() {

		std::string playerName;
		std::string gamePlayed;
		std::string rank;
		std::string oldRank = "blank";
		int rankNumber;
		int starsInRank;
		double winPercentage;
		int userChoice;
		double userChoicePercentage;

		std::cout << "Welcome to GetLegend!" << std::endl;

		std::cout << "Enter your name: " << std::endl;
		std::cin >> playerName;

		std::cout << "Choose the game you are playing: \n " << //only hearthstone for now
			"1. Hearthstone\n";

		std::cin >> userChoice;
		gamePlayed = game(userChoice); //gets string of name played
		
		/*if (gamePlayed == "Hearthstone") {

			std::cout << "\nWill GetLegend be running simulations on begining of season or mid season gameplay? \n" << //have to calculate winstreaks differently based on what point of season
				"1. Midseason \n"/* <<
				"2. Beginning of Season \n" ;//later advancement

		std::cin >> userChoice;

		if (userChoice == 2) {

			std::cout << "What rank where you last season? \n" <<
				"1. Bronze \n" <<
				"2. Silver \n" <<
				"3. Gold \n" <<
				"4. Platinum \n" <<
				"5. Diamond \n" <<
				"6. Legend \n" << std::endl;

			std::cin >> userChoice; */
			oldRank = "Bronze";//this needs to go into its own function -
			

		std::cout << "What rank are you currently? \n" <<//get rank
				"1. Bronze \n" <<
				"2. Silver \n" <<
				"3. Gold \n" <<
				"4. Platinum \n" <<
				"5. Diamond \n" << std::endl;

				std::cin >> userChoice;
				rank = currentRank(userChoice);
				
		 std::cout << "What rank number are you at? \n" <<//get rank number
			"1. One \n" <<
			"2. Two \n" <<
			"3. Three \n" <<
			"4. Four \n" <<
			"5. Five \n" <<
			"6. Six \n" <<
			"7. Seven \n" <<
			"8. Eight \n" <<
			"9. Nine \n" <<
			"10. Ten \n" << std::endl;

		std::cin >> userChoice;
		rankNumber = userChoice;
		
		std::cout << "How many stars do you have in your rank? \n" <<//get star count in rank
			"0. Zero\n" <<
			"1. One \n" <<
			"2. Two \n" <<
			"3. Three \n" << std::endl;

		
		std::cin >> userChoice;
		starsInRank = userChoice;

		std::cout << "Please enter your win percentage: \n";

		std::cin >> userChoicePercentage;
		winPercentage = userChoicePercentage;

		userProfile playerProfile(playerName, gamePlayed, oldRank, rank, rankNumber, starsInRank, winPercentage);
					

		return playerProfile;

	}

	
