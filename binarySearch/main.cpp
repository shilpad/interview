/*
 * main.cpp
 *
 *  Created on: Jul 20, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

int iterativeBinSearch (int size, int arr[], int numToFind)
{

	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int midpoint = (left + right) / 2;

		if (numToFind == arr [midpoint])
			return midpoint;
		else if (numToFind > arr [midpoint])
			left = midpoint + 1;
		else
			right = midpoint - 1;
	}

	return -1;
}

int recursiveBinSearch (int arr[], int num, int left, int right)
{
	if (left > right)
		return -1;

	int midpoint = (left + right) /2;
	if (num == arr[midpoint])
		return midpoint;
	else if (num > arr [midpoint])
		return (recursiveBinSearch(arr, num, midpoint+1, right));
	else
		return (recursiveBinSearch(arr, num, left, midpoint-1));
}

int main ()
{
	int arr [10] = {1,4,6,8,10,12,13,16,18,19};

	int num = 13;
	int size = sizeof(arr)/sizeof(arr[0]);
	int index = iterativeBinSearch (size, arr, num);
	cout << "iterativeBinSearch:" << num << " found at index " << index << endl;

	index = recursiveBinSearch (arr, num, 0, size-1);
	cout << "recursiveBinSearch:" << num << " found at index " << index << endl;

}



