/*
 * main.cpp
 *
 *  Created on: Sep 7, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
using namespace std;

//http://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/

int main ()
{
	int arr [] = {5,1,4, 2,8,-1,10,20,15,-10,50,26};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 6;

	for (int i=0; i<k ; i++)
	{
	  for (int j=0; j<n-1-i; j++)
	  {
	    /* compare the two neighbors */
	    if (arr[j+1] < arr[j])
	    {
	      /* swap a[j] and a[j+1]      */
	      int tmp = arr[j];
	      arr[j] = arr[j+1];
	      arr[j+1] = tmp;
	    }
	  }
	}

	cout << "Sorted array is:\n";
	for (int i = 0; i < n; ++i)
		cout << arr[i] << ",";
}


