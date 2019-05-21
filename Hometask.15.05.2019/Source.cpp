#define _CRT_SECURE_NO_WARNINGS

#include <io.h>
#include <fstream>
#include <iostream>
#include "Book.h"

typedef double(*Key)(Book);

using namespace std;

void InitFile(char*);
void DisplayFile(char*);
void AddToEndFile(char*);
void ChangeFile(char*);
void RemoveFromFile(char*);
void InitNumber(long&);
void SystemFun();
void InitNameFile(char*);
void SortingFile(char*);
int Menu();
int SortingMenu();
int ChangingMenu();

int main()
{
	char fileName[N] = "List.bin";
	enum { Init = 1, Create, Display, Add, Change, Remove, Sort, Exit };
	while (true)
	{
		int key = Menu();
		if (key == Exit)
		{
			return 0;
		}
		system("cls");

		switch (key)
		{
		case Init:
			InitNameFile(fileName);
			SystemFun();
			break;
		case Create:
			InitFile(fileName);
			SystemFun();
			break;
		case Display:
			DisplayFile(fileName);
			SystemFun();
			break;
		case Add:
			AddToEndFile(fileName);
			SystemFun();
			break;
		case Change:
			ChangeFile(fileName);
			SystemFun();
			break;
		case Remove:
			RemoveFromFile(fileName);
			SystemFun();
			break;
		case Sort:
			SortingFile(fileName);
			SystemFun();
			break;
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}
	}
}

void InitFile(char* fileName)
{
	ofstream streamOut;
	streamOut.open(fileName, ios::binary);
	if (!streamOut.is_open())
	{
		cout << "\nCan't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Book);
	Book book;
	char ok = 'y';
	while (ok == 'y')
	{
		book.EnterBook();
		streamOut.write((char*)&book, bufSize);
		cout << " If do you want to continue, press 'y' :";
		cin >> ok;
	}

	streamOut.close();
}

void AddToEndFile(char* fileName)
{
	ofstream streamOut(fileName, ios::app | ios::binary);
	if (!streamOut.is_open())
	{
		cout << "Can't open file to write!";
		SystemFun();
		return;
	}
	int bufSize = sizeof(Book);
	Book book;
	char Ok = 'y';
	while (Ok == 'y')
	{
		book.EnterBook();
		streamOut.write((char*)&book, bufSize);
		cout << " If do you want to continue, press 'y' : ";
		cin >> Ok;
	}
	streamOut.close();
}

void SortingFile(char* fileName)
{
	bool flag = true;
	while (flag)
	{
		fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
		if (!streamInOut.is_open())
		{
			cout << "Can't open file to read and write!";
			SystemFun();
			return;
		}
		flag = false;
		Book firstBook, secondBook;
		int bufSize = sizeof(Book);
		streamInOut.read((char*)&firstBook, bufSize);

		enum { ReleaseYear = 1, PrimeCost, Price, Profit, Title, FirstName, LastName, PublishingHouse, Exit };
		int menu = SortingMenu();

		if (menu == Exit)
		{
			break;
		}

		switch (menu)
		{
		case ReleaseYear:
		{
			while (streamInOut.read((char*)&secondBook, bufSize))
			{
				if (secondBook.GetReleaseYear() < firstBook.GetReleaseYear())
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&secondBook, bufSize);
					streamInOut.write((char*)&firstBook, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&firstBook, bufSize);
			}

			break;
		}
		case PrimeCost:
		{
			while (streamInOut.read((char*)&secondBook, bufSize))
			{
				if ((firstBook.GetPrimeCost() - secondBook.GetPrimeCost()) > eps)
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&secondBook, bufSize);
					streamInOut.write((char*)&firstBook, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&firstBook, bufSize);
			}

			break;
		}
		case Price:
		{
			while (streamInOut.read((char*)&secondBook, bufSize))
			{
				if ((firstBook.GetPrice() - secondBook.GetPrice()) > eps)
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&secondBook, bufSize);
					streamInOut.write((char*)&firstBook, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&firstBook, bufSize);
			}

			break;
		}
		case Profit:
		{
			while (streamInOut.read((char*)&secondBook, bufSize))
			{
				if ((firstBook.GetProfit() - secondBook.GetProfit()) > eps)
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&secondBook, bufSize);
					streamInOut.write((char*)&firstBook, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&firstBook, bufSize);
			}

			break;
		}
		case Title:
		{
			while (streamInOut.read((char*)&secondBook, bufSize))
			{
				if ((firstBook.GetTitle()[0] - secondBook.GetTitle()[0]) > 0)
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&secondBook, bufSize);
					streamInOut.write((char*)&firstBook, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&firstBook, bufSize);
			}

			break;
		}
		case FirstName:
		{
			while (streamInOut.read((char*)&secondBook, bufSize))
			{
				if ((firstBook.GetFirstName()[0] - secondBook.GetFirstName()[0]) > 0)
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&secondBook, bufSize);
					streamInOut.write((char*)&firstBook, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&firstBook, bufSize);
			}

			break;
		}
		case LastName:
		{
			while (streamInOut.read((char*)&secondBook, bufSize))
			{
				if ((firstBook.GetLastName()[0] - secondBook.GetLastName()[0]) > 0)
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&secondBook, bufSize);
					streamInOut.write((char*)&firstBook, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&firstBook, bufSize);
			}

			break;
		}
		case PublishingHouse:
		{
			while (streamInOut.read((char*)&secondBook, bufSize))
			{
				if ((firstBook.GetPublisnigHouse()[0] - secondBook.GetPublisnigHouse()[0]) > 0)
				{
					streamInOut.seekp(-2 * bufSize, ios::cur);
					streamInOut.write((char*)&secondBook, bufSize);
					streamInOut.write((char*)&firstBook, bufSize);
					flag = true;
				}
				streamInOut.seekp(-bufSize, ios::cur);
				streamInOut.read((char*)&firstBook, bufSize);
			}

			break;
		}
		default:
			cout << "\nIncorrect input! Try again!";
			SystemFun();
		}

		streamInOut.close();
	}
}

