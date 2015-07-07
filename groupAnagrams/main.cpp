/*
 * main.cpp
 *
 *  Created on: Aug 6, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

bool isPrime (int n)
{

	if (n == 1)
	{
		return false;
	}
	else if (n == 2)
	{
		//cout << n << " is the next prime.\n";
		return true;
	}
	else
	{
		for (int i = 2; i <= sqrt(n); ++i)
		{
		if (n % i == 0)
			return false;
		}

		//cout << n << " is the next prime.\n";
		return true;
	}
}

int calculateKey (string strWord, int arr[26])
{
	int key = 1;
	for (int i = 0; i < strWord.length(); ++i)
	{
		int index = strWord[i] - 'a';
		key *= arr[index];
	}

	return key;
}

void printAnagrams (map <int, vector<string> > mapAnagrams)
{
	map <int, vector<string> >::iterator it = mapAnagrams.begin ();

	for (; it != mapAnagrams.end (); ++it)
	{
		vector<string> vecAnagrams = it->second;

		for (vector<string>::iterator itVec = vecAnagrams.begin(); itVec != vecAnagrams.end(); ++itVec)
		{
			cout << *itVec << " ";
		}
		cout << endl;
	}
}

void generatePrimes (int arr[26])
{
	// generate 26 primes
	int startFrom = 2;
	for (int i = 0; i < 26;)
	{
		if (isPrime (startFrom))
			arr [i++] = startFrom;

		++startFrom;
	}

	for (int i = 0 ; i < 26; ++i)
		cout << arr [i] << ",";
	cout << endl;
}

void groupAnagrams (vector<string> vecWordsProcessed)
{
	int arr [26];// =  {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101};
	generatePrimes (arr);

	map <int, vector<string> > mapAnagrams;
	map <int, vector<string> >::iterator itAnagram;

	//vector<string>::iterator it = vecWordsProcessed.begin();
	for (int i = 0; i < vecWordsProcessed.size(); ++i)
	{
		// calculate the key
		int key = calculateKey (vecWordsProcessed[i], arr);

		// Add key and word to map
		itAnagram = mapAnagrams.find (key);
		if (itAnagram == mapAnagrams.end())
		{
			// create new
			vector <string> vecAnagrams;
			vecAnagrams.push_back (vecWordsProcessed[i]);

			mapAnagrams [key] = vecAnagrams;
		}
		else
		{
			// update value
			(itAnagram->second).push_back (vecWordsProcessed[i]);
		}
	}

	printAnagrams (mapAnagrams);
}

int main ()
{
	// Assume strings are always in lowercase

/*	map<string, bool> mapWordsProcessed;
	mapWordsProcessed ["art"] = false;
	mapWordsProcessed ["rat"] = false;
	mapWordsProcessed ["bats"] = false;
	mapWordsProcessed ["banana"] = false;
	mapWordsProcessed ["stab"] = false;
	mapWordsProcessed ["tar"] = false;

	groupAnagrams (mapWordsProcessed);*/

	vector<string> vecWordsProcessed;
	vecWordsProcessed.push_back("art");
	vecWordsProcessed.push_back("rat");
	vecWordsProcessed.push_back("bats");
	vecWordsProcessed.push_back("banana");
	vecWordsProcessed.push_back("stab");
	vecWordsProcessed.push_back("tar");

	groupAnagrams (vecWordsProcessed);

}
