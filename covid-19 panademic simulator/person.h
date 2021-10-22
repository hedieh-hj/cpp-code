#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include<vector>
using namespace std;

class Person
{
public:
	Person(vector<int> C , int a);
	~Person();
	vector<int> Connection;
	int getperson() const { return valu; };
	
private:
	int valu;
};


