/*
 * main.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

int fib (int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return (fib (n-1) + fib (n-2));
}

int arr [100];

int fast_fib (int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
	{
		if (arr[n] != 0)
			return arr[n];
		else
		{
			arr [n] = fast_fib (n-1) + fast_fib (n-2);
			return arr[n];
		}
	}
}

int main ()
{
	int n = 4;
	cout << "Fib of n=" << n << " is " << fib (n) << "\n";

	cout << "Fast fib of n=" << n << " is " << fib (n) << "\n";

}



