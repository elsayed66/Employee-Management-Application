#ifndef _STAFFMEMBER_H
#define _STAFFMEMBER_H

#include<iostream>
#include<string>
using namespace std;

class StaffMember
{
	// abstract Class
protected:
	int employeeID;
	string name;
	string phone;
	string email;



public:
	StaffMember();
	virtual ~StaffMember();
	int type;
	int Departmnt;

	int getId() { return employeeID; }
	string getName() { return name; }
	string getPhone() { return phone; }
	string getEmail() { return email; }

	void setID(int id) { employeeID = id; }
	void setName(string name) { this->name = name; }
	void setPhone(string phone) { this->phone = phone; }
	void setEmail(string email) { this->email = email; }
	bool search(string key)const;
	string TypToString(int typ);

	virtual string Print() { return to_string(employeeID)+'\t' + name + "\t\t" + phone + "\t\t" + email + "\t\t" + TypToString(type) + "\t"+to_string(Departmnt); }
	// pure virtual function
	virtual double Pay() = 0;
};
#endif

