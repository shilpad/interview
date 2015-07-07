/*
 * main.cpp
 *
 *  Created on: Sep 4, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <set>

using namespace std;

void printRepeatingStrings (string str, int sequenceLength)
{
	if (str.length() == 0 || sequenceLength <=0 || sequenceLength > str.length())
		return;

	int i = 0;
	int j = i + sequenceLength;

	set<string> tempSet;
	set<string> repeatingSequence;

	while (j <= str.length())
	{
		//cout << "i=" << i << " j=" << j << endl;
		string sub = str.substr (i, sequenceLength);
		pair<set<string>::iterator, bool> ret = tempSet.insert (sub);
		cout << sub << "=" << ret.second << endl;
		if (ret.second == false)
			repeatingSequence.insert (sub);

		i++;
		j = i + sequenceLength;
	}

	for (set<string>::iterator it = tempSet.begin(); it != tempSet.end(); ++it)
	{
		cout << *it << endl;
	}

	cout << "-------------------------\n";

	for (set<string>::iterator it = repeatingSequence.begin(); it != repeatingSequence.end(); ++it)
	{
		cout << *it << endl;
	}
}


int main ()
{
	//printRepeatingStrings("ABCABCA", 2);
	printRepeatingStrings("ABCACBABC", 3);
//	printRepeatingStrings("ABABBABBZEDZEDZE", 3);
//	printRepeatingStrings("AAGATCCGTCCCCCCAAGATCCGTC", 10);
}
