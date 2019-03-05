#include <iostream>

using namespace std;

typedef int(*Key)(int);
typedef bool(*Predicate)(int,int);
typedef bool(*Condition)(char, int);

void DisplayArrayInt(int*, int);
void InPutArray(int*, int);
int* AllocateMemoryInt(int);
char InPutElement();
int ValidationOfElement();
int GettingKeys(int);
void Swap(int&, int&);
void BubbleSort(int*,int,Key);
void DeleteElements(int*, int& ,Predicate);
bool IsEqual(int, int);
bool IsInclude(char, int);
int* GetDeletedElements(int*, int&, char, Condition);
int GetAmountOfDeletedElements(int*, int, char, Condition);
void DeleteElements(int*, int&, int);


int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		int n = ValidationOfElement();
		int* array = AllocateMemoryInt(n);

		InPutArray(array, n);
		system("cls");

		DisplayArrayInt(array, n);

		BubbleSort(array, n, GettingKeys);
		DeleteElements(array, n, IsEqual);

		char symbol = InPutElement();

		int m = GetAmountOfDeletedElements(array, n, symbol, IsInclude);
		int* deleted_array = AllocateMemoryInt(m);
		deleted_array = GetDeletedElements(array, n, symbol, IsInclude);

		DisplayArrayInt(array, n);
		DisplayArrayInt(deleted_array, m);

		cout << "Press y ot Y to continue";
		cin >> esc;
		system("cls");
	}

	return 0;
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

void Swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

void Swap(double& x, double& y)
{
	int t = x;
	x = y;
	y = t;
}

void BubbleSort(int* array,int n,Key key)
{	
	bool swapped = true;
	int i = 1;
	while (swapped)
	{
		swapped = false;
		for (int j = n - 1; j >= i; j--)
		{
			if (key (array[j]) < key(array[j - 1]))
			{
				Swap(array[j], array[j - 1]);
				swapped = true;
			}
		}
		i++;
	}
	
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

void DeleteElements(int* array , int& n, Predicate predicate)
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

int GetAmountOfDeletedElements(int* array, int n, char symbol, Condition condition)
{
	int i = 0, k  = 0;

    while(i < n)
	{
		if (condition(symbol, array[i]))
		{
			k++;
		}

		i++;
	}

	return k;
}

void DeleteElements(int* array, int& n,int index)
{
	int m = n;
	for (int i = index - 1 ; i < m; i++)
	{
		array[i] = array[i + 1];
	}

	n--;
}

