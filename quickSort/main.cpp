/*
 * main.cpp
 *
 *  Created on: Jul 22, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <algorithm>

using namespace std;

int partition (int arr[], int left, int right)
{
	// find pivot
	int pivot = (left + right) / 2;
	while (left <= right)
	{
		while (arr[left] < arr[pivot])
			++left;

		while (arr [right] > arr[pivot])
			--right;

		// swap with pivot
		if (left <= right)
		{
			int temp = arr[left];
			arr [left] = arr[right];
			arr [right] = temp;
			++left;
			--right;
		}
	}

	return left;
}

void quicksort (int arr[], int left, int right)
{
	int index = partition (arr, left, right);

	if (left < index-1)
		quicksort (arr, left, index - 1);

	if (right > index)
		quicksort (arr, index, right);
}

void partial_quicksort (int arr[], int left, int right, int k)
{
	int index = partition (arr, left, right);

	partial_quicksort (arr, left, index - 1, k);

	if (index < k -1)
		partial_quicksort (arr, index + 1, right,  k);
}
int main ()
{
	int arr [] = {2,4,1,7,-3,10, 20,5};

	int size = sizeof(arr)/sizeof(arr[0]);

	quicksort (arr, 0, size -1);
	//partial_quicksort (arr, 0, size -1, 3);

	for (int i=0; i < size; ++i)
		cout << arr [i] << ",";
}

