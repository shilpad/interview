/*
 * main.cpp
 *
 *  Created on: Aug 5, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <map>
#include <vector>
using namespace std;

void buildTriangle (int rows)
{
	map <int, int> mapRowToPos;
	vector<int> vecInts;

	for (int row = 1; row <= rows; ++row)
	{
		if (row == 1)
		{
			cout << "1 \n";
			vecInts.push_back (1);
			mapRowToPos [row] = row - 1;
		}
		else if (row == 2)
		{
			cout << "1 1 \n";
			vecInts.push_back (1);
			vecInts.push_back (1);
			mapRowToPos [row] = row - 1;
		}
		else
		{
						// low at the values from the previous row
			int prevRow = row - 1;
			int prevStartPos = mapRowToPos [prevRow];
			int prevEndPos = prevStartPos + (prevRow - 1);
		//	cout << "Row Pos = " << prevRow << " " << prevStartPos << " " << prevEndPos << "\n";
			for (int i = prevStartPos; i <= prevEndPos; ++i)
			{
				if ((i - 1) < prevStartPos)
				{
					cout << "1 ";
					vecInts.push_back (1);
				}
				else
				{
					int newVal = vecInts [i - 1] + vecInts [i];
					vecInts.push_back (newVal);
					cout << newVal <<  " ";
				}
			}
			cout << " 1 \n";
			vecInts.push_back (1);
			mapRowToPos [row] = prevEndPos + 1;
		}
	}
}

void version1 ()
{
	int nOfRows, cols, rows, value, nOfSpace;
	  printf("Pascal Triangle Program\n");
	  printf("Enter the number of rows: ");
	  scanf("%d",&nOfRows);

	  for (rows = 0; rows < nOfRows; rows++)
	  {
		  cout << "Row=" << rows << endl;
		  value = 1;
		 /* for(nOfSpace = 0; nOfSpace < nOfRows - rows; nOfSpace++)
		  {
			  printf("%3s", " ");
		  }*/

		  for (cols = 0; cols <= rows; cols++)
		  {
			  //cout << "col=" << cols << " value=" << value << endl;
			  printf("  %3d ",value);
			  value = value * (rows - cols) / (cols + 1);
			  //cout << "New Value=" << value << endl;
		  }
		  printf("\n");
	  }

	  printf("\n");
}

int main ()
{
	//buildTriangle (5);
	version1 ();
}
