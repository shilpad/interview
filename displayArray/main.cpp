/*
 * main.cpp
 *
 *  Created on: Sep 2, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

int** displayArray (int *arr, int size, int nCols)
{
	int elemsPerCol = size/nCols;
	int remain = size%nCols;

	int **output;
	int nRows = 0;
	if (remain == 0)
		nRows = elemsPerCol;
	else
		nRows = elemsPerCol + 1;

	output = new int*[nRows];
	for (int i = 0; i < nRows; ++i)
		output [i] = new int [nCols];

	int k = 0;
	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols - 1; j++)
		{
			if (k >= size)
				return output;

			output [j][i] = arr[k];
			k++;
		}

		if (remain > 0)
		{
			output [nRows - 1][i] = arr[k];
			remain--;
			k++;
		}
	}

	cout << "----------------------------------------" << endl;

	for (int i = 0; i < nRows; ++i)
	{
		for (int j = 0; j < nCols; ++j)
			cout << output [i][j] << " ";
		cout << endl;
	}

	return output;
}

int main ()
{
	int arr [7] = {1,2,3,4,5,6,7};
	int nCols = 3;
	int size = sizeof(arr)/sizeof(arr[0]);

	int **output = displayArray (arr, size, nCols);
}


