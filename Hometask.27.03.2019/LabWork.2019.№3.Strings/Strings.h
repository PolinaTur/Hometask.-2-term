#pragma once
#include <iostream>

const int N = 256;
typedef int(*Key)(char*);
typedef bool(*Filter)(char*);
typedef void(*Sort)(char**,int, int,Key);

using namespace std;

int ValidationOfElement(int n);

char* ValidationOfArray(char* array, int n);

char** ValidationOfMatrix(char** matrix, int n);

char* AllocateMemoryChar(int);

char** ObtainWordsAgain(char*, int&);

void DisplayWords(char**, int);

int GettingKeys(char*);

bool GettingFilter(char*);

void MergeSort(char**, int, Key,Filter);

void MergeSort(char**, int, int, Key,Filter);

void Merge(char**, int, int, int, Key);




