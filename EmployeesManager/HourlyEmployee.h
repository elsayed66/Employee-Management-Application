#ifndef _HOURLYEMPLOYEE_H
#define	_HOURLYEMPLOYEE_H
#include "Employee.h"


class HourlyEmployee :public Employee
{
private:
	double hoursWorked;
	double rate;

public:
	HourlyEmployee();
	void setHoursWorked(double hours) { hoursWorked = hours; }
	void setRate(double rate) { this->rate = rate;}

	double getHoursWorked() const{ return hoursWorked; }

	void addHours(int moreHours) { hoursWorked += moreHours; }
	double Pay() { return rate * hoursWorked; }
	string Print() { return Employee::Print() + " , Hours Worked = " + to_string(hoursWorked)+" , Rate = "+to_string(rate); }
};
#endif

