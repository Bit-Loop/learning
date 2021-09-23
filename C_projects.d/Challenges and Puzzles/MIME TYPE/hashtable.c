/* ITJ hashtable.c, created on 09/18/21, last change 09/18/21
* REFs are in hashtable.h
*
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "hashtable.h"

#define TABLE_SIZE 10
#define FNAME_SIZE 257

typedef struct { 
	char fname[FNAME_SIZE];
	char ext[11];
} bucket;

bucket buckets[TABLE_SIZE + 1];

int returnBucket(int x) {

	return buckets[x].fname;
}

void printAllBuckets() {
	for (int i = 0; i <= TABLE_SIZE; ++i) {
		printf("Bucket %0x\t", i);
		printf("FName ");
		if (buckets[i].fname == "") printf("----\t");
		else printf("%s\t", buckets[i].ext);
		printf("EXT ");
		if (buckets[i].ext == "") printf("----\t");
		else printf("%s\t", buckets[i].ext);
		printf("\n");
	}
}

void initBuckets() {
	for (int i = 0; i <= TABLE_SIZE; ++i) {
		strcpy(buckets[i].ext, "");
		strcpy(buckets[i].fname, "");
	}
}

unsigned int hash(char* inputChar) { 
	unsigned long int tempCount = 1;
	int inputLen = sizeof(inputChar);
	for (int i = 0; i <= inputLen; ++i) {
		tempCount *= inputChar[i] + 1;
	}
	printf("Hash(): tempCount %% TABLE_SIZE ==> %d\n", (tempCount % TABLE_SIZE));
	return tempCount % TABLE_SIZE;
}

bool hashIns(char* inputChar) {
	if (inputChar == NULL) {
		printf("\n\ninput string is null!\n\n");
		return false;
	}
	int tempIndex = hash(inputChar);
	if (buckets[tempIndex].fname != NULL) { 
		puts("Error: Hash INS conflict"); 
		//return false;
	} //else if ((buckets[tempIndex]->fname == NULL)) {
		puts("well something ran.");
		strcpy(buckets[tempIndex].fname, inputChar);
		return 1;
	//} 
}


void humanTest() {
	initBuckets();
	printAllBuckets();
	bucket val = { .ext = "foo", .fname = "bar" };
	strcpy(buckets[0].fname, val.ext);
	strcpy(buckets[1].fname, val.fname);
	printf("\nBucket 0 FNAME %s\t", buckets[0].fname);
	printf("Bucket 1 FNAME %s", buckets[1].fname);
	printAllBuckets();
	//initHash();
	char tempInput[257];
	int tempHash = 0;
	gets(tempInput);
	tempHash = hash(tempInput);
	printf("Hash # %x for %s\n", tempHash, tempInput);
	hashIns(tempInput);

}







