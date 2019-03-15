#include <iostream>
#include "DynamicArray.h"

using namespace std;

int GettingKeys(int);
bool IsEqual(int, int);
bool IsInclude(char, int);
int* GetDeletedElements(int*, int&, char, Condition);

int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		int n = ValidationOfElement();
		int* array = nullptr;

		try
		{
			array = AllocateMemoryInt(n);
		}
		catch (const invalid_argument& ex)
		{
			cerr << "Invalid argument: " << ex.what() << '\n';
		}

		InPutArray(array, n);
		system("cls");

		cout << "The soucre array is:" << endl;
		DisplayArrayInt(array, n);

		QuickSort(array, 0, n - 1, GettingKeys);
	    DeleteElements(array, n, IsEqual);

		char symbol = InPutElement();
        
		int m = GetAmountOfDeletedElements(array, n, symbol, IsInclude);
		int* deletedArray = nullptr;

		try
		{
			deletedArray = AllocateMemoryInt(m);
		}
		catch (const invalid_argument& ex)
		{
			cerr << "Invalid argument: " << ex.what() << '\n';
		}
		
		deletedArray = GetDeletedElements(array, n, symbol, IsInclude);

		cout << "The array elements of which doesn't consist the given symbol:" << endl;
		DisplayArrayInt(array, n);
		cout << "The array elements of  which consist the given symbol:" << endl;
		DisplayArrayInt(deletedArray, m);

		cout << "Press y ot Y to continue";
		cin >> esc;
		system("cls");

	}

	return 0;
}

int GettingKeys(int number)
{
	int remainder = 0, current = abs(number);

	while (current)
	{
		remainder = current % 16;
		current /= 16;
	}

	return remainder;
}

bool IsEqual(int x, int y)
{
	return x == y;
}

bool IsInclude(char symbol, int number)
{
	switch (symbol)
	{

	case 'A':
	case 'a':
	{
		while (number)
		{
			if (number % 16 == 10)
			{
				return 1;
			}
			number /= 16;
		}
		return 0;
		break;
	}

	case 'B':
	case 'b':
	{
		while (number)
		{
			if (number % 16 == 11)
			{
				return 1;
			}
			number /= 16;
		}
		return 0;
		break;
	}

	case 'C':
	case 'c':
	{
		while (number)
		{
			if (number % 16 == 12)
			{
				return 1;
			}
			number /= 16;
		}
		return 0;
		break;
	}

	case 'D':
	case 'd':
	{
		while (number)
		{
			if (number % 16 == 13)
			{
				return 1;
			}
			number /= 16;
		}
		return 0;
		break;
	}

	case 'E':
	case 'e':
	{
		while (number)
		{
			if (number % 16 == 14)
			{
				return 1;
			}
			number /= 16;
		}
		return 0;
		break;
	}

	case 'F':
	case 'f':
	{
		while (number)
		{
			if (number % 16 == 15)
			{
				return 1;
			}
			number /= 16;
		}
		return 0;
		break;
	}

	default:
	{
		cout << "The letter you have entered doesn't match the condition of the problem. Please Try one more time";
	}

	}
}

int* GetDeletedElements(int* array, int& n, char symbol, Condition condition)
{
	int* result = AllocateMemoryInt(n);
	int m = n;

	for (int i = 0, j = 0; i < m; i++)
	{
		if (condition(symbol, array[i]))
		{
			result[j] = array[i];
			j++;
			DeleteElements(array, n, i + 1);
		}

	}

	return result;

}

//Tests:
//n = 10
//symbol = A
//source array:0 10 26 15 36 7 8 32 45 42
//	array which consist:26 42 10
//	deleted array:0 36 32 45 7 8 15
//n = 13
//symbol = F
//source array:4 26 7 8 15 0 2 24356 31 10 1 3 456
//	array which consist:31 24356 15
//	deleted array:0 26 1 456 2 3 4 7 8 10
