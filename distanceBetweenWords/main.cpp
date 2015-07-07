/*
 * main.cpp
 *
 *  Created on: Sep 5, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
using namespace std;

int findDistance (string str, string pair1, string pair2)
{
	int distance = 0;
	size_t found;
	int finalDistance = INT_MAX;
	int trailingPos = 0;

	do
	{
		found  = str.find_first_of (" ", trailingPos);
		string sub = str.substr (trailingPos, found - trailingPos);
		cout << sub << endl;

		if (sub == pair1)
			distance = 0;
		else if (sub == pair2)
			finalDistance = min (finalDistance, distance);

		++distance;
		trailingPos = found + 1;
	}while (found != string::npos);

	if (finalDistance == INT_MAX || finalDistance == 0)
		return -1;
	else
		return finalDistance;
}

int main ()
{
	//string in = "hello how are you";
	//string in = "hello how are hello you";
	//string in = "you are hello";
	string in = "hello how are hello";

	string pair1 = "hello";
	string pair2 = "you";

	int d = findDistance (in, pair1, pair2);
	cout << d << endl;
}


