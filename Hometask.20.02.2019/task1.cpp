#include <iostream>

using namespace std;

int ValidationOfElement();
double* AllocateMemory(int);
void DisplayArray(double*, int);
void DisplayArrayInt(int*, int);
void InPutArray(double*, int);
void AmountOfOnes(int*, int*, int);
void AmountOfZeroes(int*, int*, int);
void ConvertToInt(double*,int*, int);
void BubbleSort(double*, int*, int);
void Swap(double&, double&);
void Swap(int& x, int& y);
int* AllocateMemoryInt(int);
int InPutElement();
int AmountOfDelElements(int*, int*,int*, int, int,int);
void CreateNewArray(double*, double*, int*, int);
void DeleteElements(double*,int*, int, int);

int main()
{
	int n = ValidationOfElement();
	double* array = AllocateMemory(n);

	InPutArray(array, n);
	system("cls");
	
	cout << "The sorted array are:";
	DisplayArray(array, n);

   int* arr = AllocateMemoryInt(n);
   ConvertToInt(array, arr, n);

   int* ones = AllocateMemoryInt(n);
   AmountOfOnes(arr, ones, n);
   
   BubbleSort(array, ones, n);

   int* zeroes = AllocateMemoryInt(n);
   AmountOfZeroes(ones, zeroes, n);

   int a = InPutElement();
   int b = InPutElement();

  int* indexes = AllocateMemoryInt(n);
  int k = AmountOfDelElements(ones, zeroes, indexes, a, b, n);

  double* new_array = AllocateMemory(k);
  CreateNewArray(array, new_array, indexes, k);
  cout << "The array with numbers which contains a ones and b zeroes: ";
  DisplayArray(new_array, k);

  DeleteElements(array, indexes, k, n);
  cout << "The array without numbers which contains a ones and b zeroes: ";
  DisplayArray(array, n - k);

  system("pause");
   return 0;
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

double* AllocateMemory(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}

	double* array = new double[n]; 

	return array;
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

void InPutArray(double* array, int n)
{
	for (double* p = array, i = 1; p < array + n; p++, i++)
	{
		cout << "a[" << i << "]= ";
		cin >> *p;
	}
}

void DisplayArray(double* array, int n)
{
	for (double* p = array; p < array + n; p++)
	{
		cout << *p << " ";
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

void AmountOfOnes(int* array,int* keys, int n)
{

	for (int i = 0; i < n; i++)
	{
		int k = 0;
		for (int j = 0; j < 32; j++)
		{
			if (array[i] & 1)
			{
				k++;
			}
			array[i] >>= 1;
		}
		keys[i] = k;
	}
}

void AmountOfZeroes(int* array, int* keys, int n)
{
	for (int i = 0; i < n; i++)
	{
		keys[i] = 32 - array[i];
	}
}

void ConvertToInt(double* array, int* arr,int n )
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int)array[i];
	}
}

void BubbleSort(double* array, int* keys, int n)
{
	bool swapped = true;
	int i = 1;
	while (swapped)
	{
		swapped = false;
		for (int j = n - 1; j >= i; j--)
		{
				if (keys[j] < keys[j - 1])
				{
					Swap(array[j], array[j - 1]);
					Swap(keys[j], keys[j - 1]);

					swapped = true;
				}
		}
		i++;
	}
			
}

void Swap(double& x, double& y)
{
	double t = x;
	x = y;
	y = t;
}

void Swap(int& x, int& y)
{
	int t = x;
	x = y;
	y = t;
}

int InPutElement()
{
	int element;
	cout << "\nPlease enter number  of elements which contains in  number: ";
	cin >> element;
	return element;
}

int AmountOfDelElements(int* ones, int* zeroes,int* indexes, int a, int b, int n)
{
	int i = 0, j = 0;
	while (i < n)
	{
		if (ones[i] == a && zeroes[i] == b)
		{
			indexes[j] = i;
			j++;
		}
		else
		{
			n--;
		}
		i++;
	}
	return j;
}

void CreateNewArray(double* array, double* new_array, int* indexes, int k)
{
	for (int i = 0; i < k; i++)
	{
		int j = indexes[i];
		new_array[i] = array[j];
	}
}

void DeleteElements(double* array,int* indexes, int k, int n)
{
	for (int i = 0, j = 0; i < n; i++)
	{
		if (i != indexes[i])
		{

			array[j] = array[i];
			j++;
		}
	}
}
