#include<iostream>
#include<fstream>
#include "Matrix.h"

using namespace std;
using namespace matrix;

void CreateFile(const char*,int**, int*,int);
void AddFile(const char*,int**, int*,int);

int main()
{
	const char* fileName = "C:\\Users\\Polina\\Desktop\\проекты\\2 семестр\\17.04.2019\\№3\\test3.txt";
	int n = InPutDimention();

	int* dimentions = AllocateMemoryInt(n);;
	RandomArray(dimentions, n, 20);
	
	int** matrix = AllocateMemory(n, dimentions);;
	RandomMatrix(matrix, n, dimentions);

	CreateFile(fileName,matrix, dimentions, n);

	GetSorted(matrix, n, dimentions, QuickSort, GettingKeys);
	AddFile(fileName, matrix, dimentions, n);

	system("pause");
	return 0;
}

void CreateFile(const char* fileName,int** matrix,int* dimentions, int n)
{
	ofstream streamOut(fileName);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	streamOut << "Source matrix:" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < dimentions[i]; j++)
		{
			streamOut.width(5);
			streamOut << matrix[i][j] ;
		}

		streamOut << endl;
	}

	streamOut.close();
}

void AddFile(const char* fileName,int** matrix, int* arr, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\nSorted matrix!\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			streamOut.width(5);
			streamOut << matrix[i][j];
		}

		streamOut << endl;
	}

	streamOut.close();
}

