#include <iostream>
#include "DynamicArray.h"
#include "Matrix.h"

using namespace std;

int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		int n = ValidationOfElement();

		double** matrix = AllocateMemory(n);
		double** matrixDifference = AllocateMemory(n);

		double accurancy = GettingAccurancy();

		GettingMatrix(matrix, n, accurancy, TaylorRowSinus);
		GettingDifference(matrixDifference, matrix, n);

		cout << "The maximal difference between elements is: " << FindMaximum(matrixDifference, n) << endl ;

		cout << "Press y ot Y to continue";
		cin >> esc;
		system("cls");
	}

	return 0;
}