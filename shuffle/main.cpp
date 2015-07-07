/*
 * main.cpp
 *
 *  Created on: Aug 18, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

int random (int low, int high)
{
	return (low + rand() * (high - low + 1));
}

int *shuffle (int cards[], int n)
{
	if (n == 0)
		return cards;

	shuffle(cards, n-1);

	int k = random (0,n);

	swap (cards[k], cards[n]);

	return cards;
}

void iterative (int cards[], int n)
{
	for (int i =0; i < n; ++i)
	{
		int rand = random (0, i);
		swap (cards[i], cards[rand]);
	}
}

int main ()
{
	int cards[5] = {1,3,5,7,38};
	shuffle (cards, 5);

	iterative (cards, 5);
}
