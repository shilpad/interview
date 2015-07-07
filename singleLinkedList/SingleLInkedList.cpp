/*
 * SingleLInkedList.cpp
 *
 *  Created on: Jul 17, 2014
 *      Author: rudolpharaujo
 */
#include <stddef.h>
#include "SingleLInkedList.h"
#include <iostream>

using namespace std;

SingleLInkedList::SingleLInkedList() {
	// TODO Auto-generated constructor stub
	head = tail = NULL;
}

SingleLInkedList::~SingleLInkedList() {
	// TODO Auto-generated destructor stub
	Node *tmp = head;

	while (head)
	{
		head = tmp->next;
		delete tmp;
		tmp = head;
	}

}

bool SingleLInkedList::add (int data)
{
	// Create a new node
	Node* tmp = new Node();
	if (!tmp) return false;

	tmp->data = data;
	tmp->next = NULL;

	// Check if its an empty list
	if (head == NULL)
		head = tail = tmp;
	else
	{
		tmp->next = head;
		head = tmp;
	}

	return true;
}

bool SingleLInkedList::remove (int data)
{
	Node* tmp = head;

	if (head == NULL)
		return false;

	// special case for head
	if (head->data == data)
	{
		head = head->next;
		delete tmp;
	}
	else
	{
		Node *trail = tmp;
		tmp = tmp->next;

		while (tmp)
		{
			if (tmp->data == data)
			{
				trail->next = tmp->next;
				delete tmp;
				return true;
			}

			trail = tmp;
			tmp = tmp->next;
		}
	}

	return false;
}

void SingleLInkedList::reverse ()
{
	Node *trail = NULL;
	Node * tmp = NULL;

	tmp = head;
	tail = head;

	while (head)
	{
		head = tmp->next;
		tmp->next = trail;
		trail = tmp;
		tmp = head;
	}

	head = trail;
}

bool SingleLInkedList::sort ()
{
	// selection sort - O(n^2)

	if (head == NULL)
		return false;

	Node *first = head;
	Node *second = NULL;

	int min = 0;
	while (first)
	{
		min = first->data;
		second = first->next;
		while (second)
		{
			if (second->data < min)
			{
				// swap data
				int tmp = first->data;
				first->data = second->data;
				second->data = tmp;
			}
			second = second->next;
		}
		first = first->next;
	}

	return true;
}

int SingleLInkedList::getNthNodeFromLast (const int &n)
{
	Node *tmp = head;
	Node *ptrFound = NULL;
	int counter = 0;

	while (tmp)
	{
		++counter;
		if (counter - n == 0)
		{
			ptrFound = head;
		}
		else if (counter - n > 0)
		{
			ptrFound = ptrFound->next;
		}

		tmp = tmp->next;
	}

	if (ptrFound == NULL)
		return 0;
	else
	{
		cout << n << " node from the last is " << ptrFound->data;
		return ptrFound->data;
	}
}

void SingleLInkedList::print ()
{
	Node *tmp = head;
	cout << "print\n";

	while (tmp)
	{
		cout << tmp->data << "->";
		tmp = tmp->next;
	}

	cout << endl;
}




