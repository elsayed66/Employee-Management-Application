#ifndef _SALARIEDEMPLOYEE_H
#define	_SALARIEDEMPLOYEE_H
#include "Employee.h"


class SalariedEmployee :public Employee
{
protected:
	double salary;

public:
	SalariedEmployee();
	virtual ~SalariedEmployee();
	double getSalary() { return salary; }
	void setSalary(double salary) { this->salary = salary; }

	virtual double Pay(){ return salary; }
	virtual string Print() { return Employee::Print() +" , salary = " + to_string(salary); }
};
#endif

