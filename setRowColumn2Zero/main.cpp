
#include <iostream>
using namespace std;

void makeRowColumnZero (int otherMatrix[3][3], int row, int col)
{
	for (int i = 0; i < 3; ++i)
	{
		otherMatrix [row][i] = 0;
		otherMatrix [i][col] = 0;
	}
}

void print (int matrix[3][3])
{
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
			cout << matrix [i] [j];
		cout << endl;
	}
}

void makeZero (int matrix [3][3])
{
	int otherMatrix [3][3];

	for (int i = 0; i < 3; ++i)
		for (int j = 0; j < 3; ++j)
			otherMatrix [i][j] = matrix [i][j];

	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (matrix[i][j] == 0)
				makeRowColumnZero (otherMatrix, i, j);
		}
	}

	print (otherMatrix);
}

int main ()
{
	int matrix [3][3] = {{1,1,1},
						 {1,0,1},
						 {1,1,1}};

	makeZero (matrix);

}
