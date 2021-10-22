#pragma once
#include <iostream>
#include <fstream>
#include <conio.h>
#include<vector>
#include<time.h>
#include<stdlib.h>
#include"world.h"

class Disease : public World
{
public:
	Disease();
	~Disease();

	int getdayKill() const { return dayKill; };
	void setdayKill(int daykill);

	int getcommunitySize() const { return communitySize; };
	void setcommunitySize();

	void setvpr(int VPR);

	int getkills() const { return Kills; };

	int getkillLoop() const { return killLoop; };
	void setkillLoop();

	void addperson(Person& person, int i);
	void diseaseSimulation();

};


