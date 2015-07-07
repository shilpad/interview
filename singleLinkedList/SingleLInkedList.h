/*
 * SingleLInkedList.h
 *
 *  Created on: Jul 17, 2014
 *      Author: rudolpharaujo
 */

#ifndef SINGLELINKEDLIST_H_
#define SINGLELINKEDLIST_H_

typedef struct Node
{
	int data;
	struct Node *next;
}Node;

class SingleLInkedList {
private:
	Node *head;
	Node *tail;

public:
	SingleLInkedList();
	virtual ~SingleLInkedList();

	bool add (int data);

	bool remove (int data);

	void print ();

	void reverse ();

	bool sort ();

	int getNthNodeFromLast (const int &n);
};

#endif /* SINGLELINKEDLIST_H_ */
