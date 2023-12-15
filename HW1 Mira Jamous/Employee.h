#pragma once
#include "Date.h"
class Employee :public Date {
private:
	char FirstName[20], LastName[20];
	int salary;
public:
	Date Birthdate, HireDate;
	Employee();
	void setFirstName(char* FN);
	void setLastName(char* LN);
	char* getFirstName();
	char* getLastName();
	int getSalary();
	void setSalary(int s);
	Employee(char* FN, char* LN, Date HD, Date BD);
	void setEmployee(char* FN, char* LN, int s, Date BD, Date HD);
	friend ostream& operator<<(ostream& os, Employee& e);
	~Employee();
};