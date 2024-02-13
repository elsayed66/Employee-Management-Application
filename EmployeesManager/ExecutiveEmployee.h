#ifndef _EXECUTIVEEMPLOYEE_H
#define _EXECUTIVEEMPLOYEE_H
#include "SalariedEmployee.h"

class ExecutiveEmployee:public SalariedEmployee
{
private:
	double bonus;

public:
	ExecutiveEmployee();
	void setBonus(double bonus) { this->bonus = bonus; }
	double getBonus() { return bonus; }

	void addBonus(double moreBonus) { bonus += moreBonus; }

	double Pay() { return salary + bonus; }
	string Print() { return SalariedEmployee::Print() + " , Bonus = " + to_string(bonus); }
};

#endif
