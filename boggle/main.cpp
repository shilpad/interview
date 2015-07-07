/*
 * main.cpp
 *
 *  Created on: Jul 15, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

bool inBounds (int row, int col)
{
	if (row < 0 || row > 3 || col < 0 || col > 3)
		return false;

	return true;
}

bool isValidWord (const string &str)
{
	if (str == "PACKING")
		return true;
}

void boggle (char board[4][4], int row, int col, string prefix, bool **marked)
{
//	cout << "Row=" << row << " Col=" << col << endl;
	// Check if the character is not in use
	if ((!inBounds(row, col)) || marked [row][col])
	{
		return;
	}

	// Append character to the prefix
	prefix += board[row][col];

	// Check this prefix against the provided dictionary which could be stored
	// as trie - which essentially is a tree data structure generally used for storing lists
	// of words. It gives a very efficient runtime to call isPrefix()
	//if (!isValidPrefix()) return;

	// Check if the prefix matches against the dictionary and print it if it does
	if (isValidWord (prefix))
		cout << "In boggle -- " << prefix << endl;

	marked [row][col] = true;

	boggle (board, row-1, col, prefix, marked); //top
	boggle (board, row+1, col, prefix, marked); // down
	boggle (board, row, col+1, prefix, marked); // right
	boggle (board, row, col-1, prefix, marked); //left

	marked[row][col] = false;
}

void boggle (char board[4][4], int nRows, int nCols)
{
	bool **marked = new bool*[nRows];
	for (int i=0; i < nRows; i++)
		marked [i] = new bool[nCols];

	string prefix;

	for (int i = 0; i < nRows; i++)
	{
		for (int j = 0; j < nCols; j++)
		{
			cout << "--------------------" << board[i][j] << "\n";
			boggle (board, i, j, prefix, marked);
		}
	}

	cout << "---------------\n";

	/*for (int i = 0; i < nRows; i++)
	{
		delete [] marked [i];
	}*/

	cout << "Here ?\n";

	//delete []marked;
}

int main ()
{
	int nRows = 0, nCols = 0;

	//cout << "Enter the number of rows and columns\n";
	//cin >> nRows >> nCols;
	nRows = nCols = 4;

	/*char **board = new char*[nRows];
	for (int i = 0; i < nRows; i++)
	{
		board [i] = new char [nCols];
	}*/

	// initialize this array
	char board [4][4] = { {'L','I','G','O'},
						  {'E','P','N','I'},
						  {'N','A','C','K'},
						  {'S','M','A','R'}};

	boggle (board, nRows, nCols);

	/*for (int i = 0; i < nRows; i++)
	{
		delete [] board [i];
	}

	delete []board;*/
}

