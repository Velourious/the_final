#include<iostream>
#include<iomanip>
#include <string>
#include <fstream>	//io file
#include "Add.h"
#include "Subtract.h"
#include "Multiply.h"
#include "Divide.h"
#include "Player.h"
#include "FunDisplay.h"

using namespace std;

//Function Prototypes
void getPlayerInfo(Player *&);
int menu();
int executeChoice(int choice, int &);
int stringToInt(string userInput);
int compareAnswer(int rightAnswer, int &);
int getUserAnswer(bool &);
void updateRoundStats(Player *&, int rightAnswer);
void showOverallStats(Player *& player);


int main()
{
	Player *player = nullptr;
	int playerChoice;
	int play = 1;
	FunDisplay display;	
	int userRight;//switches between 3 values: 0) user is wrong, update stats
					//1) user is right, update stats
					//2) user just wants to see stats, simply display stats

	display.splashScreen();
	getPlayerInfo(player);
	system("pause");

	do {
		system("cls");
		playerChoice = menu();//menu is displayed, player choice returned
		userRight = executeChoice(playerChoice, play);//execute player choice, determine if player is right
		updateRoundStats(player, userRight);//update stats with player right/wrong info
	} while (play == 1);

	player->savePlayerStats();//this round saved to player overall stats

	display.bye();
	delete player;
	system("pause");
	return 0;
}//end main

//Ask for player name
//open file if player is returning
//create file if new player
//Accepts pointer to memory address of Player
void getPlayerInfo(Player *&player)
{
	string playerName;
	int nameLength;
	int counter = 0;

	cout << endl;
	do
	{
		cout << "     Please enter your name: ";
		getline(cin, playerName);
		nameLength = playerName.length();
	} while (nameLength == 0);

	//iterate over player name
		while (counter < nameLength)
		{
			if (!(isalpha(playerName[counter])))//if any non-alpha characters found
			{
				do
				{
					cout << "     Please enter your name: ";//re-prompt for input
					getline(cin, playerName);
					nameLength = playerName.length();	//reset nameLength
					counter = 0;						//reset counter
				} while (nameLength == 0);
			}
			else
			{
				counter++;
			}
		}

	player = new Player(playerName);

	cout << "     Welcome, " << player->getName() << "!" << endl;
}//end getPlayerInfo

//Menu is displayed. Int value returned
int menu()
{

	string userSelection = "";
	int inputLength;
	int selectionAsInt = 0;
	int selectionSum;//stores the sum of ascii char values user inputs
	bool menuSelectionComplete = false;
	int x;//counter variable

	do
	{
		//setting values inside this loop.
		//if loop runs again, values reset
		inputLength = 0;
		selectionSum = 0;
		x = 0;

		//display menu and get input
		do {
			system("cls");
			cout << " ************************\n"
				<< "          MENU\n "
				<< "************************\n"
				<< " 1. Add\n"
				<< " 2. Subtract\n"
				<< " 3. Multiply\n"
				<< " 4. Divide\n"
				<< " 5. See full stats\n"
				<< " Q/q to quit" << endl;
			cout << "Please select a menu option: ";

			getline(cin, userSelection);
			inputLength = userSelection.length();
		} while (inputLength == 0);//menu displays so long as user enters nothing

		//add up value of ascii characters put in, store in selectionSum
		while (x < inputLength)
		{
			selectionSum = selectionSum + userSelection[x];
			x++;
		}

		//Modifies the quit option to int type to be passed into
		//executeChoice() function
		if (userSelection == "q" || userSelection == "Q")
		{
			cout << "quit" << endl;
			userSelection = "0";
			selectionAsInt = 0;
			menuSelectionComplete = true;
		}
		else
		{
			//valid menu options are 1 - 5 with ascii values of
			//49 - 53. if user has put in anything else 
			//menu selection is not complete
			if (selectionSum < 49 || selectionSum > 53)
			{
				menuSelectionComplete = false;
			}
			else
			{
				menuSelectionComplete = true;
			}
		}
	} while (menuSelectionComplete == false);

	//convert user's input from string to integer data type
	selectionAsInt = stringToInt(userSelection);

	return (selectionAsInt);
}//end menu()

