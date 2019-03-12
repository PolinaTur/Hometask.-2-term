#include <iostream>
#include "DynamicArray.h"


using namespace std;

double TaylorRowSinus(double, double);
void GettingMatrixA(double**,int, double, Function);
void GettingMatrixB(double** matrix, int n);
double** GettingDifference(double**, double**, int);


int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		int n = ValidationOfElement();
	
		double** matrixA = AllocateMemory(n);
		double** matrixB = AllocateMemory(n);

		double accurancy = GettingAccurancy();

		GettingMatrixA(matrixA, n, accurancy, TaylorRowSinus);
        GettingMatrixB(matrixB, n);
	
		double** matrixC = GettingDifference(matrixB,matrixA, n);
		DisplayMatrix(matrixC, n);

		cout << "Press y ot Y to continue";
		cin >> esc;
		system("cls");

	}

	return 0;
}

double TaylorRowSinus(double x, double accurancy)
{
	double term = x;
	double sinus = 0.0;
	int i = 1;

	while (fabs(term) > accurancy)
	{
		sinus += term;
		term *= - 1.0 * x * x / ((2 * i) * (2 * i + 1));
		i++;
	}

	return sinus;
}

void GettingMatrixA(double** matrix,int n, double accurancy, Function function)
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
				matrix[i][j] = (function(i + j, accurancy) - function(i - j, accurancy));
			}

		}
	}
}


void GettingMatrixB(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{
		
		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				matrix[i][j] = (sin(i + j) - sin(i - j)) / pow((i + j + 1), 2);
			}
			else
			{
				matrix[i][j] = 1;
			}

		}
	}
}

double** GettingDifference(double** matrixA, double** matrixB, int n)
{
	double** matrixC = AllocateMemory(n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			matrixC[i][j] = fabs(matrixA[i][j] - matrixB[i][j]);
		}
	}

	return matrixC;
}

