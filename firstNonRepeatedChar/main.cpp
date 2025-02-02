/*
 * main.cpp
 *
 *  Created on: Jul 8, 2014
 *      Author: rudolpharaujo
 */


#include <iostream>
#include <list>
#include <map>
using namespace std;

typedef struct CharToNum
{
	char ch;
	int	 nOccurrences;
}CharToNum;

bool searchInList (std::list<CharToNum> &lstCharToNum, char &ch)
{
	std::list<CharToNum>::iterator itList;
	for (itList = lstCharToNum.begin(); itList != lstCharToNum.end(); ++itList)
	{
		if (itList->ch == ch)
		{
			itList->nOccurrences++;
			return true;
		}
	}

	return false;
}

// Horrible solution - Complexity : O(n^2)
int solution1 (string &strWord)
{
	std::list<CharToNum> lstCharToNum;

	//loop through the word
	for (int i=0; i < strWord.length(); ++i)
	{
		char ch = strWord[i];
		// search if character has been added to  list i.e. has occurred before in strWord
		bool found =searchInList (lstCharToNum, ch);

		if (found == false)
		{
			CharToNum charOccurrence;
			charOccurrence.ch = ch;
			charOccurrence.nOccurrences = 1;
			lstCharToNum.push_back(charOccurrence);
		}
	}

	// Iterate through the final list and find 1st character with 1 occurrence
	std::list<CharToNum>::iterator itList;
	for (itList = lstCharToNum.begin(); itList != lstCharToNum.end(); itList++)
	{
		CharToNum charOccurrence = *itList;
		cout << charOccurrence.ch << " occurs " << charOccurrence.nOccurrences << " times.\n";
		if (charOccurrence.nOccurrences == 1)
		{
			cout << "Solution 1 (Using list): 1st character in string " << strWord << " that occurs only once is " << itList->ch << endl;
			return 0;
		}
	}

	return 0;
}
// Time Complexity : O(n)
int solution2 (string &strWord)
{
	map<char,int> mapCharToInt;
	map<char,int>::iterator itMap;

	//loop through the word
	for (int i=0; i < strWord.length(); ++i)
	{
		char ch = strWord[i];

		// search character in map
		itMap = mapCharToInt.find (ch);
		if (itMap != mapCharToInt.end())
		{
			// found
			itMap->second++;
		}
		else
		{
			mapCharToInt [ch] = 1;
		}
	}

	// once again loop through the array
	for (int i=0; i < strWord.length(); ++i)
	{
		char ch = strWord[i];

		// search character in map
		itMap = mapCharToInt.find (ch);
		if (itMap->second == 1)
		{
			cout << "Solution2 (Using map): 1st character in string " << strWord << " that occurs only once is " << ch << endl;
			return 0;
		}

	}

	return 0;
}

int main ()
{
	string strWord;

	cout << "Enter a word:" ;
	cin >> strWord;
	cout << strWord << endl;

	// Solution 1
	solution1 (strWord);

	solution2 (strWord);

	return 0;
}
