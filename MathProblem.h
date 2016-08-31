#pragma once
#ifndef MATHPROBLEM_H
#define MATHPROBLEM_H

using namespace std;

class MathProblem; //FWD declaration

class MathProblem
{
public:
	MathProblem(); //default constructor
	MathProblem(int tempA, int tempB); //overloaded constructor

	void setNumbers(int tempA, int tempB); //set int a & b

	//returns int a
	int getA() const 
	{	return a;	}

	//returns int b
	int getB() const
	{	return b;	}


protected:
	int a, b;
};
#endif // !MathProblem_H
