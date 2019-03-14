#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include "Srings.h"

using namespace std;

int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		char* string = AllocateMemoryChar(N);
		cout << "Please, enter string: " << endl;
		cin.getline(string, 256);

		cout << "Please, enter word which want to replace: " << endl;
		char* replacingWord = ValidationOfWord();

		cout << "Please, enter word: " << endl;
		char* word = ValidationOfWord();

		ToReplaceWord(string, replacingWord, word);
		cout << "The resulting string is: " << string << endl;

		cout << "Press y ot Y to continue";
		cin >> esc;
		system("cls");
	}

	return 0;
}
