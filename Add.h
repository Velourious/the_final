//Derived from MathProblem class which 
//sets int a and int b to random numbers
//between 0 - 10.
//MathProblem class contains:
//
//VARIABLES:
//int a, int b
//
//FUNCTIONS:
//int getA(), int getB(),
//setNumbers(int tempA, int tempB)

#pragma once
#ifndef ADD_H
#define ADD_H

#include "MathProblem.h"

using namespace std;

class Add; //FWD declaration

//Stream prototype
ostream &operator <<(ostream & someStream, const Add &AddProblem);

class Add : public MathProblem //Add is derived from MathProblem class
{
public:
	Add();
	Add(int tempA, int tempB);

	int getAnswer()
	{	return answer;	}

private:
	int answer;
};
#endif // !Add_H
