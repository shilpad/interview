/*
 * main.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

http://www.geeksforgeeks.org/k-largestor-smallest-elements-in-an-array/
//Modify outermost loop to run atmost k times in order to find k largest elements
int main ()
{
	int a [5] = {3,2,6,1,4};
	for (int i = 0; i < 2; i++)
	{
		int min = i;
		for (int j = i+1; j < 5; j++)
		{
			if (a[j] < a[min])
				min = j;
		}

		//swap a[min] & a[i]
		int temp = a[min];
		a[min] = a[i];
		a[i] = temp;
	}

	for (int i = 0; i < 5; i++)
		cout << a[i] << " ";
}
