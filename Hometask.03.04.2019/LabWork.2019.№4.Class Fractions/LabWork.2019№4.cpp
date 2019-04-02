#include <iostream>
#include "Fractions.h"

typedef int(*Key)(Fractions);
typedef bool(*Predicate)(int);

Fractions* AllocateMemory(int);
Fractions FindFraction(Fractions*, int, Predicate, Predicate);
void setArrayOfFractions(Fractions*, int);
bool IsDenominatorEven(int);
bool IsNumeratorpositive(int);
void Display(Fractions*, int);
int CompareTo(Fractions, Fractions);
void QuickSort(Fractions* fractions, int n, Key key);
void QuickSort(Fractions* fractions, int left, int right, Key key);
int Partition(Fractions* array, int low, int high, Key key);
void Swap(Fractions& x, Fractions& y);
int GetKey(Fractions);

using namespace std;

int main()
{
	int n;
	cout << "Enter n:";
	cin >> n;

	Fractions* array = nullptr;

	try
	{
		array = AllocateMemory(n);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	setArrayOfFractions(array, n);
	cout << "The source array of fractions is:";
	Display(array, n);
	cout << endl;

	QuickSort(array, n,GetKey);
	cout << "The sorted array of fractions is:";
	Display(array, n);
	cout << endl;

	system("pause");
	return 0;
}

Fractions* AllocateMemory(int n)
{
	if (n <= 0)
	{
		throw invalid_argument("The amount of elements in array can't be less or equal to 0");
	}

	Fractions* array = new Fractions[n];

	if (array == nullptr)
	{
		throw invalid_argument("The poiner to array can't be nullptr");
	}

	return array;
}

Fractions FindFraction(Fractions* array, int n, Predicate predicateNumerator, Predicate predicateDenominator)
{
	for (int i = 0; i < n; i++)
	{
		if (predicateNumerator(array[i].getNumerator()) && predicateDenominator(array[i].getDenominator()))
		{
			return array[i];
		}

	}
}

void setArrayOfFractions(Fractions* array, int n)
{
	int m, k;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter the numerator and denominator of fraction:";
		cin >> m;
		cin >> k;
		array[i].setFraction(m, k);
	}

	system("cls");
}

#pragma region Predicates
bool IsDenominatorEven(int denominator)
{
	return denominator % 2 == 0 ? true : false;
}

bool IsNumeratorpositive(int numerator)
{
	return numerator > 0 ? true : false;
}
#pragma endregion

void Display(Fractions* fractions, int n)
{
	for (int i = 0; i < n; i++)
	{
		fractions[i].DisplayFraction();
	}
}

#pragma region QuickSort
void QuickSort(Fractions* fractions, int n,Key key)
{
	QuickSort(fractions, 0, n - 1,key);
}

void QuickSort(Fractions* fractions, int left, int right,Key key)
{
	if (left < right)
	{
		int pivot = Partition(fractions, left, right,key);
		QuickSort(fractions, left, pivot - 1,key);
		QuickSort(fractions, pivot + 1, right,key);
	}
}

int Partition(Fractions* array, int low, int high,Key key)
{
	Fractions pivot = array[high];

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

void Swap(Fractions& x, Fractions& y)
{
	Fractions t = x;
	x = y;
	y = t;
}
#pragma endregion

int CompareTo(Fractions first,Fractions second)
{
	if (first.getDenominator() == second.getDenominator() && first.getNumerator() == second.getNumerator())
	{
		return 0;
	}

	else if (first.getDenominator() == second.getDenominator())
	{
		return first.getNumerator() > second.getNumerator() ? 1 : -1;
	}

	else if (first.getNumerator() == second.getNumerator())
	{
		return first.getDenominator() < second.getDenominator() ? 1 : -1;
	}

	else
	{
		return first.getNumerator() * second.getDenominator() > first.getDenominator() * second.getNumerator() ? 1 : -1;
	}
}

int GetKey(Fractions fraction)
{
	return fraction.getDenominator() + fraction.getNumerator();
}