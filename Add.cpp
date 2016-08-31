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
#include "Add.h"

using namespace std;

const int MIN = 0;
const int MAX = 10;

Add::Add()
{
	answer = a + b;
}

Add::Add(int tempA, int tempB)
{
	//do not accept negative ints
	if (tempA < 0) //if int a is negative
	{
		cout << "\nFirst number was out of range.";
		a = (rand() % (MAX - MIN + 1)) + MIN; //generate new int a in range
		cout << " First number is now " << a << ".\n";
	}
	else
	{
		a = tempA;
	}

	if (tempB < 0) //if b is negative
	{
		cout << "\nSecond number was out of range.";
		b = (rand() % (MAX - MIN + 1)) + MIN; // generate new b in range
		cout << " Second number is now " << b << ".\n";
	}
	else
	{
		b = tempB;
	}

	answer = a + b;
}

ostream &operator <<(ostream & someStream, const Add &AddProblem)
{
	someStream << AddProblem.getA() << " + " << AddProblem.getB() << " = ";
	return someStream;
}
