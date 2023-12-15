#include <iostream>
using namespace std;
#include "Date.h"
Date::Date() {
	day = 1;
	month = 1;
	year = 1990;
}

Date::Date(int a, int b, int c)
{    day = a;
     month=b;
	 year = c;
	if (this->validdate()==0)
	{
		cout << "invalid date\n";
		setdate(1, 1, 1990);
	}

}

void Date::setdate(int a, int b, int c)
{
	Date d(a, b, c);
	if (d.validdate() == 1)
	{
		this->day = a;
		this->month=b;
		this->year=c;
	}
	else cout << "invalid date\n";

}


void Date::print()
{
	cout << day << "/" << month << "/" << year << endl;
}

int Date::getday()
{
	return day;
}
int Date::getmonth()
{
	return month;
}
int Date::getyear()
{
	return year;
}

int Date::leapyear(int y)
{

	if ((y % 4) == 0)
	{
		if ((y % 100) != 0)
			return 1;
		else {
			if ((y % 400) == 0)
				return 1;
			else return 0;
		}

	}
	else return 0;

}

int Date::validdate()
{
	if (month > 12)
		return 0;
	else
	{
		switch (month)
		{
		case 1: {if ((day <= 31) && (day >= 1))
			return 1;
			  else
			return 0;
		}
		case 2: {if ((leapyear(year) == 1) && (day > 29))
			return 0;
			  else if ((leapyear(year) == 1) && ((1 <= day) && (day <= 29)))
			return 1;
			  else if ((leapyear(year) == 0) && (day > 28))
			return 0;
			  else if ((leapyear(year) == 0) && ((1 <= day) && (day <= 28)))
			return 1;
		}
		case 3: {if ((1 <= day) && (day <= 31))
			return 1;
			  else
			return 0;
		}
		case 4: {if ((1 <= day) && (day <= 30))
			return 1;
			  else
			return 0;
		}
		case 5: {if ((1 <= day) && (day <= 31))
			return 1;
			  else
			return 0;
		}
		case 6: {if ((1 <= day) && (day <= 30))
			return 1;
			  else
			return 0;
		}
		case 7: {if ((1 <= day) && (day <= 31))
			return 1;
			  else
			return 0;
		}
		case 8: {if ((1 <= day) && (day <= 31))
			return 1;
			  else
			return 0;
		}
		case 9: {if ((1 <= day) && (day <= 30))
			return 1;
			  else
			return 0;
		}
		case 10: {if ((1 <= day) && (day <= 31))
			return 1;
			   else
			return 0;
		}
		case 11: {if ((1 <= day) && (day <= 30))
			return 1;
			   else
			return 0;
		}
		case 12: {if ((1 <= day) && (day <= 31))
			return 1;
			   else
			return 0;
		}
		default:return 0;
		}
	}
}



Date Date::operator+(int z)
{
	if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
	{
		if ((day <= 30) && (day >= 1))
			day++;
		else if (day == 31)
		{
			day = 1;
			if (month != 12)
				month++;
			else {
				month = 1; year++;
			}
		}
	}
	else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
	{
		if ((day <= 29) && (day >= 1))
			day++;
		else if (day == 30)
		{
			day = 1;
			month++;
		}
	}
	else if (month == 2)
	{
		if (leapyear(year) == 1)
		{
			if ((day <= 28) && (day >= 1))
				day++;
			else if (day == 29)
			{
				day = 1;
				month++;
			}
		}
		else {
			if ((day <= 27) && (day >= 1))
				day++;
			else if (day == 28)
			{
				day = 1;
				month++;
			}
		}
	}
	Date m(day, month, year);

	return m;
}

ostream& operator <<(ostream& os, Date& d)
{
	os << d.day << '/' << d.month << '/' << d.year << endl;
	return os;
}
Date::~Date()
{

}