/*
 * main.cpp
 *
 *  Created on: Jul 16, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <math.h>
using namespace std;

bool nextPrime (int n)
{

	if (n == 1)
	{
		return false;
	}
	else if (n == 2)
	{
		cout << n << " is the next prime.\n";
		return true;
	}
	else
	{
		for (int i = 2; i <= sqrt(n); ++i)
		{
		if (n % i == 0)
			return false;
		}

		cout << n << " is the next prime.\n";
		return true;
	}
}

// double the speed by avoiding the % operator
bool fastNextPrime (int n)
{
	cout << "Checking if prime:" << n << endl;

	if (n == 1)
	{
		return false;
	}
	else if (n == 2)
	{
		cout << n << " is the next prime.\n";
		return true;
	}
	else
	{
		for (int i=2; i <= sqrt(n); ++i)
		{
			int quot = n /i;

			if (n == quot * i)
				return false;
		}

		cout << n << " is the next prime.\n";
		return true;
	}
}

int main ()
{
	int n = 21;

	while (true)
	{
		if (fastNextPrime (n+1))
			break;
		else
			++n;
	}
}
