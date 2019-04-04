//англоязычная строка закодировать все слова заданной длины по правилу буква соотвествует цифре в перевернутом английском алфавите 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

typedef bool(*PredicateWord)(char);
typedef bool(*Predicate)(int,int);
typedef char*(*Key)(int);
typedef char*(*Rule)(char*,Key);

const int N = 256;

int ValidationOfElement(int n);
char* ValidationOfArray(char* array, int n);
char* AllocateMemoryChar(int n);
char* ToEncode(char*,PredicateWord,Predicate, Rule,int,Key);
bool IsWord(char);
bool IsLength(int,int);
char* GetRule(char*,Key);
char RegisterIndependent(char);
void ToReplaceWord(char* string, char* replacingWord, char* word);
char* ConvertToChar(int);

using namespace std;

int main()
{
	char* string = AllocateMemoryChar(N);
	cout << "Please, enter string: " << endl;
	cin.getline(string, N);

	int n;
	cout << "Please enter of what length word you want to encode:" << endl;
	cin >> n;

	try
	{
		n = ValidationOfElement(n);
	}
	catch (const exception& ex)
	{
		cout << ex.what() << endl;
	}
	
	cout << "The encodinig string is" << endl;
   ToEncode(string, IsWord, IsLength, GetRule, n, ConvertToChar);
   cout << string;
	
	system("pause");
	return 0;
}

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

char* ToEncode(char* string,PredicateWord word,Predicate length,Rule rule,int n,Key key)
{

	for (int i = 0, j = 0; i < strlen(string); i++)
	{
		if (word(string[i]))
		{
			j++;
			if (length(j,n))
			{
				ToReplaceWord(string,string+(i-n),rule(string + (i - n),key));
			}
			
			j = 0;
		}
	}

	return string;
}

bool IsWord(char symbol)
{
	const char* symbols = "ABCDEFGHIJKLMNOPQRSTUWVXYZabcdefghijklnmopqrstuwvxyz";
	bool result = true;
	
	while (result)
	{
		result = false;

		for (int i = 0; i < strlen(symbols); i++)
		{
			if (symbol == symbols[i])
			{
				result = true;
				return result;
			}
		}
	}
	
	return result;		
}

bool IsLength(int number,int length)
{
	return number == length;
}

char* GetRule(char* word,Key key)
{
	const char* symbols = "zyxvwutsrqpomnlkjihgfedcba";
	char* encodinigWords = new char[strlen(word)];

	for (int i = 0,j = 0; i < strlen(symbols); i++)
	{
		if (word[j] == symbols[i])
		{
			encodinigWords[j] = *(key(i));
			j++;
		}
	}

	return encodinigWords;
		
}

char RegisterIndependent(char symbol)
{
	return symbol < 'a' ? symbol + 32 : symbol;
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

char* ConvertToChar(int number)
{
	char* code = new char[3];
	int i = 0;

	while (number)
	{
		code[i] = number % 10 + '0';
		i++;
		number /= 10;
	}

	return code;
}

// правило: кодирует гласные буквы
 
//char* GetRule(char* word, Key key)
//{
//	const char* symbols = "aeiouy"; 
//	char* encodinigWords = new char[strlen(word)];
//
//	for (int i = 0, j = 0; i < strlen(symbols); i++)
//	{
//		if (word[j] == symbols[i])
//		{
//			encodinigWords[j] = *(key(i));
//			j++;
//		}
//	}
//
//	return encodinigWords;
//
//}