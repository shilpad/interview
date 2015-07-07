/*
 * main.cpp
 *
 *  Created on: Jul 16, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <algorithm>

using namespace std;

//int arr [5] = {3,2,6,5,7};
void printMissing (int arr [], int n)
{
	for (int i = 0; i < n; ++i)
	{
		int k = i;
		cout << "\nIteration " << i << endl;
		while (arr [k] != k+1)
		{
			if ((arr[k] < 1) || (arr[k] > n) /*|| (arr [k] == arr[arr[k]-1])*/)
			{
				arr[k]=-1;
				cout << "\nBreaking!\n";
				break;
			}

			cout << "\nSwap elements at " << k << " and " << arr[k] -1 << " position\n";
			// i.e. if arr[k] = 3 for k = 0 -> 3 should ideally be at 3rd position i.e. k-1 i.e. 2
			swap (arr[k], arr [arr[k]-1]);

			//print out current state
			for (int tmp=0; tmp < n; ++tmp)
				cout << arr[tmp] << ",";
		}
	}

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] < 0)
			cout << "\nMissing number =" << i+1 << endl;
	}
}

void printOneMissingNumber (int arr[], int n)
{
	long XOR = 0;

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] !=0)
			XOR ^= arr [i];

		XOR ^= i+1;
	}
	cout << XOR << " is the missing element. Wow !" << endl;

}

void traditionalMethod (int arr[], int n)
{
	//Compute total of n numbers using n*(n+1)/2
	int expectedTotal = (n * (n+1))/2;
	int total = 0;

	for (int i =0; i < n; ++i)
	{
		total += arr[i];
	}

	cout << "Missing number is " << (expectedTotal - total) << endl;
}

int main ()
{
	int arr [5] = {3,2,6,5,7};

	printMissing (arr, 5); // find k missing numbers

	//int array1 [10] = {1,2,3,4,5,6,8,9,10};
	//printOneMissingNumber (array1, 10);

	//traditionalMethod (array1, 10);

}



