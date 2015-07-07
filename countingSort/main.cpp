/*
 * main.cpp
 *
 *  Created on: Aug 10, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;
#define RANGE 255

// The main function that sort the given string str in alphabatical order
void countSort(char *str)
{
    // The output character array that will have sorted str
    char output[strlen(str)];

    // Create a count array to store count of inidividul characters and
    // initialize count array as 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    cout << "1----\n";
    // Store count of each character
    for(i = 0; str[i]; ++i)
    {
        ++count[str[i]];
        cout << "str[i]=" << str[i] << " " << count [str[i]] << "\n";
    }

    cout << "2----\n";
    // Change count[i] so that count[i] now contains actual position of
    // this character in output array
    for (i = 1; i <= RANGE; ++i)
    {
        count[i] += count[i-1];
        cout << count [i] << ",";
    }
    cout << endl;

    cout << "3----\n";
    // Build the output character array
    for (i = 0; str[i]; ++i)
    {
        output[count[str[i]]-1] = str[i];
        --count[str[i]];
        cout << count [str[i]] << ",";
    }
    cout << endl;

    // Copy the output array to str, so that str now
    // contains sorted characters
    for (i = 0; str[i]; ++i)
        str[i] = output[i];
}


int main()
{
    char str[] = "geeksforgeeks";//"applepp";

    countSort(str);

    printf("Sorted string is %s\n", str);
    return 0;
}

