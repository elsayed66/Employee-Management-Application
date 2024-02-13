#ifndef _EMPLOYEE_H
#define _EMPLOYEE_H
#include "StaffMember.h"


class Employee:public StaffMember
{
	// abstract class
protected:
	string socialSecurityNumber;


public:
    Employee();
    virtual ~Employee();
	virtual string Print() {
		// this function will call protected Print Functin of StaffMember and add More details related to Employee

		return  StaffMember::Print() +'\t' + " SSN = " + socialSecurityNumber;
	}
	// pure virtual function
	virtual double Pay() = 0;
	void setSSN(string ssn) { socialSecurityNumber = ssn; }
};
#endif

