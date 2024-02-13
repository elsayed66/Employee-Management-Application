#ifndef		_DEPARTMENT_H
#define     _DEPARTMENT_H
#include<iostream>
#include<string>
using namespace std;

class Department
{
private:
	int departID;
	string departName;


public:
	Department();
	void Print();

	void setId(int id) { departID = id;}
	void setName(string name) { departName = name; }

	int gettId() { return departID; }
	string getName() { return departName; }
};
#endif

