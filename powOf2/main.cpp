/*
 * main.cpp
 *
 *  Created on: Jul 15, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

int main ()
{
	int num = 0;

	cout << "Enter number\n";
	cin >> num;

	int quotient = num, remainder = 0;

	while (quotient != 1)
	{
		remainder = quotient % 2;
		quotient = quotient / 2;
	}

	cout << remainder << " " << quotient << endl;

	if (remainder == 0)
		cout << "Number is power of 2 \n";
	else
		cout << "Number is NOT a power of 2 \n";

	return 0;
}