void DisplayFile(char* fileName)
{
	ifstream streamIn(fileName, ios::binary);
	if (!streamIn.is_open())
	{
		cout << "Can't open file to read!";
		SystemFun();
		return;
	}

	int bufSize = sizeof(Book);
	Book* book = new Book;
	while (streamIn.read((char*)book, bufSize))
	{
		book->DisplayBook();
	}

	streamIn.close();
}

void InitNameFile(char* fileName)
{
	cout << "Enter the name of file: " << endl;
	cin.ignore();
	cin.getline(fileName, 256, '\n');
	system("cls");
}

int Menu()
{
	int k;
	cout << "\n Enter the number - the mode of operations with file:"
		"\n 1 - INITIALIZATION THE NAME OF FILE"
		"\n 2 - FORMATION OF THE FILE"
		"\n 3 - VIEWING OF CONTENTS OF THE FILE"
		"\n 4 - ADD AN ELEMENT TO AND OF FILE"
		"\n 5 - CHANGE THE ELEMENT IN THE FILE"
		"\n 6 - REMOVE THE ELEMENT IN THE FILE"
		"\n 7 - SORTING THE ELEMENT IN THE FILE"
		"\n 8 - EXIT\n";
	cin >> k;
	return k;
}

int SortingMenu()
{
	int k;
	cout << "\n Enter the number - the sorting criterion:"
		"\n 1 - RELEASE YEAR"
		"\n 2 - PRIME COST"
		"\n 3 - PRICE"
		"\n 4 - PROFIT"
		"\n 5 - TITLE"
		"\n 6 - AUTHOR NAME"
		"\n 7 - AUTHOR SURNAME"
		"\n 8 - PUBLISHING HOUSE"
		"\n 9 - EXIT" << endl;
	cin >> k;
	return k;
}

void ChangeFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut)
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}

	int bufSize = sizeof(Book);
	Book book;
	long position;
	InitNumber(position);
	streamInOut.seekp((position - 1) * bufSize, ios::beg);
	streamInOut.read((char*)&book, bufSize);

	enum { ReleaseYear = 1, PrimeCost, Price, Title, FirstName, LastName, PublishingHouse, WholeBook, Exit };
	int menu = ChangingMenu();

	if (menu == Exit)
	{
		return;
	}
	system("cls");

	const int N = 256;
	int releaseYear = book.GetReleaseYear();
	double primeCost = book.GetPrimeCost(), price = book.GetPrice();
	char* title = book.GetTitle(); char* firstName = book.GetFirstName();
	char* lastName = book.GetLastName(); char* publishingHouse = book.GetPublisnigHouse();

	switch (menu)
	{

	case ReleaseYear:
	{
		int newReleaseYear;
		cout << "Please, enter release year:";
		cin >> newReleaseYear;
		book.SetBook(title, firstName, lastName, newReleaseYear, publishingHouse, primeCost, price);

		break;
	}
	case PrimeCost:
	{
		double newPrimeCost;
		cout << "Please, enter prime cost:";
		cin >> newPrimeCost;
		book.SetBook(title, firstName, lastName, releaseYear, publishingHouse, newPrimeCost, price);

		break;
	}
	case Price:
	{
		double newPrice;
		cout << "Please, enter price:";
		cin >> newPrice;
		book.SetBook(title, firstName, lastName, releaseYear, publishingHouse, primeCost, newPrice);

		break;
	}
	case Title:
	{
		char newTitle[N] = "";
		cout << "Enter the title of the book:";
		cin.ignore();
		cin.getline(newTitle, N, '\n');
		book.SetBook(newTitle, firstName, lastName, releaseYear, publishingHouse, primeCost, price);

		break;
	}
	case FirstName:
	{
		char newFirstName[N] = "";
		cout << "Enter the first name of author:";
		cin.ignore();
		cin.getline(newFirstName, N, '\n');
		book.SetBook(title, newFirstName, lastName, releaseYear, publishingHouse, primeCost, price);

		break;
	}
	case LastName:
	{
		char newLastName[N] = "";
		cout << "Enter the last name of author:";
		cin.ignore();
		cin.getline(newLastName, N, '\n');
		book.SetBook(title, firstName, newLastName, releaseYear, publishingHouse, primeCost, price);

		break;
	}
	case PublishingHouse:
	{
		char newPublishingHouse[N] = "";;
		cout << "Enter the publishing house:";
		cin.ignore();
		cin.getline(newPublishingHouse, N, '\n');
		book.SetBook(title, firstName, lastName, releaseYear, newPublishingHouse, primeCost, price);

		break;
	}
	case WholeBook:
	{
		book.EnterBook();
		break;
	}
	default:
		cout << "\nIncorrect input! Try again!";
		SystemFun();
	}

	streamInOut.seekp((position - 1) * bufSize, ios::beg);
	streamInOut.write((char*)&book, bufSize);
	streamInOut.close();
}

void RemoveFromFile(char* fileName)
{
	fstream streamInOut(fileName, ios::in | ios::out | ios::binary);
	if (!streamInOut.is_open())
	{
		cout << "Can't open file to read and write!";
		SystemFun();
		return;
	}
	streamInOut.seekp(0, ios::end);
	long n = streamInOut.tellp();
	int bufSize = sizeof(Book);
	Book book;
	long Position;
	InitNumber(Position);
	streamInOut.seekp(Position * bufSize, ios::beg);

	while (streamInOut.read((char*)&book, bufSize))
	{

		streamInOut.seekp(-2 * bufSize, ios::cur);
		streamInOut.write((char*)&book, bufSize);
		streamInOut.seekp(bufSize, ios::cur);
	}
	streamInOut.close();
	int diskriptorFile = _open(fileName, 2);
	_chsize(diskriptorFile, n - bufSize);
	_close(diskriptorFile);
}

void SystemFun()
{
	cout << endl;
	system("pause");
	system("cls");
}

void InitNumber(long& n)
{
	cout << "Enter the number of record:" << endl;
	cin >> n;
	system("cls");
}

int ChangingMenu()
{
	int k;
	cout << "\n Enter the number - the changing criterion:"
		"\n 1 - RELEASE YEAR"
		"\n 2 - PRIME COST"
		"\n 3 - PRICE"
		"\n 4 - TITLE"
		"\n 5 - AUTHOR NAME"
		"\n 6 - AUTHOR SURNAME"
		"\n 7 - PUBLISHING HOUSE"
		"\n 8 - WHOLE BOOK"
		"\n 9 - EXIT" << endl;
	cin >> k;
	return k;
}