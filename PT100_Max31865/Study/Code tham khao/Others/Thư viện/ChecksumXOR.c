/*
 * ChecksumXOR.c
 *
 *  Created on: Oct 10, 2019
 *      Author: Home_Premium
 */

#include "ChecksumXOR.h"
#include "dbgPrint.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

//.................../*VARIABLES*/......................


//........................./*Function*/........................

//Function read value checksum of data
void valueChecksum(char *array, char *readData, char *findChecksum)
{
	int count, dola, sao;
	unsigned int xor = 0;

	for (int k=0; k < strlen(array); k++) {
		if (strncmp(&array[k], "$", 1) == 0) {
			dola = k;
		}
		if (strncmp(&array[k], "*", 1) == 0) {
			sao = k;
			break;
		}
	}
	count = sao - dola;
	memcpy(readData, &array[dola + 1], count - 1);

	for (int i=0; i < strlen(readData); i++)
	{
		xor ^=  readData[i];
	}

	//Convert dec to hex
	sprintf(findChecksum, "%02x", xor);
}

KQ compareChecksum(char *array)
{
	int count, sao;
	char checksum[3];
	int result;

	memset(s.data, 0, 128);
	memset(s.CheckXOR, 0, 2);
	memset(checksum, 0, 3);

	valueChecksum(array, s.data, s.CheckXOR);

	for (int k=0; k < strlen(array); k++) {
		if (array[k] == '*') {
			sao = k;
		}
		if (array[k] == '\r') {
			count = k - sao;
			memcpy(checksum, &array[sao + 1], count - 1);
			break;
		}
	}

	//Compare if result = 1: Checksum true
	//If result = 0: Checksum false
	if (strcmp(checksum, s.CheckXOR) == 0) {
		result = 1;
	} else {
		result = 0;
	}

	return result;
}
