#pragma once
#include <iostream>

using namespace std;

class ComplexNumber
{
	friend ostream& operator<<(ostream&, const ComplexNumber&);
public:

	ComplexNumber() : ComplexNumber(1, 1)
	{

	}

	ComplexNumber(double, double);

#pragma region Set Functions
	void setA(double);

	void setB(double);

	void setComplexNumber(double, double);
#pragma endregion

#pragma region Get Functions
	double getA() const;

	double getB() const;

	ComplexNumber getReverse() const;

	double getModule() const;

	double getSin() const;

	double getCos() const;
#pragma endregion 

#pragma region Operator Functions
	ComplexNumber& operator=(const ComplexNumber& number);

	ComplexNumber& operator+(const ComplexNumber& number) const;

	ComplexNumber& operator-(const ComplexNumber& number) const;

	ComplexNumber& operator-() const;

	ComplexNumber& operator*(const ComplexNumber& number) const;

	ComplexNumber& operator/(const ComplexNumber& other) const;
#pragma endregion

private:
	double a, b;
};
