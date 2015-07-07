/*
 * main.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: rudolpharaujo
 */
#include <vector>
#include <iostream>
using namespace std;

vector<int> convertToSet (int x, vector<int> vec)
{
	vector<int> subset;
	int index = 0;
	for (int i = x; i > 0; i >>= 1)
	{
		if ((i & 1) == 1)
		{
			subset.push_back((vec[index]));
		}
		index++;
	}

	return subset;
}

vector<vector<int> > getSubsets (vector<int> lst)
{
	vector<vector<int> > allSubSets;
	int max = 1 << lst.size ();

	for (int i = 0; i < max; i++)
	{
		vector<int> subsets = convertToSet (i, lst);
		allSubSets.push_back(subsets);
	}

	return allSubSets;
}

int main ()
{
	vector<int> vec;
	vec.push_back (1);
	vec.push_back (2);
	vec.push_back (3);

	vector<vector<int> > subsets = getSubsets (vec);
	vector<vector<int> >::iterator it;
	for (it = subsets.begin(); it != subsets.end (); ++it)
	{

		vector <int> tmp = *it;
		for (vector<int>::iterator it = tmp.begin(); it != tmp.end(); it++)
		{
			cout << *it;
		}
		cout << endl;
	}
}
