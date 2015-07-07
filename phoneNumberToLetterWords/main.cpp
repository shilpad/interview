/*
 * main.cpp
 *
 *  Created on: Jul 21, 2014
 *      Author: rudolpharaujo
 */


/*
 * 		Algorithm
 * 		1.	Construct the starting word by mapping 1st letter to the phone digit
 * 			1.e.
 * 			for (i = 0 to 7)
 * 			result [i] = getCharKey (phoneNumber [i], 1);
 * 		2.	Start an infinite loop
 * 			if (# of chars in the result == # digits in the phone number)
 * 				print it out
 *
 * 		3. for (i = 7; i >= -1; --i)
 * 			{
 * 				3.1	If the first letter has reset then we are done i.e. if if i == -1 return;
 *
 * 				3.2 if getCharKey (phoneNumber[i], 3) = 0 or 1 or 	same as result [i] (i.e. we have gone through all 3 chars for a digit)
 * 					// do nothing i.e. loop continues
 * 				else if getCharKey(phoneNumber[i],1) == result [i]
 * 					result [i] = getCharKey (phoneNumber [i], 2);
 * 					break;
 * 				else if (getCharKey (phoneNumber [i], 2) == result [i])
 * 					result [i ] = getCharKey (phoneNymber [i], 3);
 					break;
 	 	 	 }
 */


