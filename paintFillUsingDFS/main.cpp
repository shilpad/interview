/*
 * main.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <stack>
using namespace std;

class Node
{

public:
	int x;
	int y;

	Node (int x, int y)
	{
		this->x = x;
		this->y = y;
	}
};

void paintFill (int **matrix, int x, int y, int oColor, int nColor)
{
	stack<Node> stack;
	stack.push (Node (x,y));

	while (!stack.empty())
	{
		Node node = stack.top();
		stack.pop();

		if (node.x < 0 || node.x >= 20 || node.y < 0 || node.y >= 20)
			continue;

		if (matrix[node.x] [node.y] == nColor)
			continue;

		cout << "================" << nColor << endl;
		matrix[node.x] [node.y] = nColor;

		stack.push (Node (x + 1, y));
		stack.push (Node (x - 1, y));
		stack.push (Node (x, y + 1));
		stack.push (Node (x, y - 1));
	}
}

void print (int **matrix)
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			cout << matrix[i][j] << ",";
		}
		cout << endl;
	}

	cout << "------------------------\n";
}

void paintFill (int **matrix , int oColor, int nColor)
{
	print (matrix);

	paintFill (matrix, 10, 10, oColor, nColor);

	print (matrix);
}

int main ()
{
	int n = 20;
	int **matrix = new int *[n];
	int oldColor = 100;
	int newColor = 200;


	for (int i = 0; i < n; i++)
		matrix [i] = new int (n);

	cout << "Coming here ?\n";

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix [i][j] = oldColor;

	cout << "Coming here ?\n";

	paintFill (matrix, oldColor, newColor);
}



