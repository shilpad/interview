/*
 * main.cpp
 *
 *  Created on: Aug 1, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <vector>
#include <set>

#include "sortString.h"

using namespace std;

struct Compare {
	bool operator () (const string &str1, const string &str2)
	{
		return (str1.length () > str2.length());
	}
};

int main ()
{
	/*Datastructure ds;

	ds.add ("cat");
	ds.add ("brown");
	ds.add  ("mat");
	ds.add  ("rat");
	ds.add ("fall");
	ds.add ("zebra");
	ds.add  ("bat");

	ds.sort ();

	ds.print();*/

	// sort string vector based on length of strings
	vector<string> vecStrings;
	vecStrings.push_back("abc");
	vecStrings.push_back("abcde");
	vecStrings.push_back("zzzzzz");

	Compare c;
	std::sort (vecStrings.begin(), vecStrings.end(), c);

	for (vector<string>::iterator it = vecStrings.begin(); it != vecStrings.end(); it++)
	{
		cout << *it << endl;
	}

}

