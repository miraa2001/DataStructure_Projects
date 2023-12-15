#include <iostream>
#include "Date.h"
#include "Employee.h"
#include <fstream>
void menu();
void menu2();
void menu3();
int* seperateDate(char date[]);
void createNewEmployee(Employee* arr, int noe);
Employee* FilterFirstName(Employee* e, int noe);
Employee* FilterLastName(Employee* e, int noe);
Employee* FilterSalary(Employee* e, int noe, int choice);
using namespace std;
int main()
{
	int numofemployees = 0, sal = 0, choice = 0, flag = 0;
	char cfn[20], cln[20], cbd[20], chd[20];
	Date bd, hd;
	ifstream f("employeesinfo.txt", ios::out);
	f >> numofemployees;
	Employee* e;
	e = new Employee[50];
	while (1)
	{
		menu();
		cin >> choice;
		if (choice == 5)
			exit(1);
		else if ((choice != 1) && (flag == 0))

		{
			cout << "Please read file first\n";
			continue;
		}
		else
		{
			if (flag == 0)
				flag = 1;
			switch (choice)
			{
			case 1: {
				ifstream f("employeesinfo.txt", ios::out);
				if (f.is_open() == NULL)
				{
					cout << "Could not open file\n\n";
					flag = 0;
				}
				else {
					f >> numofemployees;
					for (int m = 0; m < numofemployees; m++)
					{
						f >> cfn >> cln >> sal >> cbd >> chd;
						bd.setdate(seperateDate(cbd)[0], seperateDate(cbd)[1], seperateDate(cbd)[2]);
						hd.setdate(seperateDate(chd)[0], seperateDate(chd)[1], seperateDate(chd)[2]);
						e[m].setEmployee(cfn, cln, sal, bd, hd);
					}
				}
				break;
			}
			case 2: { if (numofemployees == 0)
				cout << "List of employees is empty\n";
				  else
			{
				cout << "Number of employees are: " << numofemployees << endl;
				for (int i = 0; i < numofemployees; i++)
					cout << e[i];
			}
				  break;
			}
			case 3: {
				int choice2, choice3;
				if (numofemployees == 0)
					cout << "There are no employees to filter\n\n";
				else {
					menu2();
					cin >> choice2;
					if (choice2 == 1)
						FilterFirstName(e, numofemployees);
					else if (choice2 == 2)
						FilterLastName(e, numofemployees);
					else if (choice2 == 3)
					{
						menu3();
						cin >> choice3;
						FilterSalary(e, numofemployees, choice3);
					}
					else break;
				}
				break;
			}
			case 4: { if (numofemployees >= 50)
				cout << "Employees list is full\n\n";
				  else
			{
				cout << "Please enter First name,Last name,salary,birthdate,hiredate respectively\n";
				cin >> cfn >> cln >> sal >> cbd >> chd;
				bd.setdate(seperateDate(cbd)[0], seperateDate(cbd)[1], seperateDate(cbd)[2]);
				hd.setdate(seperateDate(chd)[0], seperateDate(chd)[1], seperateDate(chd)[2]);
				e[numofemployees].setEmployee(cfn, cln, sal, bd, hd);
				numofemployees++;
				createNewEmployee(e, numofemployees);

			}
				  break;
			}
			case 5: { delete[]e;
				exit(1);
			}
			default:break;
			}
		}
	}
	return 0;
}
void menu()
{
	cout << "Please enter a number between 1 and 4\n\n";
	cout << "1.Read information of employees from a file\n";
	cout << "2.Print all Employees\n";
	cout << "3.Filter employees\n";
	cout << "4.Add a new employee\n";
	cout << "5.Exit\n\n";
}
void menu2() {
	cout << "Please enter a number between 1 and 3\n\n";
	cout << "1.Filter First Name\n";
	cout << "2.Filter Last Name\n";
	cout << "3.Filter Salary\n\n";
}
void menu3() {
	cout << "Please enter a number between 1 and 3\n\n";
	cout << "1.Salary is equal to the one chosen as a filter\n";
	cout << "2.Salary is bigger than the one chosen as a filter\n";
	cout << "3.Salary is smaller than the one chosen as a filter\n\n";


}
int* seperateDate(char date[]) {
	int* d;
	d = new int[3];
	int day = 1, month = 1, year = 1, y = 0;
	int count, count1, count2;
	count = count1 = count2 = 0;
	for (int i = 0, j = 0; j < strlen(date); j++)
	{

		if (date[j] != '/')
		{
			if (i == 0)
			{
				if (count == 0)
					day = (int)date[j] - 48;
				else
					day = day * 10 + ((int)date[j] - 48);
				count++;
			}
			if (i == 1)
			{
				if (count1 == 0)
					month = (int)date[j] - 48;
				else
					month = month * 10 + ((int)date[j] - 48);
				count1++;
			}
			if (i == 2)
			{
				if (count2 == 0)
					year = (int)date[j] - 48;
				else
					year = year * 10 + ((int)date[j] - 48);
				count2++;
			}
		}
		else i++;
	}
	d[0] = day;
	d[1] = month;
	d[2] = year;
	return d;

}
void createNewEmployee(Employee* arr, int noe) {
	ofstream x("employeesinfo.txt", ios::out);
	x << noe << endl;;
	for (int i = 0; i < noe; i++)
	{
		x << arr[i].getFirstName() << " ";
		x << arr[i].getLastName() << " ";
		x << arr[i].getSalary() << " ";
		x << arr[i].Birthdate << " ";
		x << arr[i].HireDate << " ";
		x << endl;
	}
	x.close();
}
Employee* FilterFirstName(Employee* e, int noe)
{
	char fn[20], fn2[20];
	int count = 0, count1 = 0;
	if (noe == 0)
		cout << "There are no employees to filter\n";
	else {
		cout << "Please enter the first name you'd like as a filter\n";
		cin >> fn;
		for (int i = 0; i < noe; i++)
		{
			strcpy(fn2, e[i].getFirstName());
			if (strlen(fn) == strlen(fn2))
			{
				for (int m = 0; m < strlen(fn); m++)
				{
					if (fn[m] == fn2[m])
						count++;
				}
				if (count == strlen(fn2))
					count1++;
				count = 0;
			}
		}
		count = 0;

		Employee* newEmp;
		newEmp = new Employee[count1];
		int k = 0;
		for (int i = 0; i < noe; i++)
		{
			strcpy(fn2, e[i].getFirstName());
			if (strlen(fn) == strlen(fn2))
			{
				for (int m = 0; m < strlen(fn); m++)
				{
					if (fn[m] == fn2[m])
						count++;
				}
				if (count == strlen(fn2))
				{
					newEmp[k] = e[i];
					k++;
					cout << newEmp[k - 1] << endl;;
				}
				count = 0;
			}
		}
		return newEmp;
	}



}
Employee* FilterLastName(Employee* e, int noe) {
	char ln[20], ln2[20];
	int count = 0, count1 = 0;
	if (noe == 0)
		cout << "There are no employees to filter\n";
	else {
		cout << "Please enter the last name you'd like as a filter\n";
		cin >> ln;
		for (int i = 0; i < noe; i++)
		{
			strcpy(ln2, e[i].getFirstName());
			if (strlen(ln) == strlen(ln2))
			{
				for (int m = 0; m < strlen(ln); m++)
				{
					if (ln[m] == ln2[m])
						count++;
				}
				if (count == strlen(ln2))
					count1++;
				count = 0;
			}
		}
		count = 0;

		Employee* newEmp;
		newEmp = new Employee[count1];
		int k = 0;
		for (int i = 0; i < noe; i++)
		{
			strcpy(ln2, e[i].getLastName());
			if (strlen(ln) == strlen(ln2))
			{
				for (int m = 0; m < strlen(ln); m++)
				{
					if (ln[m] == ln2[m])
						count++;
				}
				if (count == strlen(ln2))
				{
					newEmp[k] = e[i];
					k++;
					cout << newEmp[k - 1] << endl;;
				}
				count = 0;
			}
		}
		return newEmp;
	}



}
Employee* FilterSalary(Employee* e, int noe, int choice)
{
	switch (choice)
	{
	case 1: {     int s, count = 0, k = 0;
		cout << "Please enter the salary you'd like as a filter\n";
		cin >> s;
		for (int i = 0; i < noe; i++)
		{
			if (e[i].getSalary() == s)
				count++;
		}
		Employee* newEmp;
		newEmp = new Employee[count];
		for (int i = 0; i < noe; i++)
		{
			if (e[i].getSalary() == s)
			{
				newEmp[k] = e[i];
				cout << newEmp[k];
				k++;
			}
		}
		return newEmp;
		break;
	}
	case 2: {      int s, count = 0, k = 0;
		cout << "Please enter the salary you'd like as a filter\n";
		cin >> s;
		for (int i = 0; i < noe; i++)
		{
			if (e[i].getSalary() > s)
				count++;
		}
		Employee* newEmp;
		newEmp = new Employee[count];
		for (int i = 0; i < noe; i++)
		{
			if (e[i].getSalary() > s)
			{
				newEmp[k] = e[i];
				cout << newEmp[k];
				k++;
			}
		}
		return newEmp;
		break;
	}

	case 3: {     int s, count = 0, k = 0;
		cout << "Please enter the salary you'd like as a filter\n";
		cin >> s;
		for (int i = 0; i < noe; i++)
		{
			if (e[i].getSalary() < s)
				count++;
		}
		Employee* newEmp;
		newEmp = new Employee[count];
		for (int i = 0; i < noe; i++)
		{
			if (e[i].getSalary() < s)
			{
				newEmp[k] = e[i];
				cout << newEmp[k];
				k++;
			}
		}
		return newEmp;
		break;
	}
	}
}


