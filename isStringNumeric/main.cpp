/*
 * main.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

bool isStringNumeric (string &str, int base)
{
	string strBase = "0123456789ABCDEF";
	string sub = strBase.substr (0, base);

	return (str.find_first_not_of (sub) == string::npos);
}

int main ()
{
	string str = "-12.3A";

	std::size_t pos = str.find ("-");
	if (pos != 0 && pos != string::npos)
		cout << "Not valid\n";
	else if (pos == 0)
		str = str.substr(1);

	cout << str << endl;

	pos = str.find (".");
	if (pos == 0 || pos == str.length() - 1)
		cout << "Not valid\n";
	else if (pos != string::npos)
	{
		cout << pos << endl;
		str = str.substr (0, pos) + str.substr (pos+1);
	}

	cout << str << endl;

	int base = 16;

	cout << "Is " << str << " a numeric string=" << isStringNumeric (str, base) << endl;
}
