#include"disease.h"


Disease::Disease()
{
}

Disease::~Disease()
{
	community.~vector();
	communityhelp.~vector();
	Connections.~vector();
}


void Disease::setdayKill(int daykill)
{
	dayKill = daykill;
}

void Disease::setcommunitySize()
{
	communitySize = community.size();
}

void Disease::setvpr(int VPR)
{
	vpr = VPR;
}

void Disease::setkillLoop()
{
	killLoop++;
}

void Disease::addperson(Person& person, int i)
{
	int x;
	vector<int> a;
	x = person.getperson();
	community.push_back(x);
	communityhelp.push_back(x);
	a = person.Connection;
	Connections.push_back(a);
}
void Disease::diseaseSimulation()
{
	srand(time(0));
	float r, dp, v;
	v = (float)vpr / 10;
	int xx = 0; ///// chek kardan tedad marg dar har dor ! ( bishtar az do ta nashe )
	for (int i = 0; i < communitySize; i++) {

		if (community[i] > 0 && community[i] != -1) {
			int x, y, z;
			x = Connections[i].size();
			//srand(time(0));
			y = 1 + rand() % (x);
			for (int j = 0; j < y; j++) {
				z = Connections[i][j];
				if (community[z] == 0) {
					communityhelp[z] = 10;
				}
			} ///// enteqal 

			if (killLoop % dayKill == 0) {
				dp = v * (communityhelp[i]) ;
				//srand(time(0));
				r = rand() % 10;
				//cout << "\ndp : " << dp << "\nr : " << r << endl;
				if (dp > r && xx < 1) {

					cout << "\ndp : " << dp << "\nr : " << r << "\nkillLoop : " << killLoop << endl;
					communityhelp[i] = -1;
					xx++;
					Kills++;

				}
			}

			if (communityhelp[i] != -1)
				communityhelp[i] -= 1; //// eltiam

		}
	}
	for (int i = 0; i < communitySize; i++) {
		community[i] = communityhelp[i];
	}
}
