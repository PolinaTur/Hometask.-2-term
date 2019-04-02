#pragma once
#include <iostream>

using namespace std;

class Triangle
{
public:
#pragma region  ctors
	Triangle() : Triangle(1, 1, 1)
	{

	}
	Triangle(double x, double y, double z);
#pragma endregion

~Triangle();

#pragma region Set
void setSideA(double);

void setSideB(double);

void setSideC(double);

void setTriangle(double, double, double);
#pragma endregion

#pragma region Get
double getSideA();

double getSideB();

double getSideC();
#pragma endregion
   
#pragma region Const Methods
double getPerimeter() const;

int compareTo(Triangle);

void display() const;

double getArea() const;

bool isEquilateral() const;

bool isIsosceles() const;

bool equalsTo(Triangle) const;
#pragma endregion

private:
	double a, b, c;
	int number;
	static bool isTriangleValid(double x, double y, double z);	
};
