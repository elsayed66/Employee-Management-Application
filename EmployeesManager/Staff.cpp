#include "Staff.h"

#include "Volunteer.h"
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "ExecutiveEmployee.h"

void Staff::incStaffList()
{
	// function to increase the staff list array size using copy statement

	StaffMember** tempStffArr = new StaffMember*[stffMmbrsArrSiz + 20];
	stffMmbrsArrSiz += 20;

	copy(staffList, staffList + staffCount, tempStffArr);

	// delete the old array and assign the new array address to the staff list
	// deleting array the dynamci to free space of memory taken by the program
	for (int i = 0; i < staffCount; i++)
	{
		delete* (staffList + i);
	}
	delete[]staffList;

    staffList = tempStffArr;
}

Staff::Staff()
{
	// intialize count of members and size of members array
	staffPoint = NULL;
	staffCount = 0;
	stffMmbrsArrSiz = 5;
	staffList = new StaffMember * [stffMmbrsArrSiz];
}

Staff::~Staff()
{
	// deleting array the dynamic space of memory allocated by the program
	for (int i = 0; i < staffCount; i++)
	{
		delete *(staffList+i);
	}
	delete[]staffList;
}

void Staff::delteArr(StaffMember** staffList) {
	// deleting array the dynamci s[ace of memory taken by the program
	for (int i = 0; i < staffCount; i++)
	{
		delete* (staffList + i);
	}

	delete[]staffList;
}

void Staff::addMember(int typ,int deprtment,string name,string phone , string email)
{
	// adding new staff Member
	// Inserting the extra data according to each member type
	// 
	// types of Members 0- volunteer 1- Hourly employee 2 - salaried employee 3 - commission employee 4- executive employee

	StaffMember* pointMem = NULL;
	if (typ == 0) {//volunteer
		Volunteer* volPoint = new Volunteer;
		double amount;

		cout << "Please Enter amount : ";
		cin >> amount;
		cout << endl;
		volPoint->setAmount(amount);
		// finally inserting data into pointer of type staff Member
		pointMem = volPoint;
	}
	else if (typ == 1) {//Hourly employee
		HourlyEmployee* tempPointer = new HourlyEmployee;
		double hours,rate;
		cout << "Please Enter hours Worked : ";
		cin >> hours;
		cout << endl;
		tempPointer->setHoursWorked(hours);

		cout << "Please Enter the Rate : ";
		cin >> rate;
		cout << endl;
		tempPointer->setRate(hours);
		// finally inserting data into pointer of type staff Member
		pointMem = tempPointer;

	}
	else if (typ == 2) {// salaried employee 
		SalariedEmployee* tempPointer = new SalariedEmployee;
		double salary;
		cout << "Please Enter Salary: ";
		cin >> salary;
		cout << endl;
		tempPointer->setSalary(salary);

		// finally inserting data into pointer of type staff Member
		pointMem = tempPointer;
	}
	else if (typ == 3) {//commission employee
		CommissionEmployee* tempPointer = new CommissionEmployee;
		double target;
		cout << "Please Enter the Target : ";
		cin >> target;
		cout << endl;
		tempPointer->setTarget(target);

		// finally inserting data into pointer of type staff Member
		pointMem = tempPointer;
	}
	else if(typ==4){// executive employee
		ExecutiveEmployee* tempPointer = new ExecutiveEmployee;
		double salary, bonus;
		cout << "Please Enter Salary : ";
		cin >> salary;
		cout << endl;
		tempPointer->setSalary(salary);

		cout << "Please Enter the Bonus : ";
		cin >> bonus;
		cout << endl;
		tempPointer->setBonus(bonus);
		// finally inserting data into pointer of type staff Member
		pointMem = tempPointer;
	}
	
	*(staffList+staffCount) = pointMem;

	(*(staffList + staffCount))->type = typ;
	(*(staffList + staffCount))->Departmnt = deprtment;

	(*(staffList + staffCount))->setID(staffCount);
	(*(staffList + staffCount))->setName(name);
	(*(staffList + staffCount))->setPhone(phone);
	(*(staffList + staffCount))->setEmail(email);

	staffCount++;

	//check if the array of staff members is filled
	if (staffCount >= stffMmbrsArrSiz - 2)
		incStaffList();


	cout << "\t\t\tMemeber Added Successfully :)" << endl;

}



void Staff::addExtraMember(ExecutiveEmployee* employe)
{
	// adding the manager of a project to the main staff data
	ExecutiveEmployee* exec = new ExecutiveEmployee;
	(*exec) = (*employe);

	(*(staffList + staffCount)) = exec;

	staffCount++;

	if (staffCount >= stffMmbrsArrSiz - 2)
		incStaffList();

}


void Staff::calcPayroll() const
{
	// printing total payroll of all staff Members
	double totPayroll = 0;
	for (int i = 0; i < staffCount; i++)
	{
		// using pointers to ovverride claulate total payrolls function using polymorphism
		totPayroll += (*(staffList + i))->Pay();
	}
	if (totPayroll == 0)
		cout << "!!!! Total Payroll of all Staff Members= 0";
	else
	cout << "\t\t\t" << "Total Payroll of all staff Members = "<<totPayroll<<endl;
}

void Staff::delMember()
{
	// delete members base on id

	int id;
	cout << "Please Enter Member Id :";
	while (true) {
		cin >> id;
		if (id < 0 || id >= staffCount)
			cout << "\aPlease Enter a valid Member Id ";
		else
			break;
	}
	staffCount--;
	
	// delte the selected element from memory
	delete* (staffList + id);

	//copy(staffList + id + 1, staffList + staffCount, staffList + id);
	
	// this loop shift elements by ovverwirte the next element on it
	for (int i = id; i < staffCount; i++)
	{
		*(staffList+i) = *(staffList + i + 1);
	}
	
	cout << "\t\t\tMemeber Deleted Successfully :("<<endl;

}
inline void printMemberHeader() {
	// header for print main row of contacts table as in search and print all 
	// name "\t\t" + phone + "\t\t" + email + "\t\t" + to_string(Departmnt) + '\t' + to_string(type)

	cout << "\n\n"
		<<"id"<<'\t' << "Name" << "\t\t" << "Phone" << "\t\t\t" << "E-Mail" << "\t\t\t\t" << "Type" << '\t' << "Department Id" << '\t' << "Other Information" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Staff::printAllMembrs() const
{

	// function loop to print all Staff Members inside the system 
	printMemberHeader();
	for (int i = 0; i < staffCount; i++)
	{
		// using pointers to ovverride print function using polymorphism
		cout<<(*(staffList + i))->Print();
		cout << endl;

	}

}

void Staff::Search() const
{
	// seacrch function take a key from the user and use it to call search functions of every Staff Member
	// then print User found by the print function
	string key;
	cin.ignore();
	cout << "Please Enter a Key to Search for : ";
		getline(cin, key);
		cout << endl;
		bool findOne = false;

		printMemberHeader();
	for (int i = 0; i < staffCount; i++)
	{
		if ((*(staffList + i))->search(key)) {
			findOne = true;
			cout << (*(staffList + i))->Print() << endl;
		}
	}
	// this condition to print a message if there is no contact founded
	if (!findOne) cout << "\t\t\t!!! No contact Founded . :(" << endl;
}


