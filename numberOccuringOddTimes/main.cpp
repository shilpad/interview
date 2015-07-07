/*
 * main.cpp
 *
 *  Created on: Jul 23, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;



// A chain of XOrs is true whenever an odd number of inputs are true, its false otherwise
int main ()
{
	int arr [] = {1,2,3,3,2,3,1,3,3,4,4};
	int len = sizeof(arr)/sizeof(arr[0]);
	int result = 0;

	for (int i=0; i < len; ++i)
		result = result ^ arr[i];

	cout << result  << " occurrs odd number of times\n";

	// Use Xor to find the only different number in two unsorted arrays
	//This didnt work so solution is using hash table
	/*int arr1 []  = {1,4,3,2,7,10,8};
	int arr2 [] = {1,4,3,2,7,9,8};
	int size = sizeof (arr1)/sizeof (arr1[0]);
	findMismatch (arr1, arr2, size);*/
}



