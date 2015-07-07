/*
 * main.cpp
 *
 *  Created on: Sep 3, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <vector>

using namespace std;

bool pair_compare (const pair <int,int> &a, const pair<int,int> &b)
{
	return a.first < b.first;
}

int covered_interval(std::vector<std::pair<int, int> > pairs)
{
	int n = pairs.size();
	if (n == 0)
		return -1;

	std::sort(pairs.begin(), pairs.end(), pair_compare);

	int i = 1;
	int sum = 0;
	int begin = pairs[0].first;
	int end = pairs[0].second;
	cout << "Start with begin=" << begin << " end=" << end << endl;

	while (i < n)
	{
		std::pair<int, int> pair = pairs[i];
		cout << pair.first << "," << pair.second << endl;

		if (pair.first > end)
		{
			cout << pair.first  << " is bigger than " << end << endl;
			sum += end - begin;
			begin = pair.first;
			end = pair.second;
		} else
		{
			if (end < pair.second)
			{
				end = pair.second;
			}
		}

		cout << "Sum=" << sum << " begin=" << begin << " end=" << end << endl;
 		i++;
  }

	sum += end - begin;
	cout << "Final sum=" << sum << endl;
	return sum;
}

int main ()
{
	vector<pair<int,int> > pairs;

	pairs.push_back(make_pair(1,3));
	pairs.push_back(make_pair(2,5));
	pairs.push_back(make_pair(8,9));

	cout << "Interval covered=" << covered_interval (pairs) << endl;

}


