#include"person.h"

Person::Person( vector<int> C , int a):Connection(C) , valu(a)
{
	
}

Person::~Person()
{
	Connection.~vector();
}

