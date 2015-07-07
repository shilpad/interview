/*
 * main.cpp
 *
 *  Created on: Jul 23, 2014
 *      Author: rudolpharaujo
 */
#include <map>
#include <iostream>
using namespace std;

/* Problem : Given an array of integers (1,2,3,4).
 * Find the sum of pairs of integers in shortest time.
 * i.e. (1,2), (1,3), (1,4), (2,3), (2,4), (4,5) are the pairs
 * Add them up: (1+2) + (1+3) + (1+4) + (2+3) + (2+4) + (3+4) = 30
 * Solution: Notice, every integer shows up 3 times in the listing of pairs.
 * 			 i.e. 1*3 + 2*3 + 3*3 + 4*3 = 30 !
 *           You will observe the same thing when you change the number of elements i.e. (1,2,3)
 *           (1,2) (1,3) (2,3)
 *           i.e. 1*2 + 2*2 + 3*2 = 12
 * Generalize: For every integer
 * 				integer * (length of array - 1)
 * 			   end for
 *
 */

int main ()
{
	int arr [] = {1,2,3,4};
	int len = sizeof (arr)/sizeof(arr[0]);
	int total = 0;
	int times = len - 1;

	for (int i=0; i < len; ++i)
	{
		total += arr[i] * times;
	}

	cout << "Total is " << total << endl;
}



