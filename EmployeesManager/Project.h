#ifndef _PROJECT_H
#define _PROJECT_H

#include "Budget.h"
#include "Employee.h"
#include"StaffMember.h"

class Project
{
private:
	int projectID;
	string location;
	Employee* manager;
	double currentCost;

	int budgetCount;
	int budgetArrSiz;
	Budget *budgetList;

	void incBudgetList();

public:
	Project();
	~Project();
	void setId(int id) { projectID = id; }
	void setLocation(string location) { this->location = location; }
	void setCurrentCost(double currentCost) { this->currentCost = currentCost; }
	void setManager(Employee* manager) { this->manager = manager; }
	int getId() { return projectID; }
	string getLocation() { return location; }
	double getcost() { return currentCost; }
	StaffMember* getManager() { return manager; }

	void addBudget();
	void increasBudget();
	double getTotalBudget();
	void printBudgetsData();
	void Print();

};
#endif
