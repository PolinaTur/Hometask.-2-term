#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Strings.h"

using namespace std;

int ValidationOfElement(int n)
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

char* ValidationOfArray(char* array, int n)
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

char** ValidationOfMatrix(char** matrix, int n)
{
	if (matrix == nullptr)
	{
		throw invalid_argument("The pointer to array can't be equal to nullptr");
	}

	for (int i = 0; i < n; i++)
	{
		try
		{
			matrix[i] = ValidationOfArray(matrix[i],n);
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
	}

	return matrix;
}

char* AllocateMemoryChar(int n)
{
	char* array = new char[n];

	try
	{
		array = ValidationOfArray(array, n);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}

	return array;
}

char** ObtainWordsAgain(char* source, int& n)
{
	const char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	char** words = new char*[strlen(source) / 2];

	n = 0;
	char* pword = strpbrk(source, symbols);
	while (pword)
	{
		int length = strspn(pword, symbols);
		words[n] = new char[length + 1];
		strncpy(words[n], pword, length);
		words[n][length] = '\0';
		pword += length;
		pword = strpbrk(pword, symbols);
		n++;
	}

	if (n == 0)
	{
		throw invalid_argument("There are no words in given string");
	}

	return words;
}

void DisplayWords(char** words , int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << words[i] << " ";
	}

	cout << endl;
}

int GettingKeys(char* word)
{
	const char* symbols = "AEIOUYaeiouy";

	int k = 0;

	for (int i = 0; i < strlen(word); i++)
	{
		for (int j = 0; j < strlen(symbols); j++)
		{
			if (word[i] == symbols[j])
			{
				k++;
			}
		}
	}

	return k;
}

bool GettingFilter(char* word)
{
	return strlen(word) % 2;
}

void MergeSort(char** array, int n,Key key,Filter filter)
{
	MergeSort(array, 0, n - 1,key,filter);
}

void MergeSort(char** array, int startIndex, int endIndex,Key key,Filter filter)
{
	if (filter(array[startIndex]))
	{
		if (startIndex < endIndex)
		{
			int middleIndex = (startIndex + endIndex) / 2;
			MergeSort(array, startIndex, middleIndex, key,filter);
			MergeSort(array, middleIndex + 1, endIndex, key,filter);
			Merge(array, startIndex, middleIndex, endIndex, key);
		}
	}
}

void Merge(char** array, int startIndex, int middleIndex, int endIndex,Key key)
{
	const int totalElements = endIndex - startIndex + 1;

	char** tempArray = new char*[totalElements];
	int leftIndex = startIndex;
	int rightIndex = middleIndex + 1;
	int mergedIndex = 0;
	while (leftIndex <= middleIndex && rightIndex <= endIndex)
	{
		if (key(array[leftIndex]) <= key(array[rightIndex]))
		{
			tempArray[mergedIndex] = array[leftIndex];
			++leftIndex;
		}
		else
		{
			tempArray[mergedIndex] = array[rightIndex];
			++rightIndex;
		}
		++mergedIndex;
	}

	while (leftIndex <= middleIndex)
	{
		tempArray[mergedIndex] = array[leftIndex];
		++leftIndex;
		++mergedIndex;
	}

	while (rightIndex <= endIndex)
	{
		tempArray[mergedIndex] = array[rightIndex];
		++rightIndex;
		++mergedIndex;
	}

	for (int i = 0; i < totalElements; ++i)
	{
		array[startIndex + i] = tempArray[i];
	}
	delete[] tempArray;
}
