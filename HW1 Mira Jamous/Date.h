#pragma once
#include <iostream>
using namespace std;
class Date {
private:
	int day, month, year;
public:
	Date();
	Date(int a, int b, int c);
	void setdate(int a, int b, int c);
	void print();
	int getday();
	int getmonth();
	int getyear();
	int leapyear(int y);
	int validdate();
	friend ostream& operator<<(ostream& os, Date& dt);
	Date operator +(int z);
	~Date();
};
