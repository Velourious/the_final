#pragma once
#ifndef MULTIPLY_H
#define MULTIPLY_H
#include "MathProblem.h"

using namespace std;

class Multiply; //FWD declaration

//Stream prototype
ostream &operator <<(ostream & someStream, const Multiply &MultiplyProblem);

class Multiply : public MathProblem
{
public:
	Multiply();
	Multiply(int tempA, int tempB);

	int getAnswer()
	{	return answer;	}

private:
	int answer;
};

#endif // !MULTIPLY_H
