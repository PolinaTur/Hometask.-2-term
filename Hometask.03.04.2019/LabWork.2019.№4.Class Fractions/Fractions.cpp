#include "Fractions.h"

Fractions::Fractions(int m, int n)
{
	setFraction(m, n);
}

#pragma region Set Functions
void Fractions::setNumerator(int m)
{
	numerator = m;
}

void Fractions::setDenominator(int n)
{
	if (n == 0)
	{
		throw invalid_argument("The denominator can't be equal to 0");
	}

	first = n;
}

void Fractions::setFraction(int m, int n)
{
	setNumerator(m);
	setDenominator(n);
}

#pragma endregion

#pragma region Get Functions
int Fractions::getNumerator()
{
	return numerator;
}

int Fractions::getDenominator()
{
	return first;
}

double Fractions::getSumOfFractions(Fractions other)
{
	if (getDenominator() == other.getDenominator())
	{
		return ((getNumerator() + other.getNumerator()) / getDenominator());
	}
	else
	{
		return (getNumerator() * other.getDenominator() + other.getNumerator()*getDenominator()) / (getDenominator()*other.getDenominator());
	}
}

double Fractions::getMultiplicationOfFractions(Fractions other)
{
	return (getNumerator() * other.getNumerator()) / (getDenominator() * other.getDenominator());
}

double Fractions::getQuotientOfFractiobs(Fractions other)
{
	return (numerator*other.getDenominator()) / (first * other.getNumerator());
}
#pragma endregion

void Fractions::DisplayFraction()
{
	cout << getNumerator() << "/" << getDenominator() << ",";
}

bool Fractions::IsProperFraction() const
{
	return numerator < first ? true : false;
}




