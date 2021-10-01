/* ITJ hashtable.c, created on 09/18/21, last change 09/24/21
* REFs are in hashtable.h
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "hashtable.h"

int returnBucket(int x) {

	return buckets[x]->key;
}

void printBucket(unsigned int bucketNumber) {
	printf("Bucket %0x\t", bucketNumber);
	printf("FName ");
	if (buckets[bucketNumber] == NULL) printf("____\tEXT ____");
	else {
		printf("\"%s\"\t", buckets[bucketNumber]->key);
		printf("EXT ");
		if (buckets[bucketNumber] == NULL) printf("____\t");
		else printf("%s\t", buckets[bucketNumber]->ext_pair);
	}
	printf("\n");
}

void printAllBuckets() {
	for (int i = 0; i <= TABLE_SIZE; ++i) {
		if (buckets[i] != NULL) printBucket(i);
	}
}


void initBuckets() {
	for (int i = 0; i <= TABLE_SIZE; ++i) {
		buckets[i] = NULL;
	}
}

volatile unsigned int hash(bucket_ts* drip) {
	unsigned long int tempCount = 1;
	int inputLen = sizeof(drip->key);
	for (int i = 0; i <= inputLen; ++i) {
		tempCount += drip->key[i] * inputLen +1;
	}
	printf("Hash() => %0x\n", (tempCount % TABLE_SIZE));
	return tempCount % TABLE_SIZE;
}

// Hash Table Insert = htInsv
 bool htIns(bucket_ts* drip) {
	if (drip == NULL) {
		printf("\n\nCan not insert NULL bucket!\n\n");
		return false;
	}

	int tempIndex = hash(drip);

	if (buckets[tempIndex]->key != NULL) { 
		puts("Error: Hash INS conflict"); 
		return false;
	}
	else {
		buckets[tempIndex] = drip;
		return true;
	}
}

 bucket_ts* htLookUp(bucket_ts* drip) {
	 if (drip == NULL) {
		 printf("\n\nThat bucket is empty!\n\n");
		 return false;
	 }
	 int tempIndex = hash(drip);
	 if (buckets[tempIndex]->key != NULL) {
		 puts("Error: Hash INS conflict");
		 return false;
	 }
	 else {
		 return buckets[tempIndex];
	 }
 }


void humanTest() {
	puts("start");
	initBuckets();
	bucket_ts testDrip = { .key = "foo", .ext_pair = "bar" };
	printBucket(hash(&testDrip));
	puts("Attempt Insert bucket value to hash table.");
	htIns(&testDrip); //pass by refrence
	printBucket(hash(&testDrip));
	puts("Attempt to reinsert the same value to to hash table.");
	htIns(&testDrip); //pass by refrence
	puts("end");
	puts("print all buckets (that are not null)");
	printAllBuckets();
}







