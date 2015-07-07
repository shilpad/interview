/*
 * main.cpp
 *
 *  Created on: Aug 26, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <list>
using namespace std;

void addParen (int left, int right, char str[], list<string> &lst, int index)
{
	if (left == 0 && right == 0)
	{
		cout << str << endl;
		lst.push_back (str);
		return;
	}
	else
	{
		if (left > 0)
		{
			str [index] = '(';
			cout << "Left check =" << str << " left=" << left << " right=" << right << " index=" << index << endl;
			addParen (left-1, right, str, lst, index+1);
		}

		if (right > left)
		{
			str[index] = ')';
			cout << "Right check =" << str << " left=" << left << " right=" << right << " index=" << index << endl;
			addParen (left, right - 1, str, lst, index+1);
		}
	}

}

int main ()
{
	int n = 2;
	char str[n*2];
	list<string> lst;
	addParen (n, n, str, lst, 0);

	for (list<string>::iterator it = lst.begin(); it != lst.end(); ++it)
	{
		cout << *it << " ";
	}
}



