/*
 * main.cpp
 *
 *  Created on: Jul 15, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

typedef int MAX_DIGITS = 10;

string itoa(int value)
{
	char tmp [MAX_DIGITS + 1];
	bool bIsNeg = false;

	if (value < 0)
	{
		bIsNeg = true;
		value *= -1;
	}

	int i = 0;
	while (value != 0)
	{
		tmp[i++] = (char) ((value % 10) + '0');
		value /= 10;
	}

	string final;
	if (bIsNeg)
		final = "-";

	while (i > 0)
	{
		final += tmp[--i];
	}

	return final;
}

int main ()
{
	int num = 24;
	string str = itoa(num);

	cout << num << "\n";
	cout << str << "\n";
}


