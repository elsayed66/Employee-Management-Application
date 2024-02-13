// OOP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>
using namespace std;


#include"EmployeeManagment.h"

EmployeeManagment program;


// function prototypes
void intro();
void MainScreen();
void outro();
void departmentsMenu();
void staffMenu();
void projectsMenu();

int main()
{
    intro();
    MainScreen();
	outro();
	return 0;
}

void intro()
{
    // Intro Screen for the Application 

    cout << "\n\n\n\n\n\n\n\n\n\n\n" << endl;
    cout <<"\t\t\t\t"<<"      "<< "=================================" << endl;
    cout<<"\t\t\t\t\t"<<"Employee Managment Application" << endl;
    cout <<"\t\t\t\t"<< "      "<<"=================================" << endl;
	cout << "\n\n\n Please press any key to proceed : ";

	// getch to hold screen till user click key
	_getch();

	system("cls");
}

void outro() {
	system("cls");
	cout << "\n\n\n\t\t\t*** Programmed by : Elsayed Ahmed Elsayed :) ***" << endl;
	cout << "\t\t\t\t-----------------------"<<endl;
	_getch();
}

void MainScreen()
{
	// Main screen of application and its followed attributes based on switch 

	int dec = 6;
	while (dec) {
		cout << "\t\t\t\tMain Menu" << endl;
		cout << "\t\t\t      --------------" << endl;

		cout << "\n\n\n" << endl;
		cout << "-------------------------------" << endl;
		cout << "[1] Departments" << endl
			<< "[2] Staff" << endl
			<< "[3] Projects" << endl
			<< "[0] Exit" << endl;
		cout << "-------------------------------\n\n";

		cout << "Please Choose a number to proceed : ";
		cin >> dec;
		cout << "\n--------------------------------\n";
		switch (dec) {
		case 1:
			departmentsMenu();
			break;
		case 2:
			staffMenu();
			break;
		case 3:
			projectsMenu();
			break;
		}

		system("cls");
	}
}

void departmentsMenu()
{
	// menu related to departments 

	int dec0 = -1;
	while (dec0)
	{
		system("cls");
		cout << endl;
		cout << "\t\t\t\tDepartments Menu" << endl;
		cout << "\t\t\t      --------------------" << endl;

		cout << "\n\n\n" << endl;
		cout << "-------------------------------" << endl;
		cout << "[1] Add New Department" << endl
			<< "[2] Print All Departments" << endl
			<< "[0] Exit" << endl;
		cout << "-------------------------------\n\n";

		cout << "Please Choose a number to proceed : ";

		cin >> dec0;
		cout << "\n--------------------------------\n";
		cout << endl;
		switch (dec0) {
		case 1:
			program.addDepartment();
			break;
		case 2:
			program.PrintDprtmnts();
			break;
		}
		// wait for a key input to make the program more friendly
		if (dec0 != 0)
		{
			cout << "\n\nPlease Enter any Key to proceed : ";
			_getch();
		}

	}

	
}

void staffMenu()
{
	// Staff Members Menu
	int dec0 = -1;

	while (dec0)
	{
		system("cls");

		cout << "\t\t\t\tStaff Menu" << endl;
		cout << "\t\t\t      --------------" << endl;

		cout << "\n\n\n" << endl;
		cout << "-------------------------------" << endl;
		cout << "[1] Add New Member" << endl
			<< "[2] Print All Members" << endl
			<< "[3] Search" << endl
			<< "[4] Calculate Payroll" << endl
			<< "[5] Delete Member" << endl
			<< "[0] Exit" << endl;
		cout << "-------------------------------\n\n";

		cout << "Please Choose a number to proceed : ";
		cin >> dec0;
		cout << "\n--------------------------------\n";
		switch (dec0) {
		case 1:
			program.addMember();
			break;
		case 2:
			program.printAllMembrs();
			break;
		case 3:
			program.search();
			break;
		case 4:
			program.calcPayroll();
			break;
		case 5:
			program.deleteMember();
			break;
		}
		// wait for a key input to make the program more friendly

		cout << "\n\nPlease Enter any Key to proceed : " << endl;
		if (dec0 != 0)
			_getch();
	}

}

void projectsMenu()
{
	// Projects Menu

	int dec0 = -1;
	while (dec0)
	{
		system("cls");

		cout << "\t\t\t\tProjects Menu" << endl;
		cout << "\t\t\t      ----------------" << endl;

		cout << "\n\n\n" << endl;
		cout << "-------------------------------" << endl;
		cout << "[1] Add New Project" << endl
			<< "[2] Print All Projects" << endl
			<< "[3] Add Budget to Existing Project" << endl
			<< "[4] Increase Budget to Existing Project" << endl
			<< "[0] Exit" << endl;
		cout << "-------------------------------\n\n";

		cout << "Please Choose a number to proceed : ";
		cin >> dec0;
		cout << "\n--------------------------------\n";
		switch (dec0) {
		case 1:
			program.addNewProject();
			//cout << "<<\t\t\t\tNew Project Added Successfully>>"<<endl;
			break;
		case 2:
			program.printAllProjects();
			break;
		case 3:
			program.addBudget();
			break;
		case 4:
			program.incBudget();
			break;
		}
		// wait for a key input to make the program more friendly
		cout << "\n\nPlease Enter any Key to proceed" << endl;
		if(dec0 !=0)
		_getch();
	}
}
