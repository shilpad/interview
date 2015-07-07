/*
 * main.cpp
 *
 *  Created on: Aug 8, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
using namespace std;

struct node {
	node *next;
	int value;
};

int countNodes (node *head)
{
	int count = 0;
	node *temp = head;
	while (temp != NULL)
	{
		++count;
		temp = temp->next;
	}

	return count;
}

int findIntersection (int d, node *head1, node *head2)
{
	node *tmpHead1 = head1;
	node *tmpHead2 = head2;

	// Traverse d nodes in first list
	for (int i = 0; i < d; ++i)
		tmpHead1 = tmpHead1->next;

	while (tmpHead1 != NULL)
	{
		// Traverse both the lists and compare values along the way
		if (tmpHead1->value == tmpHead2->value)
			return tmpHead1->value;

		tmpHead1 = tmpHead1->next;
		tmpHead2 = tmpHead2->next;
	}

	return -1;
}

int findIntersection (node *head1, node *head2)
{
	int c1 = countNodes (head1);
	int c2 = countNodes (head2);

	int d;

	if (c1 > c2)
	{
		d = c1 - c2;
		return (findIntersection (d, head1, head2));
	}
	else
	{
		d = c2 - c1;
		return (findIntersection (d, head2, head1));
	}
}

int main ()
{
	  /*
	    Create two linked lists

	    1st 3->6->9->15->30
	    2nd 10->15->30

	    15 is the intersection point
	  */


	node *head1 = new node ();
	head1->value = 3;

	head1->next = new node ();
	head1->next->value = 6;

	head1->next->next = new node ();
	head1->next->next->value = 9;

	node *head2 = new node ();
	head2->value = 10;

	head2->next = new node ();
	head2->next->value = 15;

	head1->next->next->next = head2->next;

	head2->next->next = new node ();
	head2->next->next->value = 30;

	head2->next->next->next = NULL;

	cout << "Intersection point between 2 linked lists is " <<  findIntersection (head1, head2) << endl;

}




