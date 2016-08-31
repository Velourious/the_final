#include <iostream>
#include <iomanip>
#include "MathProblem.h"

using namespace std;

const int MIN = 0;
const int MAX = 10;

MathProblem::MathProblem()
{
	unsigned seed = time(0);
	srand(seed);

	a = (rand() % (MAX - MIN + 1)) + MIN;
	b = (rand() % (MAX - MIN + 1)) + MIN;
}

MathProblem::MathProblem(int tempA, int tempB)
{
	this->setNumbers(tempA, tempB);
}

void MathProblem::setNumbers(int tempA, int tempB)
{	
	//int a & b will be between 0 - 10
	if (tempA < MIN || tempA > MAX) //if a not between 0 - 10
	{
		cout << "\nFirst number was out of range.";
		a = (rand() % (MAX - MIN + 1)) + MIN; //generate new a in range
		cout << " First number is now " << a << ".\n";
	}
	else
	{
		a = tempA;
	}

	if (tempB < 0 || tempB > 20) //if b not between 0 - 10
	{
		cout << "\nSecond number was out of range.";
		b = (rand() % (MAX - MIN + 1)) + MIN; // generate new b in range
		cout << " Second number is now " << b << ".\n";
	}
	else
	{
		b = tempB;
	}
}
