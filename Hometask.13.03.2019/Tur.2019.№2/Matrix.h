#pragma once
#include <iostream>

typedef double(*Function)(double, double);

using namespace std;

double** AllocateMemory(int);
int ValidationOfElement();
void DisplayMatrix(double**, int);
double FindMaximum(double, double);
double FindMaximum(double*, int);
double FindMaximum(double**, int);
double ConverToRadians(double);
void GettingMatrix(double**, int, double, Function);
void GettingDifference(double**, double**, int);
double TaylorRowSinus(double, double);

double** AllocateMemory(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}

	double** array = new double*[n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new double[n];
	}

	return array;
}

void DisplayMatrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout.width(10);
			cout.precision(4);
			cout << matrix[i][j];
		}

		cout << endl;
	}

	cout << endl;
}

double FindMaximum(double x, double y)
{
	return (x > y) ? x : y;
}

double FindMaximum(double* array, int n)
{
	int i = 0;
	double maximum = array[i];

	while (i < n)
	{
		maximum = FindMaximum(maximum, array[i]);
		i++;
	}

	return maximum;
}

double FindMaximum(double** matrix, int n)
{
	int i = 0;
	double maximum = FindMaximum(matrix[i], n);

	while (i < n)
	{
		maximum = FindMaximum(maximum, FindMaximum(matrix[i], n));
		i++;
	}

	return maximum;
}

double ConverToRadians(double x)
{
	return x = fmod(x, 2 * 3.14);
}

void GettingMatrix(double** matrix, int n, double accurancy, Function function)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = (function(ConverToRadians(i + j), accurancy) - function(ConverToRadians(i - j), accurancy));
			}

		}
	}
}

void GettingDifference(double** matrixDifference, double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				matrixDifference[i][j] = fabs(matrix[i][j] / pow((i + j + 1), 2) - (sin(ConverToRadians(i + j)) - sin(ConverToRadians(i - j))) / pow((i + j + 1), 2));
			}
			else
			{
				matrixDifference[i][j] = fabs(matrix[i][j] - 1);
			}

		}
	}
}

double TaylorRowSinus(double x, double accurancy)
{
	double term = x;
	double sinus = 0.0;
	int i = 1;

	while (fabs(term) > accurancy)
	{
		sinus += term;
		term *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
		i++;
	}

	return sinus;
}
