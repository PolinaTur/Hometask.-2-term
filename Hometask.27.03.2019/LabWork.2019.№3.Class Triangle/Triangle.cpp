#include "Triangle.h"

Triangle::Triangle(double x, double y, double z)
{
	setTriangle(x, y, z);
	number = 1;
}

Triangle::~Triangle()
{
	cout << "I am dead!!!";
}

bool Triangle::isTriangleValid(double x, double y, double z)
{
	return !(x + y <= z || x + z <= y || z + y <= x);
}

#pragma region Set
void Triangle::setSideA(double x)
{
	if (x <= 0)
	{
		throw invalid_argument("The side x can't be less or equal 0 ");
	}

	a = x;
}

void Triangle::setSideB(double y)
{
	if (y <= 0)
	{
		throw invalid_argument("The side y can't be less or equal 0 ");
	}

	b = y;
}

void Triangle::setSideC(double z)
{
	if (z <= 0)
	{
		throw invalid_argument("The side z can't be less or equal 0 ");
	}

	c = z;
}

void Triangle::setTriangle(double x, double y,double z)
{
	setSideA(x);
	setSideB(y);
	setSideC(z);

	if (!(isTriangleValid(x, y, z)))
	{
		throw invalid_argument("The triangle with such sideds doesn't exist ");
	}
}
#pragma endregion

#pragma region Get
double Triangle::getSideA()
{
	return a;
}

double Triangle::getSideB()
{
	return b;
}

double Triangle::getSideC()
{
	return c;
}
#pragma endregion

#pragma region Const Methods
double Triangle::getPerimeter() const
{
	return a + b + c;
}

int Triangle::compareTo(Triangle other)
{
	if (equalsTo(other))
	{
		return 0;
	}

	return (getPerimeter() < other.getPerimeter()) ? -1 : 1;
}

void Triangle::display() const
{
	cout << "<" << a << "," << b << "," << c << ">" << endl;
}

double Triangle::getArea() const
{
	double area = 0;
	double p = getPerimeter() / 2;
	area = p * (p - a)*(p - b)*(p - c);
	return pow(area, 0.5);
}

bool Triangle::isEquilateral() const
{
	return a == b && b == c;
}

bool Triangle::isIsosceles() const
{
	return a == b || b == c || c == a;
}

bool Triangle::equalsTo(Triangle other) const
{
	return fabs(getPerimeter() - other.getPerimeter()) <= 0.000001;
}

#pragma endregion
