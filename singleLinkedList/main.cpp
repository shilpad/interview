/*
 * main.cpp
 *
 *  Created on: Jul 17, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include "SingleLInkedList.h"
using namespace std;

int main ()
{
	SingleLInkedList objList;

	objList.add (5);
	objList.add (6);
	objList.add (7);
	objList.add (10);
	objList.add (1);

	objList.print();

	/*objList.remove(1);
	objList.print();

	objList.remove(5);
	objList.print();

	objList.remove(10);
	objList.print();

	objList.remove(7);
	objList.print();

	objList.remove(6);
	objList.print ();*/

	if (false == objList.remove(100))
		cout << "element does not exist in the list\n";

	objList.reverse ();
	objList.print();

	objList.sort();
	cout << "After sorting .....\n";
	objList.print();

	objList.getNthNodeFromLast(4);

}





