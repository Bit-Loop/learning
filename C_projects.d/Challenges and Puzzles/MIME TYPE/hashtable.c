/* ITJ hashtable.c, created on 09/18/21, last change 09/24/21
* REFs are in hashtable.h
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "hashtable.h"

void printBucket(bucket_ts* drip) {
	int bucketIndex = 0;
	printf("FName ");
	if (drip == NULL) printf("____\tEXT ____");
	else {
	bucketIndex = hash(&drip->key);
	printf("Bucket %0x\t", bucketIndex);
	bucket_ts* tempBucket = buckets[bucketIndex];
	bool dash = 0;
	while (tempBucket != NULL) {
		printf("FName: ");
		printf("\"%s\"\t", tempBucket->key);
		printf("EXT ");
		printf("%s\t", tempBucket->ext_pair);
		dash = true;
		tempBucket = tempBucket->next;
		printf(" ----<next>  ");
		}
		
		printf("\n");
	}
}

void printAllBuckets() {
	for (int i = 0; i <= TABLE_SIZE; ++i) {
		if (buckets[i] != NULL) printBucket(buckets[i]);
	}
}

void initBuckets() {
	for (int i = 0; i <= TABLE_SIZE; ++i) {
		buckets[i] = NULL;
	}
}

 unsigned int hash(char* drip) {
	 if (drip == NULL) return NULL;
	unsigned long int tempCount = 1;
	int inputLen = sizeof(drip);
	for (int i = 0; i <= inputLen; ++i) {
		tempCount += drip[i] * inputLen +1;
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
	 int tempIndex = hash(&drip->key);
	 drip->next = buckets[tempIndex];
	 buckets[tempIndex] = drip;
	 return true;
 }

 bucket_ts* htLookUp(char* drip) {
	if (drip == NULL) {
		 printf("\n\nThat string is NULL!\n\n");
		 return false;
	}
	 printf("htLookUP Char Drip = %s\n", drip);
	 bucket_ts test = { .key = "", .ext_pair = ""};
	 strcpy(test.key, drip);
	int tempIndex = hash(test.key);
	bucket_ts* tempBucket = buckets[tempIndex];
	int try = 0;
	while ((tempBucket != NULL) && strncmp(tempBucket->key, drip, sizeof(tempBucket->key)) !=0 ) {
		if (tempBucket->next == NULL) break;
		else tempBucket = tempBucket->next;
	}
	printBucket(tempBucket);
	return tempBucket;
}

 bucket_ts* htDel(char* drip) {
	 if (drip == NULL) {
		printf("\n\nThat string is NULL!\n\n");
		return NULL;
	}
	int tempIndex = hash(drip);
	bucket_ts* tempBucket = buckets[tempIndex];
	bucket_ts* prevBucket = NULL;
	int try = 0;
	while ((tempBucket != NULL) && strncmp(tempBucket->key, drip, 51) != 0) {
		prevBucket = tempBucket;
		tempBucket = tempBucket->next;
	}
	if (tempBucket == NULL) return NULL;
	if (prevBucket == NULL) {
		buckets[tempIndex] = tempBucket->next;
	}	else {
			prevBucket->next = tempBucket->next;
		}
	return tempBucket;
}
