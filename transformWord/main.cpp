/*
 * main.cpp
 *
 *  Created on: Aug 10, 2014
 *      Author: rudolpharaujo
 */

#include <iostream>
#include <set>
//#include <vector>
using namespace std;

/*transform(english_words, 'damp', 'like'):
['damp', 'lamp', 'limp', 'lime', 'like']
['damp', 'camp', 'came', 'lame', 'lime', 'like']
*/

bool isValid (string strWord)
{
	set <string> setValidWords;

	setValidWords.insert("like");
	setValidWords.insert("came");
	setValidWords.insert("lime");
	setValidWords.insert("limp");
	setValidWords.insert("lamp");
	setValidWords.insert("damp");
	setValidWords.insert("camp");
	setValidWords.insert("lame");

	if (setValidWords.find(strWord) != setValidWords.end())
		return true;
	else
		return false;
}

void transformWord (int index, char chStart, string strSrc, set<string> setFinal, string strTarget)
{
	bool bTargetReached = false;
	//set<string>::iterator it= setSrc.begin();
	for (int i = index; i < strSrc.length(); ++i)
	{
		for (char ch = chStart; ch <= 'z'; ++ch)
		{
			strSrc [i] = ch;
			cout << "strSrc=" << strSrc << endl;
			if (isValid (strSrc))
			{
				cout << strSrc << " is Valid!\n";
				setFinal.insert (strSrc);

				if (strSrc == strTarget)
				{
					bTargetReached = true;
					set<string>::iterator itlocal;
					// print the entire vector
					for (itlocal = setFinal.begin(); itlocal != setFinal.end(); ++itlocal)
						cout << *itlocal << " ";

					cout << endl;
					return;
					// Find more paths leading to the same target
					// Reset i to 0 and start from (setSrc[0]).at(0)++
					i = -1;
					itlocal = setFinal.begin();

					chStart = (*itlocal).at(0);
					++chStart;
					//transformWord (0, ++ch, *itlocal, setFinal, strTarget);
				}

				break;
				// Keep moving to the next index and finding a letter that makes a valid word
				// thus taking us closer to the target
				//transformWord (++i, 'a', strSrc, setFinal, strTarget);
			}
		}

		cout << bTargetReached << " " << i << " " << strSrc.length () << endl;
		if (bTargetReached == false && (i + 1) == strSrc.length())
		{
			cout << "Hereeeeee\n";
			// reset starting points
			i = -1;

			set<string>::iterator itlocal = setFinal.begin();
			chStart = (*itlocal).at(0);
			++chStart;
		}
	}


}

int main ()
{
	set<string> setFinal;
	setFinal.insert ("damp");

	string strTarget = "like";

	transformWord (0, 'a', "damp", setFinal, strTarget);
}

