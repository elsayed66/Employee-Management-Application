#ifndef _VOLUNTEER_H
#define _VOLUNTEER_H
#include "StaffMember.h"



class Volunteer:public StaffMember
{
private:
	// find the type of amount
	int amount;


public:
	Volunteer();
	void setAmount(double amount) { this->amount = amount; }
	double getAmount() { return amount; }
	string Print() override{
	// this function will call protected Print Functin of StaffMember and add More details related to volunteer

		return StaffMember::Print() +'\t' + " amount: " + to_string(amount);

	}
	double Pay() {
		// this function will call protected Pay function of StaffMember
		return 0;
	}
};
#endif
