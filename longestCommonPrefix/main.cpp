/*
 * main.cpp
 *
 *  Created on: Aug 8, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

string longestCommonPrefix (string arr[], int size)
{
	if (size == 0)
		return "";

	for (int index=0; index < arr[0].length(); ++index)
	{
		char ch = arr[0].at (index);
		for (int wIndex=1; wIndex < size; ++wIndex)
		{
			if (index > arr[wIndex].length() || arr[wIndex].at(index) != ch)
				return arr[wIndex].substr (0, index);
		}
	}

	return arr[0];
}

/*
 * sizeof(string)
will give you the amount of space that a string object takes up on the stack on your particular platform,
that is, the amount of space that string objects are guarunteed to take up, even before you put any characters into them.
 */

int main ()
{
	string arr[] = {"abc", "abcd", "abcde"};
	int size = sizeof(arr)/sizeof (arr[0]);

	cout << size << " " << sizeof(arr) << " " << sizeof(arr[0]) << endl;

	string lcp = longestCommonPrefix (arr, size);
	cout << "LCP=" << lcp << endl;
}



