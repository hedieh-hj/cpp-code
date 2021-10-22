#include <iostream>
#include <fstream>
#include <conio.h>
#include<vector>
#include"dataset.h"
#include "world.h"
#include"disease.h"

using namespace std;


int main()
{
	Dataset* dataset;
	dataset = new Dataset();
	Disease* disease;
	disease = new Disease();
	int n{} , x = 0, period , NumIntervals , first , daykill ;
	float helper;
	char a{};
	vector<vector<int>> v, vv;
	dataset->matrix(n, v);
	cout << "\n";
	Person* person{};
	cout << "baraye estefade az file pishfarrz adad ( a ) va baraye vared kardan matrix adad ( b ) ra vared konid " << endl;
	while (x==0)
	{
		cin >> a;
		switch (a)
		{
		case 'a':
		case 'A':
			for (int i = 0; i < n; i++) {
				dataset->personsConnection(n, i);
				person = new Person(dataset->personFriends[i], 0);
				disease->addperson(*person, i);
			}
			x = 1;
			break;

		case 'b':
		case 'B':
			dataset->matrix2(n, vv);
			for (int i = 0; i < n; i++) {
				dataset->personsConnection2(n, i);
				person = new Person(dataset->personFriends[i], 0);
				disease->addperson(*person, i);
			}
			x = 1;
			break;

		default:
			cout << "\ndobare talash konid ( a / b ) : ";
			x = 0; //// dorost shavad
		}
	}
	

	cout << endl;
	cout << "ertabatat : " << endl;
	for (int i = 0; i < n; i++) {
		cout << "nafar " << i + 1 << "om : ";
		for (int j = 0; j < disease->Connections[i].size(); j++) {
			cout << disease->Connections[i][j] + 1 << "\t";
		}
		cout << endl;
	}
	
	cout << endl;
	
	cout << "\nmizan koshandegi viroos ra vared konid [0 , 10] ( 10 koshandegi 100% mibashad ) : ";
	cin >> helper;
	disease->setvpr(helper);
	cout << "baze haye zamani baraye namayesh vaziat ra vared konid : ";
	cin >> period;
	cout << "chand bar in baze tekrar shavad? ";
	cin >> NumIntervals;
	cout << "har chand rooz emkan marg vojood darad? ";
	cin >> daykill;
	disease->setdayKill(daykill);
	//for (int i = 0; i < world->community.size(); i++) {
	//	world->community[i] = 0;
	//	world->communityhelp[i] = 0;
	//}

	//world->communitySize = world->community.size();
	disease->setcommunitySize();
	while (0)
	{
		cout << "fard shoroo konande bimari ra entekhab konid (adadi mosbat va kamtar az nafarat vared shavad : ";
		cin >> first;
		if (first > n || n < 1) {
			cout << "sahih nist , dobare talash konid : ";
			cin >> first;
		}
		else
		{
			break;
		}
	}
	cout << "fard shoroo konande bimari ra entekhab konid (adadi mosbat va kamtar az nafarat vared shavad : ";
	cin >> first;
	disease->community[first-1] = 10;
	disease->communityhelp[first-1] = 10;
	//world->killLoop = 0;

	cout << "\ndp :  (koshandegi viroos / 10 ) * mizane aloodegi   &   r : adadi random baraye ehtemal marg \n\n";
	for (int i = 0; i < (period * NumIntervals) ; i++) {
		disease->setkillLoop();
		disease->diseaseSimulation();
		if (disease->getkillLoop() % period == 0 || i == 0) {
			cout << "i : " << i << endl;
			for (int j = 0; j < disease->getcommunitySize(); j++) {
				cout << disease->community[j] << "	";
			}
			cout << endl;
			cout << "tedad morde ha : " << disease->getkills() << endl << endl;
		}
		
		cout << endl;
	}


	person->~Person();
	dataset->~Dataset();
	disease->~Disease();
	vv.~vector();
	v.~vector();
	return 0;
}
