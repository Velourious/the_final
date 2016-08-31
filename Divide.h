#pragma once
#ifndef DIVIDE_H
#define DIVIDE_H
#include "MathProblem.h"

using namespace std;

class Divide; //FWD declaration

				//Stream prototype
ostream &operator <<(ostream & someStream, const Divide &DivideProblem);

class Divide : public MathProblem
{
public:
	Divide();
	Divide(int tempA, int tempB);

	int getAnswer()
	{
		return answer;
	}

private:
	int answer;
};

#endif // !DIVIDE_H
