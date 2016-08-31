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
#include "Divide.h"

using namespace std;

const int MIN = 0;
const int MAX = 10;

Divide::Divide()
{
	if (b == 0) //avoid division by 0
	{
		b = 1;
	}

	answer = a * b;

	int temp;
	temp = a;
	a = answer;
	answer = temp; //now format is answer / b = a
					//new answer will be whole number
}

Divide::Divide(int tempA, int tempB)
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

	if (tempB <= 0) //if b is negative
	{
		cout << tempB << " is out of range.";
		b = (rand() % (MAX - MIN + 1)) + MIN; // generate new b
		cout << " This number is now " << b << ".\n";
	}
	else
	{
		b = tempB;
	}

	answer = a * b;	

	int temp;
	temp = a;
	a = answer;
	answer = temp; //now format is answer / b = a
					//new answer will be whole number
}

ostream &operator <<(ostream & someStream, const Divide &DivideProblem)
{
	someStream << DivideProblem.getA() << " / " << DivideProblem.getB() << " = ";
	return someStream;
}
