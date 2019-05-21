#define _CRT_SECURE_NO_WARNINGS

#include "Book.h"
#include <fstream>
#include <iostream>

using namespace std;

Book::Book(char* title, char* firstName, char* lastName, int releaseYear, char* publishingHouse, double primeCost, double price)
{
	this->SetBook(title, firstName, lastName, releaseYear, publishingHouse, primeCost, price);
}

void Book::SetTitle(char* title)
{
	strcpy(this->title, title);
}

void Book::SetFirstName(char* firstName)
{
	strcpy(this->firstName, firstName);
}

void Book::SetLastName(char* lastName)
{
	strcpy(this->lastName, lastName);
}

void Book::SetPublisnigHouse(char* publishingHouse)
{
	strcpy(this->publishingHouse, publishingHouse);
}

void Book::SetReleaseYear(int releaseYear)
{
	if (releaseYear >= 0 && releaseYear <= 2019)
	{
		this->releaseYear = releaseYear;
	}
	else
	{
		this->releaseYear = 0;
	}	
}

void Book::SetPrimeCost(double primeCost)
{
	if (primeCost > 0)
	{
		this->primeCost = primeCost;
	}
	else
	{
		this->primeCost = 0;
	}	
}

void Book::SetPrice(double price)
{
	if (price > 0)
	{
		this->price = price;
	}
	else
	{
		this->price = 0;
	}
}

void Book::SetBook(char* title, char* firstName, char* lastName, int releaseYear, char* publishingHouse, double primeCost, double price)
{
	this->SetTitle(title);
	this->SetFirstName(firstName);
	this->SetLastName(lastName);
	this->SetPublisnigHouse(publishingHouse);
	this->SetReleaseYear(releaseYear);
	this->SetPrimeCost(primeCost);
	this->SetPrice(price);
	this->SetProfit();
}

char * Book::GetTitle()
{
	return this->title;
}

char * Book::GetFirstName()
{
	return this->firstName;
}

char * Book::GetLastName()
{
	return this->lastName;
}

char * Book::GetPublisnigHouse()
{
	return this->publishingHouse;
}

int Book::GetReleaseYear()
{
	return this->releaseYear;
}

double Book::GetPrimeCost()
{
	return this->primeCost;
}

double Book::GetPrice()
{
	return this->price;
}

double Book::GetProfit()
{
	return this->profit;
}

void Book::DisplayBook()
{
	cout << "Book:";
	cout <<" " <<this->title << ","<< this->firstName << " " << this->lastName << endl;
	cout << " " << this->releaseYear << ","<< this->publishingHouse << "." << endl;
	cout << " " << "prime cost:" << this->primeCost << endl;
	cout << " " << "price:" << this->price << endl;
	cout << " " << "profit:" << this->profit << endl;
}

void Book::EnterBook()
{
	const int N = 256;
	char title[N] = "", firstName[N] = "", lastName[N] = "", publishingHouse[N] = "";
	cout << "Enter the title of the book:";
	cin.ignore();
	cin.getline(title, N, '\n');
	cout << "Enter the first name of author:";
	cin.getline(firstName, N, '\n');
	cout << "Enter the last name of author:";
	cin.getline(lastName, N, '\n');
	cout << "Enter the publishing house:";
	cin.getline(publishingHouse, N, '\n');
	int releaseYear;
	cout << "Enter the release year:" << endl;
	cin >> releaseYear;
	double primeCost, price;
	cout << "Enter the prime cost:" << endl;
	cin >> primeCost;
	cout << "Enter the price:" << endl;
	cin >> price;
	system("cls");
	this->SetBook(title,firstName, lastName,releaseYear,publishingHouse,primeCost,price);
}

void Book::SetProfit()
{
	if ((this->price - this->primeCost) > eps)
	{
		this->profit = this->price - this->primeCost;
	}
	else
	{
		this->profit = 0;
	}
}