#include "StaffMember.h"

StaffMember::StaffMember()
{
	// default constructor initializes variables of the staff Member
	employeeID = 0;
	name = "";
	phone = "";
	email = "";
	type = 0;
	Departmnt = 0;
}

StaffMember::~StaffMember()
{
}
string StaffMember::TypToString(int typ) {
	// function switch on each staff member type to pring string value which is type of staff member as text
	switch (typ)
	{
	case 0:
		return "Volunteer";
	case 1:
		return "Hourly Employee";
	case 2:
		return "Salaried Employee";
	case 3:
		return "Commission Employee";
	case 4:
		return "Executive Employee";
	default:
		return "un-Known type";
	}
}

bool StaffMember::search(string key) const
{
	// search function which compare the string(key) with the user data to check for any similarities 
	// if none of these conditions return true then the function will return false

	if (to_string(employeeID) == key || name.find(key) != string::npos || phone.find(key) != string::npos || email.find(key) != string::npos ||
		to_string(Departmnt).find(key) != string::npos || to_string(type).find(key) != string::npos)
		return true;

	return false;
}

