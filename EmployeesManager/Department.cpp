#include "Department.h"

Department::Department()
{
	departID = -1;
	departName = "Empty";
}

void Department::Print()
{
	cout << '[' << departID << ']' << "\t\t" << departName << endl;
}
