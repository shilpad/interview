/*
 * main.cpp
 *
 *  Created on: Aug 4, 2014
 *      Author: rudolpharaujo
 */
#include <unordered_set>
#include <iostream>
#include <stdlib.h>
using namespace std;

bool isSumZeroPossible (int *arr, int size)
{
	unordered_set<int> setInts;

	for (int i = 0; i < size; ++i)
		setInts.insert (arr[i]);

	for (int i =0; i < size; ++i)
	{
		for (int j = i+1; j < size; ++j)
		{
			int temp = -arr[i]-arr[j];

			if (setInts.find (temp) != setInts.end())
			{
				cout << "a = " << arr[i] << " b = " << arr[j] << " c = " << temp << endl;
				return true;
			}
		}
	}

	for (unordered_set<int>::iterator it = setInts.begin(); it != setInts.end(); ++it)
	{
		cout << *it << endl;
	}

	return false;
}

int comp (const void *a, const void *b)
{
	int *x = (int*)a;
	int *y = (int*)b;

	return *x - *y;
}

void allSumZeroCombinations (int arr[], int size)
{
	qsort (arr, sizeof (arr)/sizeof(arr[0]), sizeof(arr[0]), comp);

	for (int i = 0; i < size - 3; ++i)
	{
		int a = arr [i];
		int k = i+1;
		int l = size - 1;

		while (k < l)
		{
			int b = arr [k];
			int c = arr[l];

			if (a + b + c == 0)
			{
				// print numbers and continue search for more combinations
				++k;
				--l;
			}
			else if (a + b + c > 0)
				--l;
			else
				++k;
		}
	}
}

// Better solution: http://en.wikipedia.org/wiki/3SUM - Sort and find combinations
int main ()
{
	//int arr[] = {-9,-3,-2,6,8,7};
	int arr[] = {-7,4,-2,5,8};
	int size = sizeof(arr)/sizeof(arr[0]);

	//bool bZero  = isSumZeroPossible (arr, size);
	//cout << "isSumZeroPossible returned " << bZero << endl;

	allSumZeroCombinations (arr, size);
}


