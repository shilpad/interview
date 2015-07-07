/*
 * main.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

// count number of 2 in a single number
int numberOf2s (int n)
{
	int count = 0;

	while (n > 0)
	{
		if (n % 10 == 2)
			count++;
		n = n / 10;
	}

	return count;
}

// count number f '2' between 2 and n
int numberOf2sInARange (int n)
{
	int count = 0;
	for (int i =2; i <= n; i++)
		count += numberOf2s (i);

	return count;
}

int main ()
{
	int n = 21;
	int count = numberOf2sInARange (n);
	cout << "Number of 2's from 0 to " << n <<  " = " << count << endl;

}


