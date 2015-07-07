/*
 * main.cpp
 *
 *  Created on: Aug 6, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

string implementCD_org (string pwd, string operations)
{
	std::size_t trailingpos = 0;
	std::size_t found;
	do
	{
		found = operations.find_first_of ("/",  trailingpos);
		string tok = operations.substr (trailingpos, found - trailingpos);

		if (tok == "..")
		{
			pwd = pwd.substr (0, pwd.length() - 2);
		}
		else
		{
			pwd += "/";
			pwd += tok;
		}
		trailingpos = found + 1;
	}while (found != string::npos);

	return pwd;
}


int main ()
{
	string finalWD = implementCD_org ("a/b", "c/../d/e/../f");

	// Expected : a/b/d/f
	cout << "New pwd=" << finalWD << endl;
}
