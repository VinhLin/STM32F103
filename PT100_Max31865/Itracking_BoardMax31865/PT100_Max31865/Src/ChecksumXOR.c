/*
 * ChecksumXOR.c
 *
 *  Created on: Oct 10, 2019
 *      Author: Home_Premium
 */

#include "ChecksumXOR.h"
#include "dbgPrint.h"
#include "string.h"

//.................../*VARIABLES*/......................


//........................./*Function*/........................
// function to convert decimal to hexadecimal
void decToHexa(int n, char *findChecksum)
{
	char hex[2];
    // char array to store hexadecimal number
    char hexaDeciNum[2];
    // counter for hexadecimal number array
    int i = 0, count = 0;
    while(n!=0)
    {
        // temporary variable to store remainder
        int temp  = 0;
        // storing remainder in temp variable.
        temp = n % 16;
        // check if temp < 10
        if(temp < 10)
        {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else
        {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
        n = n/16;
    }
	//cout << "i: " << i << endl;
    // printing hexadecimal number array in reverse order
    for(int j=i-1; j>=0; j--) {
        //cout << hexaDeciNum[j];
		hex[count] = hexaDeciNum[j];
		count++;
	}

	//cout << endl << "Hex: " << hex << endl;
	strcpy(findChecksum, hex);
}

//Function read value checksum of data
void valueChecksum(char *array, char *readData, char *findChecksum)
{
	int count = 0, index = 0, count1 = 0, i;
	char lhs[128];
	unsigned int xor = 0;

	memset(lhs, 0, 128);

	for (int k=0; k < strlen(array); k++) {
		count++;
		if (strncmp(&array[k], "A", 1) == 0) {
			for (int i=count; array[i] != '\n'; i++)
			{
				index ++;
				memcpy(lhs, array+(count-1), index);
			}
			break;
		}
	}
//	DBG_print("lhs: %s", lhs);

	for (int j=1; lhs[j] != 0; j++)
	{
		count1++;
		if (lhs[j] == '*')
		{
			memcpy(readData, lhs + 1, count1 - 1);
		}
	}

	for (i=0; i < strlen(readData); i++)
	{
		xor ^=  readData[i];
	}
	//cout << "xor: " << hex << xor << endl;
	decToHexa(xor,findChecksum);
}

KQ compareChecksum(char *array)
{
	int count = 0, index = 0, count1 = 0, count2;
	char lhs[128];
	char checksum[16];
	int Num_checksum, Num_checkxor, result;

	 memset(s.data, 0, 128);
	 memset(s.CheckXOR, 0, 2);
	 memset(lhs, 0, 128);
	 memset(checksum, 0, 16);

	valueChecksum(array, s.data, s.CheckXOR);

	for (int k=0; k < strlen(array); k++) {
		count++;
		if (strncmp(&array[k], "A", 1) == 0) {
			for (int i=count; array[i] != '\n'; i++)
			{
				index ++;
				memcpy(lhs, array+(count-1), index);
			}
			break;
		}
	}
	for (int j=1; lhs[j] != 0; j++)
	{
		count1++;
		if (lhs[j] == '*')
		{
			count2 = count1;
		}
	}
	memcpy(checksum, lhs + count2 + 1, count1);

	//Convert string to number
	Num_checksum = atol (checksum);
	Num_checkxor = atol (s.CheckXOR);

	//Compare if result = 1: Checksum true
	//If result = 0: Checksum false
	if (Num_checksum == Num_checkxor) {
		result = 1;
	} else {
		result = 0;
	}

	return result;
}
