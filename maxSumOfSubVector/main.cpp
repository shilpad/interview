/*
 * main.cpp
 *
 *  Created on: Jul 11, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

//#define ARR_LEN sizeof(arr)/sizeof(arr[0])

void mySolution (int nArr[], int sizeOfArray)
{
	int maxSum = 0, total = 0;

	for (int i=0; i < sizeOfArray; i++)
	{
		total = nArr [i];
		if (total > maxSum) maxSum = total;

		for (int j=i+1; j < sizeOfArray; j++)
		{
			total += nArr[j];
			if (total > maxSum)
				maxSum = total;
		}
	}

	cout << "MaxSum=" << maxSum << endl;
}

void scanningAlgo (int nArr[], int sizeOfArray)
{
	int maxendinghere = 0;
	int maxsofar = 0;

	for (int i=0; i < sizeOfArray; i++)
	{
		maxendinghere = max(maxendinghere + nArr [i], 0);
		maxsofar = max (maxsofar, maxendinghere);
		cout << i << " " << maxendinghere << " " << maxsofar << endl;
	}

	cout << maxendinghere << " MaxSum = " << maxsofar << endl;
}

int main ()
{
	int arr [] = {31, -41, 59, 26, -53, 58, 97, -93, -23, 84};

	// Great link about finding size of array
	//http://stackoverflow.com/questions/37538/how-do-i-determine-the-size-of-my-array-in-c

	int n = sizeof(arr)/sizeof(arr[0]);

	//mySolution (arr, n); // O(n^2)

	//divideAndConquer (arr, n); O(nlogN)

	scanningAlgo (arr, n);// O(n) - programming pearls Pg 77
	return 0;
}

