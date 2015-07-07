/*
 * main.cpp
 *
 *  Created on: Jul 19, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
using namespace std;

#define ROW 3
#define COL 4


void diagonalTraversal (int matrix[ROW][COL])
{
	int x = 0, y = 0, sub_x = 0, sub_y = 0;

	while (true)
	{
		sub_x = x; sub_y = y;
		cout << "sub_x=" << sub_x << " sub_y = " << sub_y << endl;

		while (sub_x >= 0 && sub_y <= COL-1)
		{
			cout << matrix [sub_x] [sub_y];
			--sub_x;
			++sub_y;
		}

		cout << endl;

		if (x < ROW - 1)
			++x;
		else if (y < COL - 1)
			++y;
		else
			break;
	}
}


int main ()
{
	int matrix [ROW] [COL] = {{2,3,5,6},
					  	  	  {5,2,3,1},
					  	  	  {7,5,3,4}};

	diagonalTraversal (matrix);
}
