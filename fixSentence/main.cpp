/*
 * main.cpp
 *
 *  Created on: Aug 19, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
#include <stdlib.h>
using namespace std;

int parseSimple(string sentence, int wordStart, int wordEnd)
{
	if (wordEnd >= sentence.length())
	{
		return wordEnd - wordStart;
	}

	string word = sentence.substr (wordStart, wordEnd + 1);

	/* break current word */
	int bestExact = parseSimple(sentence, wordEnd + 1, wordEnd + 1);
	if (!dictionary.contains(word, true))
	{
		bestExact += word.length();
	}

	/* extend current word */
	int bestExtend = parseSimple(sentence, wordStart, wordEnd + 1);
	/* find best */
	return Math.min(bestExact, bestExtend);
}


