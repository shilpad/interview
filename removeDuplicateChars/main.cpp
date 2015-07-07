/*
 * main.cpp
 *
 *  Created on: Jul 13, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
#include <set>
using namespace std;

bool occursOnlyOnce (set<char> &setCharsOccurred, char ch)
{
	if (setCharsOccurred.find(ch) == setCharsOccurred.end())// did not find
	{
		// Add to set
		setCharsOccurred.insert(ch);
		return true;
	}
	else
		return false;
}

int main ()
{
	// “abracadabra” ? “abrcd”

	//1.	Find duplicates

	//2. 	Remove them
	string strWord = "abracadabra";
	int len = strWord.length();

	//int src = 0;
	int dest = 0;
	set<char> setCharsOccurred;
	for (int i = 0; i < len; ++i)
	{
		cout << "Here 0 for " << strWord[i] << "\n";
		char ch = strWord [i];
		// does this need to be written to the final output
		if (occursOnlyOnce (setCharsOccurred, ch))
		{
			cout << "Here 1 for " << strWord[i] << "\n";
			strWord [dest++] = strWord [i];
		}

		//++src;
	}

	strWord = string (strWord, 0, dest);
	cout << "Output:" << strWord << endl;
}



