#include<iostream>
#include<fstream>

typedef int(*Key)(int);
typedef bool(*Condition)(char, int);

using namespace std;

void CreateFile(const char*, int);
int* InitArray(const char*, int);
void AddFile(const char*, int*, int);
int Partition(int*, int, int, Key);
int GettingKeys(int);
bool IsInclude(char, int);
void QuickSort(int*, int, int, Key);
int* GetDeletedElements(int*, int& , char, Condition);
int* AllocateMemoryInt(int);
void DeleteElements(int*, int&, int);
int GetAmountOfDeletedElements(int*, int, char, Condition);

int main()
{
	const char* fileName = "C:\\Users\\Polina\\Desktop\\проекты\\2 семестр\\17.04.2019\\17.04.2019\\test.txt";
	int n;
	cout << "Enter count of the numbers:" << endl;
	cin >> n;

	CreateFile(fileName, n);
	
	int* array = InitArray(fileName, n);
	QuickSort(array, 0, n - 1, GettingKeys);
	AddFile(fileName, array, n);

	char symbol;
	cout << "enter symbol";
	cin >> symbol;

	int m = GetAmountOfDeletedElements(array, n, symbol, IsInclude);
	int* deletedArray = GetDeletedElements(array, n, symbol, IsInclude);
	AddFile(fileName, array, n);
	AddFile(fileName, deletedArray, m);

	system("pause");
}

void CreateFile(const char* fileName, int n)
{
	ofstream streamOut(fileName);

	if (!streamOut.is_open())
	{
		cout << "Cannot open file to write!" << endl;
		system("pause");
		exit(1);
	}

	for (int i = 1; i <= n; i++)
	{
		int temp = n - i;
		streamOut.width(5);
		streamOut << temp;
	}

	streamOut.close();
}

int* InitArray(const char* fileName, int n)
{
	ifstream streamIn(fileName);
	if (!streamIn.is_open())
	{
		cout << "Cannot open file to read!" << endl;
		system("pause");
		exit(1);
	}
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
		streamIn >> arr[i];
	streamIn.close();
	return arr;
}

void AddFile(const char* fileName, int* arr, int n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}
	streamOut << "\nSorted array!\n";
	for (int i = 0; i < n; i++)
	{
		streamOut.width(5);
		streamOut << arr[i];
	}
	streamOut.close();
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

void QuickSort(int* array, int left, int right, Key key)
{
	if (left < right)
	{
		int pivot = Partition(array, left, right, key);
		QuickSort(array, left, pivot - 1, key);
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
			swap(array[i], array[j]);
		}
	}

	swap(array[i + 1], array[high]);

	return i + 1;
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

int* AllocateMemoryInt(int n)
{
	if (n <= 0)
	{
		throw invalid_argument("Count of array elements can not be less or equal 0.");

	}

	int* array = new int[n];

	return array;
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