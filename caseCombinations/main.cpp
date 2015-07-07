/*
 * main.cpp
 *
 *  Created on: Aug 5, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

void caseCombine (string prefix, string suffix)
{
	if (suffix.length() == 0)
	{
		cout << prefix.c_str() << endl;
		return;
	}

	//string first = suffix.substr (0, 1);
	char chFirst = suffix [0];
	string rest = suffix.substr (1);

	//cout << chFirst << " " << rest << endl;

	if (tolower(chFirst) == toupper (chFirst))
	{
		caseCombine (prefix + chFirst, rest);
	}else
	{
		string tmp(1,tolower (chFirst));
		caseCombine (prefix + tmp, rest);

		tmp = string (1, toupper(chFirst));
		caseCombine (prefix + tmp, rest);
	}
}

int main ()
{
	string prefix = "";
	//string suffix = "beN!!!";
	string suffix = "0ab";
	caseCombine (prefix, suffix);
}


