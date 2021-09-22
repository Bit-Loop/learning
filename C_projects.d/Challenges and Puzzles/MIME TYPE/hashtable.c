/* ITJ hashtable.c, created on 09/18/21, last change 09/18/21
* REFs are in hashtable.h
*
*/

#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"
#define TABLE_SIZE 10000

struct bucket {
	int ext;
};

struct bucket buckets[TABLE_SIZE + 1];

int returnBucket(int x) {
	//for (int i = 0; i <= TABLE_SIZE; ++i) printf("i: %d \tbucketVal: %d\n", i, buckets[i].ext);
	return buckets[x].ext;
}

void initHash() {
	for (int i = 0; i <= TABLE_SIZE; ++i) {
		buckets[i].ext = i;
	}
}

unsigned long int hash(char* inputChar) { 
	int inputLen = sizeof(inputChar);
	unsigned long int tempCount = 0;
	for (int i = 0; i <= inputLen; ++i) {
		tempCount += inputChar[i] * i;
	}
	return tempCount % TABLE_SIZE;
}

