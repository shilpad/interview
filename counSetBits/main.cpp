/*
 * main.cpp
 *
 *  Created on: Jul 17, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
using namespace std;

void countSetBits (int n)
{
	int count = 0, number = n;
	//for(count; n; n >>= 1)
	while (n != 0)
	{
		int result = n & 1;
		cout << "result = " << result << endl;

	    if ((n & 1) == 1)
	    	count++;

	    n >>= 1;
	}

	// 3210
	// 8421

	// 0001 & 1 = 1
	// 0010 & 1 = 10
	// 0011 & 1 = 11
	// 0100 & 1 = 100
	// 0101
	// 0110
	// 0111 & 1 = 0
	// 1000

	cout << "Number of bits set in " << number << " = " << count << endl;
}


int main ()
{
	countSetBits (1);
	countSetBits (2);
	countSetBits (3);
	countSetBits (4);
	countSetBits (5);

}
