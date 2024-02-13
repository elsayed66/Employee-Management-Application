#ifndef _EMPLOYEEMANAGMENT_H
#define _EMPLOYEEMANAGMENT_H

#include<iostream>
#include<string>
#include"Department.h"
#include"Staff.h"
#include "Project.h"

class EmployeeManagment
{
private:
	int dprtCount;
	int dprtmntsArrSiz;
	Department *dprtmntLst;
	Department* tempDprtmntArr;
	Staff mainStaff;

	Project* projctsList;
	int projectcount;
	int projectArrSiz;
	void incProjctLst();

	void incDptmntLst();


public:

	EmployeeManagment();
	~EmployeeManagment();
	void PrintDprtmnts()const;
	void addDepartment();
	void deleteMember();
	void printAllMembrs()const;
	void addMember();
	void calcPayroll()const;
	void search()const;
	Staff retStaff()const { return mainStaff; }

	void addNewProject();
	void printAllProjects()const;
	void addBudget();
	void incBudget();
};
#endif

