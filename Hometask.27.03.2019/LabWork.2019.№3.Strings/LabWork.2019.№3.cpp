#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <iostream>
#include "Strings.h"

using namespace std;

int main()
{
	char esc = 'y';
	while (esc == 'y' || esc == 'Y')
	{
		char* string = AllocateMemoryChar(N);
		cout << "Please, enter string: " << endl;
		cin.getline(string, N);

		char** words = new char*[strlen(string) / 2];
		int n = strlen(string);
		try
		{
			words = ObtainWordsAgain(string, n);
		}
		catch (const exception& ex)
		{
			cout << ex.what() << endl;
		}
		DisplayWords(words, n);

		MergeSort(words, n, GettingKeys,GettingFilter);
		DisplayWords(words, n);

		cout << "Press y ot Y to continue";
		cin >> esc;
		system("cls");
	}

	return 0;
}