#pragma once
#include <iostream>

const int N = 256; 

using namespace std;

char* AllocateMemoryChar(int);
char* ValidationOfWord();
void ToReplaceWord(char*, char*, char*);

char* AllocateMemoryChar(int n)
{
	if (n <= 0)
	{
		return nullptr;
	}

	char* array = new char[n];

	return array;
}

char* ValidationOfWord()
{
	const char* symbols = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	while (true)
	{
		char* word = AllocateMemoryChar(N);
		cin.getline(word, 256);
		int length = strspn(word, symbols);

		if (length == strlen(word))
		{
			return word;
		}

		cout << "The word you enter isn't consist of symbols of alhabet. Please, try again:)" << endl;
	}
}

void ToReplaceWord(char* string, char* replacingWord, char* word)
{
	char* copyString = AllocateMemoryChar(N);
	char* ptrReplacingWord = AllocateMemoryChar(N);

	ptrReplacingWord = strstr(string, replacingWord);

	strcpy(copyString, ptrReplacingWord + strlen(replacingWord));
	strcpy(ptrReplacingWord, word);
	strcpy(strstr(string, word) + strlen(word), copyString);
}