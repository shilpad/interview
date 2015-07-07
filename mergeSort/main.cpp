/*
 * main.cpp
 *
 *  Created on: Aug 9, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

void merge (int *arr, int *helper, int left, int mid, int right)
{
	// copy elements to helper
	for (int i = left; i <= right; ++i)
		helper [i] = arr [i];

	int current = left;
	int helperRight = mid + 1;
	while (left <= mid && helperRight <= right)
	{
		if (helper[left] <= helper [helperRight] )
			arr [current] = helper [left++];
		else
			arr[current] = helper [helperRight++];

		++current;
	}

	for (int i = left; i <= mid; ++i)
		arr [current++] = helper [i];

	for (int i = helperRight; i <= right; ++i)
		arr[current++] = helper [i];
}

void mergesort (int *arr, int *helper, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) /2;
		mergesort (arr, helper, left, mid);
		mergesort (arr, helper, mid+1, right);
		merge (arr, helper, left, mid, right);
	}
}

int main ()
{
	int arr [] = {4,2,1,7,-3,10, 20,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int *helper = new int [sizeof(arr)];

	cout << "Original array:\n";
	for (int i = 0; i < size; ++i)
		cout << arr [i] << " ";

	mergesort (arr, helper, 0, size - 1);

	cout << "\nAfter sorting:\n";
	for (int i = 0; i < size; ++i)
		cout << arr [i] << " ";
}



