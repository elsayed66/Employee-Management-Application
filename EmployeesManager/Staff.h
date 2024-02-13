#ifndef _STAFF_H
#define _STAFF_H
#include"StaffMember.h"
#include"ExecutiveEmployee.h"

class Staff
{
private:
	StaffMember** staffList;

	StaffMember* staffPoint;
	int staffCount;
	int stffMmbrsArrSiz;

	void incStaffList();
	void delteArr(StaffMember** staffList);

public:
	Staff();
	~Staff();
	void addMember(int type,int deprtment,string name, string phone, string email);
	void addExtraMember(ExecutiveEmployee*employe);

	void calcPayroll()const;
	void delMember();
	void printAllMembrs()const;
	void Search()const;
	int getStaffCount()const { return staffCount; }
};
#endif

