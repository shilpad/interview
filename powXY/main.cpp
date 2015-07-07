/*
 * main.cpp
 *
 *  Created on: Sep 3, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
using namespace std;

int power (int x, int y)
{
	if (y == 0)
		return 1;

	int temp = power (x, y/2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (x * temp * temp);

}

int main ()
{
	int x = 2;
	int y = 3;

	int ans = power (x,y);
	cout << ans << endl;
}


