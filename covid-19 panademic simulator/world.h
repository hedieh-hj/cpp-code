#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include"person.h"


class World   ///// extend
{
public:
	World();
	~World();
	vector<int> community;
	vector<int> communityhelp;
	vector<vector<int>> Connections;
protected:
	int dayKill;
	int communitySize;
	int killLoop;
	float vpr;
	int Kills;
};
