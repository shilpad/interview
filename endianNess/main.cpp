/*
 * main.cpp
 *
 *  Created on: Jul 19, 2014
 *      Author: rudolpharaujo
 */
#include <iostream>
using namespace std;

/*In the above program, a character pointer c is pointing to an integer i. Since size of character is 1 byte when the character pointer
 * is de-referenced it will contain only first byte of integer.
 If machine is little endian then *c will be 1 (because last byte is stored first) and if machine is big endian then *c will be 0.
*/

bool endianness2 ()
{
	union {
		int theInteger;
		char singleByte;
	}endianTest;

	endianTest.theInteger = 1;

	// You need to typecast endianTest.singleByte as integer as cout << static_cast<unsigned>(endianTest.singleByte);. With this you will observe 1 on the output.
	// With cout << endianTest.singleByte;, the print will be SOH (Start of Heading) corresponding to ascii value of 1 which can't be printed and hence,
	// some special character is observed.

	cout << "endianness2 = "  << static_cast<unsigned int>(endianTest.singleByte) << "\n";

	return (endianTest.singleByte == 1);
}

bool endianness1 ()
{
	int num = 1;

	char *ptrch = (char*)(&num);

	// You need to typecast *ptrch as integer as cout << static_cast<unsigned>(*ptrch);. With this you will observe 1 on the output.
	// With cout << *ptrch;, the print will be SOH (Start of Heading) corresponding to ascii value of 1 which can't be printed and hence,
	// some special character is observed.


	cout << "Value at lowest memory address is = " <<  static_cast<unsigned>(*ptrch) << endl;

	if (*ptrch == 0)
		cout << "Machine is big-endian since the MSB of 1 i.e. 0 is at the lowest address\n";
	else if (*ptrch == 1)
		cout << "Machine is little-endian since the LSB of 1 i.e. 1 is at the lowest address\n";

	return *ptrch;
}

// Endianness refers to the order in which computer stores bytes of a multibyte byte.
// In a big-endian machine, MSB has the lowest address
// In a little-endian machine the LSB has the lowest address
int main ()
{
	cout << "size of int " << sizeof(int) << endl;

	if (1 == endianness1 ())
		cout << "LSB is 1 i.e. LSB is at the lowest address. So the machine uses little-endian\n";
	else
		cout << "LSB is 1 i.e. LSB is at the lowest address. So the machine uses big-endian\n";

	if (1 == endianness2 ())
		cout << "LSB is 1 i.e. LSB is at the lowest address. So the machine uses little-endian\n";
	else
		cout << "LSB is 1 i.e. LSB is at the lowest address. So the machine uses big-endian\n";
}



