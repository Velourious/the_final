#include <iostream>
#include <iomanip>
#include <fstream>
#include "Player.h"

using namespace std;

Player::Player()
{
	name = "";
	right = 0;
	wrong = 0;
	coins = 0.00;

	overallRight = 0;
	overallWrong = 0;
	overallCoins = 0.00;
}

Player::Player(string playerName)
{
	ifstream inFile;
	ofstream outFile;
	string name = playerName;
	string fileName = playerName + ".txt";

	inFile.open(fileName.c_str());
	if (inFile.fail())//no player file exists/new player
	{
		//create file
		outFile.open(fileName.c_str());
		outFile << 0 << endl;//set overall right to 0
		outFile << 0 << endl;//set overall wrong to 0
		outFile << 0.00 << endl;//set overall coins to 0.00
		outFile.close();
		inFile.close();

		//set inital values
		setName(playerName);
		right = 0;
		wrong = 0;
		coins = 0.00;
		overallRight = 0;
		overallWrong = 0;
		overallCoins = 0.00;
		cout << " Your statistics profile has been created." << endl;
	}
	else
	{
		//Get saved stats, save into Overall stats
		inFile >> overallRight;
		inFile >> overallWrong;
		inFile >> overallCoins;
		inFile.close();
		//Set this round values
		setName(playerName);
		right = 0;
		wrong = 0;
		coins = 0.00;
		cout << "     Hi again!" << endl;
	}
}

void Player::setName(string userName)
{
	name = userName;
}

void Player::addToRight()
{
	right = right + 1;
	setCoins(true);//adds 0.05 to coins
}

void Player::addToWrong()
{
	wrong = wrong + 1;
	setCoins(false);//subtracts 0.03 to coins
}

//Already added to addToRight(), addToWrong() funcs.
//do not need to call this func. separately
void Player::setCoins(bool rightAnswer)
{
	if (rightAnswer == true)
	{
		coins = coins + 0.05;
	}
	else
	{
		coins = coins - 0.03;
	}
}

int Player::showOverallRight()
{
	return(right + overallRight);
}

int Player::showOverallWrong()
{
	return (wrong + overallWrong);
}

double Player::showOverallCoins()
{
	return (coins + overallCoins);
}

void Player::savePlayerStats()
{
	ifstream inFile;
	ofstream outFile;
	string name = getName();
	string fileName = name + ".txt";
	int saveRight;
	int saveWrong;
	double saveCoins;

	inFile.open(fileName.c_str());
	if (inFile.fail())//if file fails to open, display message
	{
		cout << "Stats FAILED to save." << endl;
	}
	else//save stats to file
	{
		//Get saved stats
		inFile >> overallRight;
		inFile >> overallWrong;
		inFile >> overallCoins;
		inFile.close();

		//update stats with this round numbers
		saveRight = overallRight + right;
		saveWrong = overallWrong + wrong;
		saveCoins = overallCoins + coins;

		//save updated stats to file
		outFile.open(fileName.c_str());
		outFile << saveRight << endl;
		outFile << saveWrong << endl;
		outFile << saveCoins << endl;
		outFile.close();
		cout << "\nPlayer stats saved" << endl;
	}
}
