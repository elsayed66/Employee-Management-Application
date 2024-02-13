#include "Budget.h"

Budget::Budget()
{
	id = -1;
	value = 0;
}

string Budget::Print()
{
	return  to_string(id) + "\t\t" + to_string(value);
}
