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
#ifndef SUBTRACT_H
#define SUBTRACT_H

#include "MathProblem.h"

using namespace std;
class Subtract; //FWD declaration

//Stream prototype
ostream &operator <<(ostream & someStream, const Subtract &SubtractProblem);

class Subtract : public MathProblem
{
public:
	Subtract();
	Subtract(int tempA, int tempB);

	int getAnswer()
	{	return answer;	}

private:
	int answer;
};
#endif // !SUBTRACT_H