//Execute add, subtract, multiply, divide
//or show overall stats
//or quit
int executeChoice(int choice, int &play)
{
	FunDisplay display;
	Add *addition = nullptr;
	Subtract *subtraction = nullptr;
	Multiply *multiplication = nullptr;
	Divide *division = nullptr;

	int userAnswer = 0;
	bool answered = false;
	int userCorrect = 2;

	system("cls");

	//Execute user's choice. Choice passed from
	//menu()
	switch (choice)
	{
	case 1://execute add
		display.add();
		addition = new Add();

		do {
			cout << "              " << *addition;//display problem
			userAnswer = getUserAnswer(answered);//make sure input not empty or non-integer, else
		} while (answered == false);			//continue to display problem

		userCorrect = compareAnswer(addition->getAnswer(), userAnswer);//check if user answered correctly

		delete addition;
		addition = nullptr;
		break;

	case 2://execute subtract
		display.subtract();
		subtraction = new Subtract();
		do {
			cout << "              " << *subtraction;//display problem
			userAnswer = getUserAnswer(answered);//make sure input not empty or non-integer, else
		} while (answered == false);			//continue to display problem

		userCorrect = compareAnswer(subtraction->getAnswer(), userAnswer);

		delete subtraction;
		subtraction = nullptr;
		break;

	case 3://execute multiply
		display.multiply();
		multiplication = new Multiply();
		do {
			cout << "             " << *multiplication;//display problem
			userAnswer = getUserAnswer(answered);//make sure input not empty or non-integer, else
		} while (answered == false);			//continue to display problem

		userCorrect = compareAnswer(multiplication->getAnswer(), userAnswer);

		delete multiplication;
		multiplication = nullptr;
		break;

	case 4://excute divide
		display.divide();
		division = new Divide();
		do {
			cout << "                      " << *division;//display problem
			userAnswer = getUserAnswer(answered);//make sure input not empty or non-integer, else
		} while (answered == false);			//continue to display problem

		userCorrect = compareAnswer(division->getAnswer(), userAnswer);

		delete division;
		division = nullptr;
		break;

	case 5://show full stats option
		//function called in updateRoundStats();
		userCorrect = 2;

		break;

	case 0://user selected to quit
		play = 0;//main loop in main() will break out
		userCorrect = 2;//to pass to updateRoundStats(), stats left alone
		break;		
	}

	return userCorrect;
}//end executeChoice

//Make sure user answer is not empty
//Make sure user answer is an integer
//toggle answered variable to true when user enters positive integer
int getUserAnswer(bool &answered)
{
	string userAnswerAsString;
	int userAnswer;
	int answerLength = userAnswerAsString.length();
	int counter = 0;
	
		getline(cin, userAnswerAsString);
		answerLength = userAnswerAsString.length();

		if (answerLength != 0)//if user enters something
		{
			while (counter < answerLength)//itrate over input
			{
				if (!isdigit(userAnswerAsString[counter]))//if user did not enter number
				{
					answered = false;//user has not entered integer value
					counter = answerLength;//answered is false, break out of loop
											//do not iterate over any remaining characters
				}
				else
				{
					answered = true;//so far, user has entered integer value
					counter++;//move on to next character
				}
			}	
		}

	userAnswer = stringToInt(userAnswerAsString);

	return userAnswer;
}

//Update userCorrect. If 0)user is wrong
//if 1)user is right
//if 2)user not presented a problem, neither
//right nor wrong
int compareAnswer(int rightAnswer, int &userAnswer)
{
	FunDisplay display;
	int userCorrect = 2;
	
	if (rightAnswer == userAnswer)
	{
		userCorrect = 1;
		display.right();
	}
	else
	{
		display.wrong();
		cout << "              The right answer is " << rightAnswer << "." << endl;
		userCorrect = 0;
	}

	return userCorrect;
}//end compareAnswer

//Update stats for this round
//Display stats
//Accepts pointer to memory address of player
void updateRoundStats(Player *& player, int rightAnswer)
{
	FunDisplay display;

	if (rightAnswer == 1)//if user is right
	{
		player->addToRight();//add to right. +5 cents to coins
	}
	
	if(rightAnswer == 0)// if user wrong
	{
		player->addToWrong();// add to wrong. -3 cents to coins
	}

	if (rightAnswer == 2)
	{
		display.stats();
		showOverallStats(player);
	}

	//display "This Round" stats
	cout << "\nTHIS ROUND:\n"
		<< "Right answers: " << player->getRight() << endl;
	cout << "Wrong answers: " << player->getWrong() << endl;
	cout << "Coins: " << setprecision(2) << fixed << player->getCoinCount() << endl;
	system("pause");
}//end updateRoundStats

//Display overall stats since creation of player file displayed
//Accepts pointer to memory address of player
void showOverallStats(Player *& player)
{
	cout << "        ****************************************" << endl;
	cout << "          OVERALL STATS INLCUDING THIS ROUND:\n"
		<< "          Right answers: " << player->showOverallRight() << endl;
	cout << "          Wrong answers: " << player->showOverallWrong() << endl;
	cout << "          Coins: " << setprecision(2) << fixed << player->showOverallCoins() << endl;
	cout << "        ****************************************" << endl;
}//end showOverallStats

//Converts string to integer
//ASCII values to integer values
//String function stoi() was too buggy to use
int stringToInt(string userInput)
{
	string input = userInput;
	int inputLength = input.length();
	int counter = 0;
	int inputAsInt = 0;
	while (counter < inputLength)
	{
		inputAsInt = inputAsInt * 10 + (input[counter] - '0');
		counter++;
	}
	return inputAsInt;
}//end of string to int
