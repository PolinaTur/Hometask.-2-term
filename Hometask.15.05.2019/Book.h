#pragma once

const int N = 50;
const double eps = 0.001;

class Book
{
public:
	Book() {};
	Book(char*, char*, char*, int, char*, double, double);
	~Book() {};
	void SetTitle(char*);
	void SetFirstName(char*);
	void SetLastName(char*);
	void SetPublisnigHouse(char*);
	void SetReleaseYear(int);
	void SetPrimeCost(double);
	void SetPrice(double);
	void SetBook(char*, char*, char*, int, char*, double, double);
	char* GetTitle();
	char* GetFirstName();
	char* GetLastName();
	char* GetPublisnigHouse();
	int GetReleaseYear();
	double GetPrimeCost();
	double GetPrice();
	double GetProfit();
	void DisplayBook();
	void EnterBook();

private:
	char firstName[N]{}, lastName[N]{}, title[N]{};
	int releaseYear{};
	char publishingHouse[N]{};
	double primeCost{}, price{}, profit{};
	void SetProfit();
};


