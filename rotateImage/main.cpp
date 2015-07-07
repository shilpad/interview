/*
 * main.cpp
 *
 *  Created on: Aug 23, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

void rotateMatrix (int arr [4][4], int n)
{
	for (int layer = 0; layer < n/2; ++layer)
	{
		int first = layer;
		int last = n - 1 - layer;
		for (int i = first; i < last; ++i)
		{
			int offset = i - first;

			int top = arr [first][i];
			cout << top << " = arr[" << first << "][" << i << "]\n";

			arr [first] [i] = arr [last-offset][first];
			cout << "arr[" << first << "][" << i << "] = arr[" << last << "-" << offset << "][" << first << "]\n";

			arr[last-offset][first] = arr[last] [last-offset];
			cout << "arr[" << last << "-" << offset << "][" << first << "] = arr[" << last << "][" << last << "-" << offset << "]\n";

			arr[last][last-offset] = arr[i][last];
			cout <<  "arr[" << last << "][" << last << "-" << offset << "] = arr[" << i << "][" << last << "]\n";

			arr[i][last] = top;
			cout << "arr[" << i << "][" << last << "] = " << top << "\n";
		}
	}
}

int main ()
{
	int arr [4][4] = {{1,2,3,4},
					  {5,6,7,8},
					  {9,10,11,12},
					  {13,14,15,16}};


	rotateMatrix (arr, 4);

}



