/*
 * main.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <map>

using namespace std;

int makeChange (int total, int denom [], int index, map <int, int> cache)
{
	cout << "Calling makeChange for " << total << " with index=" << index << endl;
	map <int, int>::iterator it = cache.find (total);
	if (it != cache.end())
	{
		return it->second;
	}

	if (index >= (4 - 1))
	{
		cout << "Returning !\n";
		return 1;
	}

	int denomAmount = denom [index];
	int ways = 0;

	for (int i = 0; i * denomAmount <= total; ++i)
	{
		cout << i << " * " << denomAmount << endl;
		int remaining = total - (i * denomAmount);
		ways += makeChange (remaining, denom, index+1, cache);
	}

	cache [total] = ways;
	return ways;
}

int main ()
{
	int denom [] = {25,10,5,1};
	int total = 50;
	map <int,int> map;

	cout << makeChange (total, denom, 0, map) << endl;
}



