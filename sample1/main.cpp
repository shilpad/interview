/*
 * main.cpp
 *
 *  Created on: Jul 14, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
using namespace std;


class Foo {
public:
	int *ptr;
	Foo (int i) {
		ptr = new int(i);
		cout << "constructor\n";
	}

	~Foo ()
	{
		delete ptr;
		cout << "destructor\n";
	}

	int printVal ()
	{
		cout << "inside printVal" << *ptr << "\n";
		return *ptr;
	}
};


void SomeFunc (Foo obj) // changing this to pass by reference fixes the issue - the destructor does not get called while leaving SomeFunc
{
	cout << "Inside SomeFunc... calling printVal\n";
	int x = obj.printVal ();
}


int main ()
{
	Foo obj = 15;
	SomeFunc (obj);
	obj.printVal ();
 }
