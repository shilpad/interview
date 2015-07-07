/*
 * main.cpp
 *
 *  Created on: Aug 22, 2014
 *      Author: rudolpharaujo
 */

#include <stack>
#include <iostream>

using namespace std;

class Tower
{
	private:
		stack<int> disks;

	public:

		void moveTopTo (Tower tower)
		{
			int i = disks.top();
			disks.pop ();


			tower.add (i);
		}

		void add (int n)
		{
			if (!disks.empty() && disks.top() <= n)
			{
				printf ("Error placing disk %d\n", n);
			}
			else
				disks.push(n);
		}

		void moveDisks (int n, Tower destination, Tower buffer)
		{
			if (n > 0)
			{
				// move top n-1 disks from origin to buffer, using destination as buffer
				moveDisks (n - 1, buffer, destination);

				// move top from source to destination
				moveTopTo (destination);

				// move top n-1 from buffer to destination using source as buffer
				buffer.moveDisks (n - 1, destination, *this);
			}
		}
};


int main ()
{
	Tower one, two, three;
	one.add (5);
	one.add (4);
	one.add (3);
	one.add (2);
	one.add (1);

	one.moveDisks (3, two, three);
}
