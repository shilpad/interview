/*
 * main.cpp
 *
 *  Created on: Jun 27, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <list>
using namespace std;


void doPermute (string in, string out, bool used[], int length, int level)
{
	static int iteration = 1;
	cout << "*Iteration " << iteration++ << endl;
	cout << "in:" << in << " out:" << out << " level:" << level << " used=";
	for (int i=0; i <length; ++i)
		cout << used[i] << ",";

	cout << endl;


	if (level == length)
	{
		cout << "--------" << out << endl;
		return;
	}

	for (int i = 0; i < length; ++i)
	{
		if (used [i]) continue;

		out += in[i];
		used[i] = true;
		doPermute (in, out, used, length, level + 1);
		used[i] = false;

		cout << "used=";
		for (int i=0; i <length; ++i)
			cout << used[i] << ",";

		cout << "\nBefore removing last character = " << out << endl;
		out [out.length()-1] = '\0';
		cout << "After removing last character = " << out << endl;
	}
}

string insertCharAt (string &word, char ch, int pos)
{
	string start = word.substr (0, pos);
	string end = word.substr (pos);
	return (start + ch + end);
}

list<string> getPerms (string in)
{
	cout << "in=" << in << endl;

	list<string> permutations;

	if (in.length() == 0) // base case
	{
		permutations.push_back("");
		return permutations;
	}

	char first = in[0];
	cout << "first=" << first << endl;
	string remainder = in.substr(1);
	cout << "remainder=" << remainder << endl;
	list<string> words = getPerms (remainder);
	for (list<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		string word = *it;
		cout << "word=" << word << endl;
		for (int j = 0; j <= word.length(); ++j)
		{
			string s = insertCharAt (word, first, j);
			permutations.push_back(s);
		}
	}

	return permutations;
}

int main () {

	string  in("abcd");

	/*int length = in.length();

	//bool *used = new bool(length);
	bool used [length];

	// initialize used array
	for (int i = 0; i < length; i++)
	{
		used [i] = false;
	}

	string out;

	doPermute (in, out, used, length, 0);*/

	//delete used;

	// Method 2
	list<string> words = getPerms (in);

	for (list<string>::iterator it = words.begin(); it != words.end(); ++it)
	{
		cout << *it << endl;
	}

	return 0;
}
