#include "Employee.h"
Employee::Employee()
{
	strcpy(FirstName, "unknown");
	strcpy(LastName, "unknown");
	salary = 0;
	Birthdate.setdate(1, 1, 1990);
	HireDate.setdate(1, 1, 1990);

}
void Employee::setFirstName(char* FN)
{
	strcpy(FirstName, FN);
}
void Employee::setLastName(char* LN)
{
	strcpy(LastName, LN);
}
char* Employee::getFirstName()
{
	return FirstName;
}
char* Employee::getLastName()
{
	return LastName;
}
int Employee::getSalary()
{
	return salary;
}
void Employee::setSalary(int s)
{
	salary = s;
}
Employee::Employee(char* FN, char* LN, Date HD, Date BD)
{
	strcpy(FirstName, FN);
	strcpy(LastName, LN);
	HireDate = HD;
	Birthdate = BD;
	salary = 0;
}
void Employee::setEmployee(char* FN, char* LN, int s, Date BD, Date HD)
{
	strcpy(FirstName, FN);
	strcpy(LastName, LN);
	salary = s;
	HireDate = HD;
	Birthdate = BD;

}

ostream& operator<<(ostream& os, Employee& e)
{
	os << e.FirstName << " " << e.LastName << " " << e.salary << " " << e.Birthdate << " " << e.HireDate << endl;
	return os;
}
Employee::~Employee()
{
}