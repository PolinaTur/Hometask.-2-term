#include <iostream>

using namespace std;

void DisplayArrayInt(int*, int);
void InPutArray(int*, int);
int* AllocateMemoryInt(int);
char InPutElement();
int ValidationOfElement();
void GettingKeys(int*, int*, int);
void CopyArray(int*, int*, int);
void Swap(int&, int&);
void BubbleSort(int*, int*, int);
int GettingIndexes(int*, int*, char, int);
void GettingDelArray(int*, int*, int*, int, int);


int main()
{
	int n = ValidationOfElement();
	int* array = AllocateMemoryInt(n);

	InPutArray(array, n);
	system("cls");

	DisplayArrayInt(array, n);

	int* keys = AllocateMemoryInt(n);

	int* copy_array = AllocateMemoryInt(n);
	CopyArray(array, copy_array, n);
	GettingKeys(copy_array, keys, n);

	BubbleSort(array, keys, n);
	delete copy_array;
	char symbol = InPutElement();

	int* indexes = AllocateMemoryInt(n);

	int m = GettingIndexes(array, indexes, symbol, n);

	int* new_array = AllocateMemoryInt(m);

	GettingDelArray(array, new_array, indexes, m, n);
	DisplayArrayInt(array, n - m);
	DisplayArrayInt(new_array, m);

	system("pause");
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

void GettingKeys(int* copy_array, int* keys, int n)
{

	for (int i = 0; i < n; i++)
	{
		int current = abs(copy_array[i]);
		int remainder = 0;
		while (current)
		{

			remainder = current % 16;
			keys[i] = remainder;
			current /= 16;

		}

	}
}

void CopyArray(int* array, int* copy_array, int n)
{
	for (int i = 0; i < n; i++)
	{
		copy_array[i] = array[i];
	}
}

void Swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

void BubbleSort(int* array, int* keys, int n)
{
	bool swapped = true;
	int i = 1;
	while (swapped)
	{
		swapped = false;
		for (int j = n - 1; j >= i; j--)
		{
			if (keys[j] > keys[j - 1])
			{
				Swap(array[j], array[j - 1]);
				Swap(keys[j], keys[j - 1]);

				swapped = true;
			}
		}
		i++;
	}
}

int GettingIndexes(int* array, int* indexes, char symbol, int n)
{
	int remainder = 0, j = 0;
	for (int i = 0; i < n; i++)
	{
		int current = abs(array[i]);
		switch (symbol)
		{
		case 'A':
		case 'a':
		{
			while (current)
			{
				remainder = current % 16;
				if (remainder == 10)
				{
					indexes[j] = i;
					j++;
					break;
				}
				current /= 16;
			}
			break;
		}

		case 'B':
		case 'b':
		{
			while (current)
			{
				remainder = current % 16;
				if (remainder == 11)
				{
					indexes[j] = i;
					j++;
					break;
				}
				current /= 16;
			}
			break;
		}

		case 'C':
		case 'c':
		{
			while (current)
			{
				remainder = current % 16;
				if (remainder == 12)
				{
					indexes[j] = i;
					j++;
					break;
				}
				current /= 16;
			}
			break;
		}

		case 'D':
		case 'd':
		{
			while (current)
			{
				remainder = current % 16;
				if (remainder == 13)
				{
					indexes[j] = i;
					j++;
					break;
				}
				current /= 16;
			}
			break;
		}

		case 'E':
		case 'e':
		{
			while (current)
			{
				remainder = current % 16;
				if (remainder == 14)
				{
					indexes[j] = i;
					j++;
					break;
				}
				current /= 16;
			}
			break;
		}

		case 'F':
		case 'f':
		{
			while (current)
			{
				remainder = current % 16;
				if (remainder == 15)
				{
					indexes[j] = i;
					j++;
					break;
				}
				current /= 16;
			}
			break;
		}

		}
	}

	return j;
}

void GettingDelArray(int* array, int* new_array, int*indexes, int m, int n)
{
	for (int i = 0, k = 0, l = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (i == indexes[j])
			{
				new_array[k] = array[indexes[j]];
				k++;
			}
			else
			{
				array[l] = array[i];
				l++;
			}
		}
	}
}
