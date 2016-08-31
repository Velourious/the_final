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

#include <iostream>
#include <iomanip>
#include "Subtract.h"

using namespace std;

const int MIN = 0;
const int MAX = 10;

Subtract::Subtract()
{
	if (b > a)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}

	answer = a - b;
}

Subtract::Subtract(int tempA, int tempB)
{
	//do not accept negative ints
	if (tempA < 0) //if int a is negative
	{
		cout << tempA << " is out of range.";
		a = (rand() % (MAX - MIN + 1)) + MIN; //generate new int a
		cout << " This number's been replaced with " << a << ".\n";
	}
	else
	{
		a = tempA;
	}

	if (tempB < 0) //if b is negative
	{
		cout << tempB << " is out of range.";
		b = (rand() % (MAX - MIN + 1)) + MIN; // generate new b
		cout << " This number is now " << b << ".\n";
	}
	else
	{
		b = tempB;
	}

	if (b > a)
	{
		int temp;
		temp = a;
		a = b;
		b = temp;
	}

	answer = a - b;
}

ostream &operator <<(ostream & someStream, const Subtract &SubtractProblem)
{
	someStream << SubtractProblem.getA() << " - " << SubtractProblem.getB() << " = ";
	return someStream;
}
