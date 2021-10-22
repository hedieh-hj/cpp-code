#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include<string>
#include<stdlib.h>
#include<vector>
using namespace std;

class Dataset
{
public:
	Dataset();
	~Dataset();
	vector<vector<int>> personFriends;
	void matrix(int &n , vector<vector<int>> &vec);
	void personsConnection(int num, int name );

	void matrix2(int& n, vector<vector<int>>& m);
	bool chek(int& n, vector<vector<int>>& m);
	void vorodi(int& n, vector<vector<int>>& m);
	void personsConnection2(int num, int name);

private:
	
};


