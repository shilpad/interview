/*
 * main.cpp
 *
 *  Created on: Aug 7, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

string expandAroundTheCenter (string strWord, int c1, int c2)
{
	int n = strWord.length ();
	while (c1 >= 0 && c2 <= n-1 && (strWord[c1] == strWord[c2]))
	{
		--c1;
		++c2;
	}

	return strWord.substr (c1 + 1, c2 - c1 - 1);
}

string longestPalindrome (const string &strWord)
{
	int n = strWord.length ();
	if (n == 0) return "";

	string longest = strWord.substr (0, 1);

	for (int i = 0; i < n; ++i)
	{
		// For cases where the center has 1 letter i.e. "abcdfgdcaba";
		string p1 = expandAroundTheCenter (strWord, i, i);
		if (p1.length() > longest.length())
			longest = p1;
	}

	for (int i = 0; i < n; ++i)
	{
		// For cases where the center has 2 same lettere i.e. "abcdfgdcabba";
		string p1 = expandAroundTheCenter (strWord, i, i+1);
		if (p1.length() > longest.length())
			longest = p1;
	}

	return longest;
}

int main ()
{
	string strWord = "abcdfgdcaba";
	string palindrome = longestPalindrome (strWord);
	cout << palindrome << endl;

	strWord = "abcdfgdcabba";
	palindrome = longestPalindrome (strWord);
	cout << palindrome << endl;
}

