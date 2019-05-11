#include<iostream>
#include<fstream>

typedef double(*Function)(double, double);

using namespace std;

void CreateFile(const char*, int);
void AddFile(const char*,double);
double** AllocateMemory(int);
double FindMaximum(double, double);
double FindMaximum(double*, int);
double FindMaximum(double**, int);
double ConverToRadians(double);
void GettingMatrix(double**, int, double, Function);
void GettingDifference(double**, double**, int);
double TaylorRowSinus(double, double);
double GettingAccurancy();

int main()
{
	const char* fileName = "C:\\Users\\Polina\\Desktop\\проекты\\2 семестр\\17.04.2019\\№2\\test2.txt";
	int n;
	cout << "Enter dimension:" << endl;
	cin >> n;
	CreateFile(fileName, n);

	double** matrix = AllocateMemory(n);
	double** matrixDifference = AllocateMemory(n);

	double accurancy = GettingAccurancy();

	GettingMatrix(matrix, n, accurancy, TaylorRowSinus);
	GettingDifference(matrixDifference, matrix, n);
	AddFile(fileName, FindMaximum(matrixDifference, n));
	
	return 0;
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

	streamOut.close();
}

void AddFile(const char* fileName,double n)
{
	ofstream streamOut(fileName, ios::app);

	if (!streamOut.is_open())
	{
		cout << "\nCannot open file to addition!\n";
		system("pause");
		exit(1);
	}

	streamOut << "\The maximum difference is \n";
	streamOut << n << endl;
	
	streamOut.close();
}

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

double FindMaximum(double x, double y)
{
	return (x > y) ? x : y;
}

double FindMaximum(double* array, int n)
{
	int i = 0;
	double maximum = array[i];

	while (i < n)
	{
		maximum = FindMaximum(maximum, array[i]);
		i++;
	}

	return maximum;
}

double FindMaximum(double** matrix, int n)
{
	int i = 0;
	double maximum = FindMaximum(matrix[i], n);

	while (i < n)
	{
		maximum = FindMaximum(maximum, FindMaximum(matrix[i], n));
		i++;
	}

	return maximum;
}

double ConverToRadians(double x)
{
	return x = fmod(x, 2 * 3.14);
}

void GettingMatrix(double** matrix, int n, double accurancy, Function function)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				matrix[i][j] = 1;
			}
			else
			{
				matrix[i][j] = (function(ConverToRadians(i + j), accurancy) - function(ConverToRadians(i - j), accurancy));
			}

		}
	}
}

void GettingDifference(double** matrixDifference, double** matrix, int n)
{
	for (int i = 0; i < n; i++)
	{

		for (int j = 0; j < n; j++)
		{
			if (i != j)
			{
				matrixDifference[i][j] = fabs(matrix[i][j] / pow((i + j + 1), 2) - (sin(ConverToRadians(i + j)) - sin(ConverToRadians(i - j))) / pow((i + j + 1), 2));
			}
			else
			{
				matrixDifference[i][j] = fabs(matrix[i][j] - 1);
			}

		}
	}
}

double TaylorRowSinus(double x, double accurancy)
{
	double term = x;
	double sinus = 0.0;
	int i = 1;

	while (fabs(term) > accurancy)
	{
		sinus += term;
		term *= -1.0 * x * x / ((2 * i) * (2 * i + 1));
		i++;
	}

	return sinus;
}

double GettingAccurancy()
{
	double n;
	while (true)
	{
		cout << "Enter accurancy:";
		cin >> n;

		if (n > 0 && n < 1)
		{
			return n;
		}

		cout << "Invalid data! Try again :)" << endl;
	}
}

