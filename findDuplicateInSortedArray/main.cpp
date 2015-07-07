/*
 * main.cpp
 *
 *  Created on: Jul 20, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

int useBinarySearch (int arr[], int size)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int midpoint = (left + right)/2;

		if (arr[midpoint] != midpoint + 1)
			right = midpoint - 1;
		else
			left = midpoint + 1;

		if (left > right)
		{
			cout << "Number at index " << left << " is duplicate.\n";
			return left;
			break;
		}
	}

	return -1;
}


int main ()
{
	int arr [10] = {1,2,2,3,4,5,6,7,8,9};
	int index = useBinarySearch (arr, 10);
}


