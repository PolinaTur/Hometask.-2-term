#pragma once
#include <iostream>

typedef double(*Function)(double, double);
typedef int(*Key)(int);
typedef bool(*Predicate)(int, int);
typedef bool(*Condition)(char, int);

using namespace std;

double** AllocateMemory(int);
int ValidationOfElement();
double GettingAccurancy();
void DisplayMatrix(double**, int);
void DisplayArrayInt(int*, int);
void InPutArray(int*, int);
int* AllocateMemoryInt(int);
char InPutElement();
void DeleteElements(int*, int&, Predicate);
void Swap(int&, int&);
int GetAmountOfDeletedElements(int*, int, char, Condition);
void DeleteElements(int*, int&, int);
int Partition(int*, int, int, Key);
void QuickSort(int*, int, int,Key);

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

int ValidationOfElement()
{
	int n;
	while (true)
	{
		cout << "Enter n";
		cin >> n;

		if (n > 0)
		{
			return n;
		}

		cout << "Invalid data! Try again :)" << endl;
	}
}

double GettingAccurancy()
{
	double n;
	while (true)
	{
		cout << "Enter accurancy";
		cin >> n;

		if (n > 0 && n < 1)
		{
			return n;
		}

		cout << "Invalid data! Try again :)" << endl;
	}
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

void DisplayArrayInt(int* array, int n)
{
	for (int* p = array; p < array + n; p++)
	{
		cout << *p << " ";
	}

	cout << endl;
}

int* AllocateMemoryInt(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}

	int* array = new int[n];

	return array;
}

void InPutArray(int* array, int n)
{
	for (int* p = array, i = 1; p < array + n; p++, i++)
	{
		cout << "a[" << i << "]= ";
		cin >> *p;
	}
}

char InPutElement()
{
	char element;
	cout << "\nPlease enter symbol from A to F: ";
	cin >> element;
	return element;
}

void DeleteElements(int* array, int& n, Predicate predicate)
{
	int m = n;
	for (int i = 0; i < m - 1; i++)
	{
		if (predicate(array[i], array[i + 1]))
		{
			DeleteElements(array, n, i + 1);
		}
	}


}

void Swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

int GetAmountOfDeletedElements(int* array, int n, char symbol, Condition condition)
{
	int i = 0, k = 0;

	while (i < n)
	{
		if (condition(symbol, array[i]))
		{
			k++;
		}

		i++;
	}

	return k;
}

void DeleteElements(int* array, int& n, int index)
{
	int m = n;
	for (int i = index - 1; i < m; i++)
	{
		array[i] = array[i + 1];
	}

	n--;
}

void QuickSort(int* array, int left, int right, Key key)
{
	if (left < right)
	{
		int pivot = Partition(array, left, right, key);
		QuickSort(array, left, pivot - 1,key);
		QuickSort(array, pivot + 1, right, key);
	}
}

int Partition(int* array, int low, int high, Key key)
{
	int pivot = array[high];

	int i = low - 1;
	for (int j = low; j < high; j++)
	{
		if (key(array[j]) <= key(pivot))
		{
			i++;
			Swap(array[i], array[j]);
		}
	}

	Swap(array[i + 1], array[high]);

	return i + 1;
}
