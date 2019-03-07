#include <iostream>

using namespace std;

typedef int(*Key)(int);
typedef bool(*Predicate)(int, int);
typedef bool(*Condition)(char, int);

void DisplayArrayInt(int*, int);
void InPutArray(int*, int);
int* AllocateMemoryInt(int);
char InPutElement();
int ValidationOfElement();
int GettingKeys(int);
void Swap(int&, int&);
void DeleteElements(int*, int&, Predicate);
bool IsEqual(int, int);
bool IsInclude(char, int);
int* GetDeletedElements(int*, int&, char, Condition);
int GetAmountOfDeletedElements(int*, int, char, Condition);
void DeleteElements(int*, int&, int);
int Partition(int*, int, int, Key);
void QuickSort(int* , int, int);


int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		int n = ValidationOfElement();
		int* array = AllocateMemoryInt(n);

		InPutArray(array, n);
		system("cls");

		cout << "The soucre array is:" << endl;
		DisplayArrayInt(array, n);

		QuickSort(array, 0, n - 1);
	
		DeleteElements(array, n, IsEqual);

		char symbol = InPutElement();

		int m = GetAmountOfDeletedElements(array, n, symbol, IsInclude);
		int* deleted_array = AllocateMemoryInt(m);
		deleted_array = GetDeletedElements(array, n, symbol, IsInclude);

		cout << "The array elements of which doesn't consist the given symbol:" << endl;
		DisplayArrayInt(array, n);
		cout << "The array elements of  which consist the given symbol:" << endl;
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

void QuickSort(int* array, int left, int right)
{
	if (left < right)
	{
		int pivot = Partition(array, left, right, GettingKeys);
		QuickSort(array, left, pivot - 1);
		QuickSort(array, pivot + 1, right);
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
			Swap(array[i],array[j]);
		}
	}

	Swap(array[i + 1],array[high]);

	return i + 1;
}

//Tests:
//n = 10
//symbol = A
//source array:0 10 26 15 36 7 8 32 45 42
//	array which consist:26 42 10
//	deleted array:0 36 32 45 7 8 15


//Tests:
//n = 13
//symbol = F
//source array:4 26 7 8 15 0 2 24356 31 10 1 3 456
//	array which consist:31 24356 15
//	deleted array:0 26 1 456 2 3 4 7 8 10

