#ifndef PLAYER_H
#define PLAYER_H
#pragma once

using namespace std;
class Player;//FWD declaration

class Player
{
public:
	Player();
	Player(string playerName);

	int right;
	int wrong;
	double coins;

	string getName() const
	{	return name;	}

	//These functions show stats from
	//current round
	int getRight() const
	{	return right;	}

	int getWrong() const
	{	return wrong;	}

	double getCoinCount() const
	{	return coins;	}

	//These functions show stats since
	//creation of player profile
	//pulls stats from saved player file
	int showOverallRight();
	int showOverallWrong();
	double showOverallCoins();

	//These functions update
	//player info that will be saved
	//to player profile
	void setName(string userName);
	void addToRight();
	void addToWrong();
	void setCoins(bool rightAnswer);
	void savePlayerStats();


private:
	string name;
	int overallRight;
	int overallWrong;
	double overallCoins;
};

#endif


