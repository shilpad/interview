/*
 * main.cpp
 *
 *  Created on: Jul 14, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
using namespace std;

char * strstr (const char* source, const char* target)
{
	if (!*target) return (const_cast<char*>(source));

	char* p1 = (char*)source;

	while (*p1)
	{
		char *p1Begin = p1, *p2 = (char*)target;
		while (*p1 && *p2 && *p1 == *p2)
		{
			++p1;
			++p2;
		}

		if (!*p2)
			return p1Begin;

		p1++;// = p1Begin + 1;
	}

	return NULL;
}

int main ()
{
	char strSource [] = "This is a simple string";

	char *pstr = strstr (strSource, "simple");
	cout << pstr << endl;
}
