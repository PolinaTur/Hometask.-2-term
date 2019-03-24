#pragma once
#include <iostream>

typedef int(*Key)(int);
typedef bool(*Predicate)(int, int);
typedef bool(*Condition)(char, int);
typedef void(*Sort)(int*, int, Key);

using namespace std;

int InPutDimention();

#pragma region Validation
int ValidationOfElement(int);

int* ValidationOfArray(int*, int);

int** ValidationOfMatrix(int**, int*, int);
#pragma endregion

#pragma region Allocate
int* AllocateMemoryInt(int);

int** AllocateMemory(int, int*);
#pragma endregion

#pragma region Random
void RandomArray(int*, int, int);

void RandomMatrix(int**, int, int*);
#pragma endregion

void DisplayMatrix(int**, int, int*);

#pragma region Delete
void DeleteElements(int*, int&, Predicate);

void DeleteElements(int*, int&, int);
#pragma endregion

bool IsEqual(int, int);

void Swap(int&, int&);

int GettingKeys(int);

#pragma region QuickSort
void QuickSort(int*, int, Key);

void QuickSort(int*, int, int, Key);

int Partition(int*, int, int, Key);
#pragma endregion

void GetSorted(int**, int, int*, Sort, Key);