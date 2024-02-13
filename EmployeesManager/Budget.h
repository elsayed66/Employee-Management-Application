#ifndef _BUDGET_H
#define _BUDGET_H

#include <iostream>
#include<string>
using namespace std;

class Budget
{
private:
	int id;
	double value;

public:
	Budget();
	void setId(int id) { this->id = id; }
	void setValue(double value) { this->value = value; }
	int getId() { return id; }
	double getValue() { return value; }
	void increaseBudget(double amount) { value += amount; }
	string Print();
};
#endif

