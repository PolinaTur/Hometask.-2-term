#include "ComplexNumber.h"
#include <stdexcept>

ComplexNumber::ComplexNumber(double a, double b)
{
	setComplexNumber(a, b);
}

#pragma region Set Functions
void ComplexNumber::setA(double x)
{
	a = x;
}

void ComplexNumber::setB(double y)
{
	b = y;
}

void ComplexNumber::setComplexNumber(double x, double y)
{
	setA(x);
	setB(y);
}

#pragma endregion

#pragma region Get Functions
double ComplexNumber::getA() const
{
	return a;
}

double ComplexNumber::getB() const
{
	return b;
}
 
ComplexNumber ComplexNumber::getReverse() const
{
	return ComplexNumber(getA(),-getB());
}

double ComplexNumber::getModule() const
{
	double x = getA(), y = getB();
	return pow((pow(x,2) + pow(y,2)),0.5);
}

double ComplexNumber::getSin() const
{
	return getB()/getModule();
}

double ComplexNumber::getCos() const
{
	return getA() / getModule();
}
#pragma endregion

#pragma region Operator Functions
ComplexNumber& ComplexNumber::operator=(const ComplexNumber& number)
{
	setComplexNumber(number.getA(), number.getB());
	return *this;
}

ComplexNumber& ComplexNumber::operator+(const ComplexNumber& number) const
{
	double a = getA() + number.getA();
	double b = getB() + number.getB();
	ComplexNumber result(a, b);
	return result;
}

ComplexNumber& ComplexNumber::operator-(const ComplexNumber& number) const
{
	ComplexNumber temp = -number;
	return *this + temp;
}

ComplexNumber& ComplexNumber::operator-() const
{
	ComplexNumber result(-getA(), getB());
	return result;
}

ComplexNumber& ComplexNumber::operator*(const ComplexNumber& other) const
{
	double a = getA()*other.getA() - getB()*other.getB();
	double b = getA()*other.getB() + getB()*other.getA();
	ComplexNumber result(a, b);
	return result;
}

ComplexNumber& ComplexNumber::operator/(const ComplexNumber& other) const
{
	ComplexNumber numerator = *this * other.getReverse();
	ComplexNumber denominator = other * other.getReverse();
	double den = denominator.getA() + denominator.getB();

	ComplexNumber result((numerator.getA()) / den, (numerator.getB()) / den);
	return result;
}
#pragma endregion

ostream & operator<<(ostream& stream, const ComplexNumber& number)
{
	if (number.getB() == 0)
	{
		return stream << number.getA();
	}
	else if (number.getA() == 0)
	{
		return stream << number.getB() << "i";
	}
	else if (number.getB() < 0)
	{
		return stream << number.getA() << number.getB() << "i";
	}
	else
	{
		return stream << number.getA() << "+" << number.getB() << "i";
	}
}
