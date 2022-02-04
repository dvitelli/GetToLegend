#include <iostream>
#include <string>
#ifndef USERPROFILE_H_
#define USERPROFILE_H_

class userProfile
{
private:

	std::string playerName;
	std::string gamePlayed;
	std::string rank;
	std::string oldRank;
	int rankNumber;
	int starsInRank;
	int distanceToLegend;
	double winPercentage;
	int rankLowerBound;
	int rankUpperBound;
	int winstreakCounter;
	int rankNumerical;

public:

	 userProfile();
	 userProfile(std::string playerNameInput, std::string gamePlayedInput, std::string oldRank, std::string rankInput, int rankNumberInput, int starsinRankInput, double winPercentageInput);
	 std::string getPlayerName();
	 std::string getGamePlayed();
	 std::string getRank();
	 std::string getOldRank();
	 int getRankNumber();
	 int getStarsInRank();
	 int getdistanceToLegend();
	 double getWinPercentage();
	 int getRankLowerBound();
	 int getRankUpperBound();
	 int getWinStreakCounter();
	 int getRankNumerical();
	 void setPlayerName(std::string input);
	 void setGamePlayed(std::string input);
	 void setRank(std::string input);
	 void setOldRank(std::string input);
	 void setRankNumber(int input);
	 void setStarsInRank(int input);
	 void setDistanceToLegend(int input);
	 void setWinPercentage(double input);
	 void setRankLowerBound(int input);
	 void setRankUpperBound(int input);
	 void setWinStreakCounter(int input);
	 void setRankNumerical(int input);
	 void incrementWinStreakCounter();
	 void incrementRankNumerical();
	 void decrementRankNumerical();
	 void printProfile();
	 void setInitialBounds();
	 void calculateDistanceToLegend(std::string gamePlayed, std::string rank, int rankNumber, int starsInRank);
	 

	};

#endif

