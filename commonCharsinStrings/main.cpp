/*
 * main.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <set>
#include <vector>
using namespace std;


int findCommonChars (vector<string> vecStrings)
{
	int noOfUnique[256] = {0};

	for (int i = 0 ; i < vecStrings.size(); ++i)
	{
		set <char> setUnique;
		string str = vecStrings [i];
		for (int indexCh = 0; indexCh < str.length(); ++indexCh)
		{
			set<char>::iterator it = setUnique.find (str[indexCh]);
			if (it == setUnique.end())
			{
				int index = str[indexCh] - 'a';
				setUnique.insert (str[indexCh]);
				++noOfUnique [index];
			}
		}
	}

	int count = 0;
	// loop the array to see which char has count = vec.size()
	for (int i = 0; i < 256; ++i)
	{
		if (noOfUnique[i] == vecStrings.size())
		{
			++count;
			char ch = 'a' + i;
			cout << ch << " occurs " << vecStrings.size() << " times!\n";
		}
	}

	return count;
}

int main ()
{
	vector<string> vecStrings;
	vecStrings.push_back ("aghkafgklt");
	vecStrings.push_back ("dfghako");
	vecStrings.push_back ("qwemnaarkf");

	int count = findCommonChars (vecStrings);
	cout << count << " characters are common to all strings!\n";

}
