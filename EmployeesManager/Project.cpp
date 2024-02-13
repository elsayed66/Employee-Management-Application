#include "Project.h"

void Project::incBudgetList()
{
	// this function increase budget list size if needed by using temporary budget array

	Budget* tempList = new Budget[budgetArrSiz + 20];
	copy(budgetList, budgetList + budgetCount, tempList);

	delete[]budgetList;

	budgetList = tempList;

	budgetArrSiz += 20;
}

Project::Project()
{
	// intialize project data
	projectID = 0;
	location = "Un-defined";
	currentCost = 0;

	// localize budget list
	budgetCount = 0;
	budgetArrSiz = 5;
	budgetList = new Budget[budgetArrSiz];

	//manager->setID(-1);
}

Project::~Project()
{
	// delocalize budget list 
	delete[]budgetList;
}

inline void printMemberHeader() {
	// header for print main row of contacts table as in search and print all 
	// 
	// name "\t\t" + phone + "\t\t" + email + "\t\t" + to_string(Departmnt) + '\t' + to_string(type)

	cout << "\n\n"
		<< "id" << '\t' << "Name" << "\t\t" << "Phone" << "\t\t\t" << "E-Mail" << "\t\t\t\t" << "Type" << '\t' << "Department Id" << '\t' << "Other Information" << endl;
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}


void Project::addBudget()
{
	// adding new budget to the project
	(budgetList + budgetCount)->setId(budgetCount);

	double value;
	cout << "Please Enter Budget Value : ";
	cin >> value;
	(budgetList + budgetCount)->setValue(value);
	
	currentCost += value;
	budgetCount++;
	// check if the budget list is fully occupied
	if (budgetCount >= budgetArrSiz - 2)
		incBudgetList();
}

void Project::increasBudget()
{
	// Increase amount of budget to the same project
	int budgId;
	double addsValue;
	cout << "Please Enter budget ID: ";
	cin >> budgId;
	cout << endl;

	cout << "Please Enter Budget adds value : ";
	cin >> addsValue;

	(budgetList + budgId)->increaseBudget(addsValue);

	currentCost += addsValue;
}

double Project::getTotalBudget()
{
	// add all project budgets to get the total budget
	double totalBudget = 0;
	for (int i = 0; i < budgetCount; i++)
	{
		totalBudget += (budgetList + i)->getValue();
	}
	return totalBudget;
}

void Project::printBudgetsData()
{
	// function print all budgets in a suitable format

	cout << "[Budget Id]" << "\t\t" << "[Budget Value]" << endl;
	for (int i = 0; i < budgetCount; i++)
	{
		cout << (budgetList + i)->Print() << endl;
	}
}

void Project::Print()
{
	// [Project id] location current cost 
	cout << "[-Project ID-]" << "\t\t" << "[-Location-]\t\t[-Current Cost-]" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << '[' << projectID << ']' << "\t\t\t" << location << "\t\t" << currentCost<<endl;
	cout << endl;
	cout << "\n\t\t---Budget Details---\n" << endl;
	printBudgetsData();
	cout << endl;
	cout << "\n\t\tManager Details :- \n" << endl;
	printMemberHeader();
	cout<<(manager)->Print();

	cout << "\n";
}
