/* ITJ hashtable.c, created on 09/18/21, last change 09/18/21
* REFs are in hashtable.h
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "hashtable.h"

#define TABLE_SIZE 10000
#define FNAME_SIZE 257

typedef struct { 
	char fname[FNAME_SIZE];
	char ext[11];
} bucket_ts; //ts = typedef struct

bucket_ts *buckets[TABLE_SIZE + 1];

int returnBucket(int x) {

	return buckets[x]->fname;
}

void printBucket(unsigned int bucketNumber) {
	printf("Bucket %0x\t", bucketNumber);
	printf("FName ");
	if (buckets[bucketNumber] == NULL) printf("____\tEXT ____");
	else {
		printf("\"%s\"\t", buckets[bucketNumber]->fname);
		printf("EXT ");
		if (buckets[bucketNumber] == NULL) printf("____\t");
		else printf("%s\t", buckets[bucketNumber]->ext);
	}
	printf("\n");
}

void printAllBuckets() {
	for (int i = 0; i <= TABLE_SIZE; ++i) {
		printBucket(i);
	}
}



void initBuckets() {
	for (int i = 0; i <= TABLE_SIZE; ++i) {
		buckets[i] = NULL;
	}
}

unsigned int hash(bucket_ts* drip) {
	unsigned long int tempCount = 1;
	int inputLen = sizeof(drip->fname);
	for (int i = 0; i <= inputLen; ++i) {
		tempCount *= drip->fname[i] + 1;
	}
	printf("Hash() => %0x\n", (tempCount % TABLE_SIZE));
	return tempCount % TABLE_SIZE;
}

// Hash Table Insert = htIns
bool htIns(bucket_ts* drip) {
	if (drip == NULL) {
		printf("\n\nCan not insert NULL bucket!\n\n");
		return false;
	}
	int tempIndex = hash(drip->fname);
	if (buckets[tempIndex]->fname != NULL) { 
		puts("Error: Hash INS conflict"); 
		return false;
	}
	else {
		buckets[tempIndex] = drip;
		return true;
	}
}


void humanTest() {
	puts("start");
	initBuckets();
	bucket_ts testDrip = { .fname = "foo", .ext = "bar" };
	printBucket(hash(&testDrip));
	puts("Attempt Insert bucket value to hash table.");
	htIns(&testDrip); //pass by refrence
	printBucket(hash(&testDrip));
	puts("Attempt to reinsert the same value to to hash table.");
	htIns(&testDrip); //pass by refrence
	puts("end");

}







