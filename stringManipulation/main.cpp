/*
 * main.cpp
 *
 *  Created on: Jul 17, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

/*void reverseString (string toReverse, int len)
{
	int start = 0;
	int end = len - 1;

	while (start < end)
	{
		char ch = toReverse [start];
		toReverse[start] = toReverse[end];
		toReverse[end] = ch;
		++start; --end;
	}

	cout << "After reversing: " << toReverse << endl;
}*/

void reverseString (char *pStart, int len)
{
	char *pSave = pStart;
	char *pEnd = pStart + (len-1);

	while (pStart < pEnd)
	{
		char ch = *pStart;
		*pStart = *pEnd;
		*pEnd = ch;
		++pStart; --pEnd;
	}

	for (int i = 0; i < len; ++i)
	{
		cout << *pSave;
		pSave++;
	}
	cout << endl;
}

void toUpper (char *string)
{
	char *head = string;

	while (*string != 0)
	{
		*string = ((*string >= 'a' && *string <= 'z') ? (*string - 'a' + 'A') : *string);
		string++;
	}

	cout << "After converting to uppercase " << head << endl;

}

char* lastInstanceOfChar (char* string, char chFind)
{
	int index=0;
	char *pStr= NULL;

	while ((*(string + index)) != '\0')
	{
		if (*(string + index) == chFind )
			pStr = (string + index);

		++index;
	}

	if (pStr == NULL)
		pStr = "lastInstanceOfChar::Character not found";

	return pStr;
}

void checkStringForBrackets (const char* strBrackets)
{
	const char* ptrTraverse = strBrackets;
	int count = 0;

	while (*ptrTraverse != '\0')
	{
		if (*ptrTraverse == '(')
			++count;
		else if (*ptrTraverse == ')')
			--count;

		++ptrTraverse;
	}

	if (count != 0 )
		cout << "The brackets dont match !\n";
	else
		cout << "The brackets match ! \n";
}

int main ()
{
	string sentence;
	cout << "Enter a sentence to reverse:";
	getline (cin, sentence);

	char *ptrS = (char*)sentence.c_str();
	reverseString (ptrS, sentence.length());
	cout << "Sentence reverse =" << sentence.c_str() << endl;

	int len = 0;
	char* word = (char*)sentence.c_str();

	cout << "sentence length = " << sentence.length() << "\n";

	for (int i = 0; i < sentence.length(); ++i)
	{
		if ((sentence[i] == ' ') || (sentence[i] == '\0'))
		{
			reverseString (word, len);
			word = &sentence [i+1];// or try word+i
			len=0;
		}
		else
			++len;
	}

	cout << "Word by word reverse  =" << sentence.c_str() << endl;

	char str[] = "abcdedxz";

	char* ch = lastInstanceOfChar (str, 'd');
	cout << ch << endl;

	toUpper (str);

	const char* strBrackets = "((((((()()))";
	checkStringForBrackets (strBrackets);
}


