//Ágúst Örn Eiğsson
//Skilaverkefni 2

#include "stdafx.h"
#include <iostream>
#include <bitset>
#include <cmath>

using namespace std;


int main()
{
	int ipnumb[4], netbitar, netaskipt;

	cout << "\nSlad inn upphafsnet: ";

	for (int i = 0; i < 4; i++)
	{
		cin >> ipnumb[i];
	}

	cout << "\nFjoldi netbita i upphafsneti: ";
	cin >> netbitar;


	cout << "\nFjoldi neta sem a ad skipta upphafsnetinu i: ";
	cin >> netaskipt;

	double stuff = log2(netaskipt);

	cout << stuff;

	cout << ipnumb[0];
	for (int i = 1; i < 4; i++)
	{
		cout << "." << ipnumb[i];
	}
	cout << endl;
}
