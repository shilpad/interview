/*
 * main.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

#define HEIGHT 4
#define WIDTH 4
#define ALIVE 'X'
#define DEAD '.'

struct Shape
{
	public:
		int x;
		int y;
		int height;
		int width;
		char **figure;
};

struct Blinker: public Shape
{
	public:
		static const int BLINKER_HEIGHT = 3;
		static const int BLINKER_WIDTH = 1;

		Blinker (int x, int y);
		~Blinker ();
};

class GameOfLife
{
	private:
		char world [HEIGHT][WIDTH];
		char otherworld [HEIGHT][WIDTH];
		Shape shape;
		bool toggle;

		void changeStateOfCell (int noOfAliveNeighbors, int row, int col); //update
		int inspectNeighbors (int row, int col); // getState

	public:
		GameOfLife (Shape sh);

		void print ();
		void start();
};

GameOfLife::GameOfLife(Shape sh) : shape (sh), toggle(true)
{
	for (int i = 0; i < HEIGHT; ++i)
	{
		for (int j = 0; j < WIDTH; ++j)
		{
			world [i][j] = DEAD;
			otherworld [i][j] = DEAD;
		}
	}

	for (int i = shape.y; i - shape.y < shape.height; i++)
	{
		for (int j = shape.x; j-shape.x < shape.width; j++)
		{
			world[i][j] = shape.figure [i - shape.y] [j - shape.x];
			otherworld[i][j] = shape.figure [i - shape.y] [j - shape.x];
		}
	}
}

void GameOfLife::print ()
{
	if (toggle)
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
				cout << world [i][j];
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < HEIGHT; i++)
		{
			for (int j = 0; j < WIDTH; j++)
				cout << otherworld [i][j];
			cout << endl;
		}
	}
}

void GameOfLife::changeStateOfCell (int noOfAliveNeighbors, int row, int col)
{
	if (toggle)
	{
		if (world[row][col] == ALIVE)
			otherworld[row][col] = (noOfAliveNeighbors > 1 && noOfAliveNeighbors < 4) ? ALIVE : DEAD;
		else if (world[row][col] == DEAD && noOfAliveNeighbors == 3)
			otherworld [row][col] = ALIVE;
	}
	else
	{
		if (otherworld[row][col] == ALIVE)
			world[row][col] = (noOfAliveNeighbors > 1 && noOfAliveNeighbors < 4) ? ALIVE : DEAD;
		else if (otherworld[row][col] == DEAD && noOfAliveNeighbors == 3)
			world [row][col] = ALIVE;
	}
}

int GameOfLife::inspectNeighbors (int row, int col)
{
	int count = 0;
	if (toggle)
	{
		for (int i = max (0, row - 1); i <= min(row+1, HEIGHT); ++i)
		{
			for (int j = max (0, col -1); j <= min (col+1, WIDTH); ++j)
			{
				if (i != row || j != col)
				{
					// check status of the cell
					if (world[i][j] == ALIVE)
					{
						//cout << "Neighbor=" << i << "," << j << endl;
						++count;
					}
				}
			}
		}
	}
	else
	{
		for (int i = max (0, row - 1); i <= min(row+1, HEIGHT); ++i)
		{
			for (int j = max (0, col -1); j <= min (col+1, WIDTH); ++j)
			{
				if (i != row || j != col)
				{
					// check status of the cell
					if (otherworld[i][j] == ALIVE)
					{
						//cout << "Neighbor=" << i << "," << j << endl;
						++count;
					}
				}
			}
		}
	}

	return count;
}

void GameOfLife::start ()
{
	for (int row = 0; row < HEIGHT; row++)
	{
		for (int col = 0; col < WIDTH; col++)
		{
			int noOfAliveNeighbors = 0;

			// inspect each cell and find its neighbors if current cell is alive
			noOfAliveNeighbors = inspectNeighbors (row,col);
			//cout << noOfAliveNeighbors << " alive for row=" << row << ", col=" << col << endl;
			changeStateOfCell (noOfAliveNeighbors, row, col);
		}
	}

	toggle = !toggle;
}


Blinker::Blinker (int xIn, int yIn)
{
	x = xIn;
	y = yIn;
	height = BLINKER_HEIGHT;
	width = BLINKER_WIDTH;
	figure = new char*[BLINKER_HEIGHT];

	for (int i = 0; i < BLINKER_HEIGHT; i++)
		figure [i] = new char [BLINKER_WIDTH];

	for (int i = 0; i < BLINKER_HEIGHT; i++)
	{
		for (int j = 0; j < BLINKER_WIDTH; j++)
			figure [i][j] = 'X';
	}
}

Blinker::~Blinker ()
{
	for (int i = 0; i < BLINKER_HEIGHT; i++)
		delete[] figure[i];

	delete[] figure;
}

int main ()
{
/*	int matrix [4][4] = {{0,1,1,0},
						 {0,1,1,0},
						 {0,0,0,0},
						 {0,0,0,0}};

	start(matrix);

	print (matrix);*/

	Blinker blinker (1, 0);
	GameOfLife gol (blinker);
	gol.print ();

	int noOfIterations = 3;
	for (int i = 0; i < noOfIterations; ++i)
	{
		cout << "-------------------\n";
		gol.start ();
		gol.print();
	}

}



