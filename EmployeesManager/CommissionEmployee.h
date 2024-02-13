#ifndef _COMMISSIONEMPLOYEE_H
#define _COMMISSIONEMPLOYEE_H
#include "Employee.h"


class CommissionEmployee:public Employee
{
private:
	double target;

public:
	CommissionEmployee();
	void setTarget(double target) { this->target = target;}
	double getTarget() { return target; }
	double Pay() { return 0.05 * target; }
	string Print() { return Employee::Print() + " , Target = " + to_string(target); }
};
#endif
