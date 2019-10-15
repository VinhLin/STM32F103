/*
 * ChecksumXOR.h
 *
 *  Created on: Oct 10, 2019
 *      Author: Home_Premium
 */

#ifndef CHECKSUMXOR_H_
#define CHECKSUMXOR_H_

//.................../*Define*/.......................

typedef unsigned int KQ;

struct Data
{
	char data[128];
	char CheckXOR[2];
}s;

//....................../*Function prototypes*/........................

extern void valueChecksum(char *array, char *readData, char *findChecksum);
extern KQ compareChecksum(char *array);

#endif /* CHECKSUMXOR_H_ */
