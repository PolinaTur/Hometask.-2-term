#include "Matrix.h"

using namespace std;
using namespace matrix;

int matrix::InPutDimention()
{
	int n;
	cout << " Enter n (dimention):";
	cin >> n;

	try
	{
		n = ValidationOfElement(n);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	return n;
}

#pragma region Validation
int matrix::ValidationOfElement(int n)
{
	if (n <= 0)
	{
		throw invalid_argument("The count of elements of array can't be less or equal to 0");
	}
	else
	{
		return n;
	}
}

int* matrix::ValidationOfArray(int* array, int n)
{
	try
	{
		n = ValidationOfElement(n);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	if (array == nullptr)
	{
		throw invalid_argument("The pointer to array can't be equal to nullptr");
	}

	return array;
}

int** matrix::ValidationOfMatrix(int** matrix, int* array, int n)
{
	if (matrix == nullptr)
	{
		throw invalid_argument("The pointer to matrix can't be equal to nullptr");
	}

	try
	{
		array = ValidationOfArray(array, n);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	for (int i = 0; i < n; i++)
	{
		array[i] = ValidationOfElement(array[i]);
	}

	return matrix;
}
#pragma endregion

#pragma region Allocate
int* matrix::AllocateMemoryInt(int n)
{
	int* array = new int[n];
	array = ValidationOfArray(array, n);

	return array;
}

int** matrix::AllocateMemory(int n, int* dimentions)
{
	try
	{
		dimentions = ValidationOfArray(dimentions, n);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	
	int** matrix = new int*[n];

	try
	{
		matrix = ValidationOfMatrix(matrix, dimentions, n);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	for (int i = 0; i < n; i++)
	{
		matrix[i] = AllocateMemoryInt(dimentions[i]);
	}

	return matrix;
}
#pragma endregion

#pragma region Random
void matrix::RandomArray(int* array, int n, int max)
{
	for (int i = 0; i < n; i++)
	{
		array[i] = rand() % max;
	}
}

void matrix::RandomMatrix(int** matrix, int n, int* dimentions)
{
	for (int i = 0; i < n; i++)
	{
		RandomArray(matrix[i], dimentions[i], 50);
	}
}
#pragma endregion

void matrix::DisplayMatrix(int** matrix, int n, int* dimentions)
{
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < dimentions[i]; j++)
		{
			cout.width(5);
			cout << matrix[i][j];
		}

		cout << endl;
	}

	cout << endl;
}

#pragma region Delete
void matrix::DeleteElements(int* array, int& n, Predicate predicate)
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

void matrix::DeleteElements(int* array, int& n, int index)
{
	int m = n;
	for (int i = index - 1; i < m; i++)
	{
		array[i] = array[i + 1];
	}

	n--;
}
#pragma endregion

bool matrix::IsEqual(int x, int y)
{
	return x == y;
}

void matrix::Swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

int matrix::GettingKeys(int number)
{
	int remainder = 0, current = abs(number);

	while (current)
	{
		remainder = current % 16;
		current /= 16;
	}

	return remainder;
}

#pragma region QuickSort
void matrix::QuickSort(int* array, int n, Key key)
{
	QuickSort(array, 0, n - 1, key);
}

void matrix::QuickSort(int* array, int left, int right, Key key)
{
	if (left < right)
	{
		int pivot = Partition(array, left, right, key);
		QuickSort(array, left, pivot - 1, key);
		QuickSort(array, pivot + 1, right, key);
	}
}

int matrix::Partition(int* array, int low, int high, Key key)
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
#pragma endregion

void matrix::GetSorted(int** matrix, int n, int* dimentions, Sort sort, Key key)
{
	for (int i = 0; i < n; i++)
	{
		if (dimentions[i] % 2)
		{
			sort(matrix[i], dimentions[i], key);
			DeleteElements(matrix[i], dimentions[i], IsEqual);
		}
	}
}