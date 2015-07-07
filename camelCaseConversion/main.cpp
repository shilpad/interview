/*
 * main.cpp
 *
 *  Created on: Jul 13, 2014
 *      Author: rudolpharaujo
 */


#include <iostream>
#include <set>
using namespace std;

// Change annika palaash shilpa rudolph -> AnnikaPalaashShilpaRudolph
int main ()
{
	//1. Convert 1st letter to capital if its lower case
	//2. Remove space

	string strWord = "annika palaash shilpa rudolph";
	cout << "Original string = " << strWord << "\n";
	bool bPreviousSpace = false;
	int src = 0, dest = 0;

	for (int i=0; i <  strWord.length(); i++)
	{
		if ((i == 0) || (bPreviousSpace == true))
			strWord [i] = (strWord[i] >= 'a' && strWord[i] <= 'z') ? strWord[i] - 'a' + 'A': strWord[i];

		if (strWord[i] != ' ')
		{
			strWord [dest++] = strWord [src];
			bPreviousSpace = false;
		}
		else
			bPreviousSpace = true;

		++src;
	}

	strWord = string (strWord, 0, dest);
	cout << "CamelCase conversion = " << strWord << "\n";
}

