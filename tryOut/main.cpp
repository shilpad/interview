/*
 * main.cpp
 *
 *  Created on: Aug 27, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

enum Color  {NONE, BLACK, WHITE};

class Piece
{
private:
	Color color;

public:
	Piece () {}
	Piece (Color c) {color = c;}
	Color getColor () {return color;}

	Piece& operator=(Piece &piece)
	{
		color = piece.color;
		return *this;
	}
};

ostream& operator<<(ostream& out, Piece &piece)
{
	out << piece.getColor();
	return out;
}


class Board
{
private:
	Piece **board;

public:
	Board ()
	{

		board = new Piece*[5];
		for (int i = 0; i < 5; i++)
			board[i] = new Piece[5];

		Piece p (BLACK);

		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				board [i][j] = p;

	}

	void print ()
	{
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout <<  board [i][j] << ",";
			}
			cout << endl;
		}
	}

};

int main ()
{
	Board board;
	board.print ();
}
