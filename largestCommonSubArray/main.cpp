/*
 * main.cpp
 *
 *  Created on: Jul 19, 2014
 *      Author: rudolpharaujo
 */
#include <unordered_map>
#include <iostream>
using namespace std;

int main ()
{
	int arr1[] ={1,2,3,2,3,2};
	int arr2[] = {2,2,3,3,4,5};

	int size = sizeof(arr1)/sizeof(arr1[0]);

	int *result = new (nothrow) int [size] ();

	unordered_map<int, int> mapNumbers;

	// build unordered_map off arr1
	for (int i = 0; i < 6; ++i)
	{
		if (mapNumbers.find(arr1[i]) == mapNumbers.end())
		{
			// create new entry
			mapNumbers [arr1[i]] = 1;
		}
		else
			mapNumbers [arr1[i]] += 1;
	}

	// traverse through arr2 and find common elements
	// and fill result
	for (int i = 0; i < 6; ++i)
	{
		if ((mapNumbers.find(arr2[i]) != mapNumbers.end()) && (mapNumbers [arr2[i]] > 0))
		{
			//
			result [i] = arr2 [i];
			mapNumbers [arr1[i]] -= 1;
		}
	}

	//print out result
	for (int i = 0; i < 6; ++i)
	{
		if (result[i] > 0)
			cout << result [i] << ",";
	}

	cout << endl;

	delete []result;
}


