#include "EmployeeManagment.h"

#include "ExecutiveEmployee.h"


EmployeeManagment::EmployeeManagment()
{
	// intialize count of departements
	dprtCount = 0;
	dprtmntsArrSiz = 5;
	tempDprtmntArr = NULL;
	dprtmntLst = new Department[dprtmntsArrSiz];

	projectArrSiz = 5;
	projectcount = 0;
	projctsList = new Project[projectArrSiz];


}

EmployeeManagment::~EmployeeManagment()
{
	// freeing up the memeory after closing project
	delete[]dprtmntLst;
	delete[]projctsList;
}

void EmployeeManagment::incProjctLst()
{
	// function to increase the projects array size using copy statement
	Project* tempProjctLst = new Project[projectArrSiz + 20];

	projectArrSiz += 20;
	copy(projctsList, projctsList + projectcount, tempProjctLst);

	// delete the old array and assign the new array address to the dempartment list
	delete[]projctsList;

	projctsList = tempProjctLst;
}

void EmployeeManagment::incDptmntLst()
{
	// function to increase the department array size using copy statement

	tempDprtmntArr = new Department[dprtmntsArrSiz + 20];
	dprtmntsArrSiz += 20;
	copy(dprtmntLst, dprtmntLst + dprtCount, tempDprtmntArr);

	// delete the old array and assign the new array address to the dempartment list
	delete[]dprtmntLst;

	dprtmntLst = tempDprtmntArr;
}


void EmployeeManagment::PrintDprtmnts()const
{
	// printing departements data in a suitable format

	cout << "\n[ID]\t\t[-Department Name-]\n";
	cout << "----------------------------------\n";

	for (int i = 0; i < dprtCount; i++)
	{
		dprtmntLst[i].Print();
	}
}

void EmployeeManagment::addDepartment()
{
	// adding a new department
	string name;
	cin.ignore();
	cout << "Please Enter Department Name : ";
	getline(cin, name);
	cout << endl;
	cout << "\t\t\t<-- A new Department Added Successfully -->" << endl;
	dprtmntLst[dprtCount].setId(dprtCount);
	dprtmntLst[dprtCount].setName(name);
	dprtCount++;

	//check if the array of departments is filled
	if(dprtCount>=dprtmntsArrSiz-2)
	incDptmntLst();

}

void EmployeeManagment::deleteMember()
{
	mainStaff.delMember();
}

void EmployeeManagment::printAllMembrs()const
{
	mainStaff.printAllMembrs();
}

void EmployeeManagment::addMember()
{
	int type,deprtmn;
	string name, email, phone;
	cin.ignore();

	cout << "Enter Member Name: ";
	getline(cin, name);
	cout << endl << "Enter Member Phone : ";
	getline(cin, phone);
	cout << endl << "Enter member email: ";
	getline(cin, email);
	cout << endl;
	cout << "Enter Member type as follow : \n"
		<< "0- Volunteer \t 1- Hourly Employee \t 2- Salaried Employee \t 3- Commission Employee \t 4- Executive Employee \t"<<endl;
	while (true)
	{
		cin >> type;
		if (type < 0 || type >4)
			cout << "Please Enter a Valid Type (0-4) " << endl;
		else
			break;
	}
	// choose the department of the employee
	cout << endl;
	cout << "Enter Member Department as follow : \n";
	for (int i = 0; i < dprtCount; i++)
	{
		cout << i << "- " << (dprtmntLst + i)->getName() << " \t";
	}
	cout << endl;
	cout << "enter Department Id: ";
	while (true)
	{
		cin >> deprtmn;
		if (deprtmn < 0 || deprtmn >= dprtCount)
			cout << "Please Enter a Valid department id (0 - "<<dprtCount-1<<") " << endl;
		else
			break;
	}
	mainStaff.addMember(type,deprtmn, name, phone, email);

}

void EmployeeManagment::calcPayroll()const
{
	//calaculating total payroll
	mainStaff.calcPayroll();
}

void EmployeeManagment::search() const
{
	// search for Members
	mainStaff.Search();
}

void EmployeeManagment::addNewProject()
{
	// adding new project
	string loc;
	double currnCost;
	cin.ignore();
	cout << "Please Enter Project Location: ";
	getline(cin, loc);
	cout << endl;
	cout << "Please Enter Current Cost :";
	cin >> currnCost;
	cout << endl;
	cin.ignore();

	// adding manager details
	ExecutiveEmployee* employee = new ExecutiveEmployee;
	string name, phone, email;
	cout << "Please Enter Manager's Name : ";
	getline(cin ,name);
	cout << endl;
	cout << "Please Enter Managers's Phone : ";
	getline(cin,phone);
	cout << endl;
	cout << "Please Enter Manager's E-mail : ";
	getline(cin,email);
	cout << endl;
	employee->setName(name);
	employee->setEmail(email);
	employee->setPhone(phone);
	string ssn;
	cout << "Please Enter Employee's Social Security Number : ";
	getline(cin, ssn);
	employee->setSSN(ssn);

	double salary, bonus;
	cout << "Please Enter Salary : ";
	cin >> salary;
	cout << endl;
	employee->setSalary(salary);

	cout << "Please Enter the Bonus : ";
	cin >> bonus;
	cout << endl;
	employee->setBonus(bonus);
	employee->setID(retStaff().getStaffCount());
	employee->type=4;
	
	(projctsList + projectcount)->setLocation(loc);
	(projctsList + projectcount)->setCurrentCost(currnCost);
	(projctsList + projectcount)->setManager(employee);

	mainStaff.addExtraMember(employee);

	cout << "\t\t\tProject Added Successfully";

	projectcount++;
	if (projectcount >= projectArrSiz - 2)
	incProjctLst();
}

void EmployeeManagment::printAllProjects() const
{
	for (int i = 0; i < projectcount; i++) {
		(projctsList + i)->Print();
		cout << endl;
	}
}

void EmployeeManagment::addBudget()
{
	// function allow user to add budget to an existing project
	int id;
	cout << "Please Enter Project Id : ";
	while (true)
	{
		cin >> id;
		if (id < 0 || id >= projectcount)
			cout << "\aPlease Enter a valid project Id";
		else
			break;
	}
	cout << endl;

	(projctsList + id)->addBudget();
}

void EmployeeManagment::incBudget()
{
	// function allow user to increase an existing budget of chosen project by an adds value
	int id;
	cout << "Please Enter Project Id : ";
	while (true)
	{
		cin >> id;
		if (id < 0 || id >= projectcount)
			cout << "\aPlease Enter a valid project Id";
		else
			break;
	}
	cout << endl;

	(projctsList + id)->increasBudget();
}
