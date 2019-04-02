#pragma once
#include <iostream>

using namespace std;

class Fractions
{
public:
	Fractions() : Fractions(1, 1)
	{

	}

	Fractions(int, int);

#pragma region Set Functions
	void setNumerator(int);

	void setDenominator(int);

	void setFraction(int, int);
#pragma endregion

#pragma region Get Functions
	int getNumerator();

	int getDenominator();

	double getSumOfFractions(Fractions);

	double getMultiplicationOfFractions(Fractions);

	double getQuotientOfFractiobs(Fractions);
#pragma endregion 

	void DisplayFraction();

	bool IsProperFraction() const;

private:
	int numerator, first;
};
