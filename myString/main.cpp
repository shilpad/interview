/*
 * main.cpp
 *
 *  Created on: Jul 21, 2014
 *      Author: rudolpharaujo
 */

//29.	Design MyString class interface: constructor, indexOf and concat.
#include <iostream>
using namespace std;

// Implement rest
//.,,http://www-cs-students.stanford.edu/~wolfe/cpp/Mystring.cpp


class myString
{
private:
	char*	ptrString;
public:
	myString (const char* string);
	~myString ();

	int indexOf (char ch);
	const char* concat (const char* toConcat);

	void print ();
};

myString::myString (const char *string)
{
	ptrString = new char [strlen (string) + 1];
	strcpy (ptrString, string);
}

myString::~myString()
{
	delete []ptrString;
}

void myString::print ()
{
	cout << ptrString;
}

int myString::indexOf (char ch)
{
	int index = 0;

	while (*(ptrString + index) != '\0')
	{
		if (*(ptrString + index ) == ch)
			return index;

		++index;
	}

	return -1;
}

const char* myString::concat (const char *add)
{
	int index = 0;
	int len = strlen (add);
	while (*(add + index) != '\0')
	{
		ptrString [len++] = *(add + index++);
	}

	return ptrString;
}

int main ()
{
	myString string ("abcd");
	string.print ();

	int index = string.indexOf ('a');
	cout << "\n Found at index " << index << endl;

	const char* final = string.concat ("def");
	cout << "New string " << final << endl;

}

