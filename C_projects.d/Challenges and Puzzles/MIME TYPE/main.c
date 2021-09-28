// ITJ 09/07/2021, Last change: 09/27/21
// codingame challege Mime Types
// Limit: 0 < N < 10000
// Limit: 0 < Q < 10000

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "hashtable.h"
#include "testdata.h"
//#include "hashtable.c"
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#define EXT_MT_TABLE_SIZE 20

void initBucket(bucket_ts* bucketPtr, char keyVal[257], char extVal[257]) {
    strcpy(bucketPtr->key, keyVal);
    strcpy(bucketPtr->ext_pair, extVal);
}

int main() {
    int Q = 0;
    int N = 0;

    struct extMt {
        char ext_pair[11];
        char mt[51];
    };
    struct extMt extMt_s[20] = { 0 };

    // ^^^^^^


    /*
    for (int i = 0; i < N; i++) {
        fprintf(stderr, "n %i\n", i + 1);
        scanf("%s%s", extMt_s[i].ext, extMt_s[i].mt); fgetc(stdin);
        fprintf(stderr, "EXT %s \t MT %s\n", extMt_s[i].ext, extMt_s[i].mt);
    }
    for (int i = 0; i <= N; ++i) {
        printf("#%d\t%s\t%s\n", i, extMt_s[i].ext, extMt_s[i].mt);
    }
    for (int i = 0; i < Q; i++) {
        // One file name per line.
        char FNAME[257];
       // scanf("%[^\n]", FNAME); fgetc(stdin);
    }
  */
#define MAX_SIZE 50
#define STR_SIZE 50
    FILE* mt_f;
    FILE* ext_f;
    FILE* fname_f;
    char* mtPath = "C:\\Users\\bitloop\\Documents\\GitHub\\learning\\C_projects.d\\Challenges and Puzzles\\MIME TYPE\\_mt.txt";
    char* extPath = "C:\\Users\\bitloop\\Documents\\GitHub\\learning\\C_projects.d\\Challenges and Puzzles\\MIME TYPE\\_ext.txt";
    char* fnamePath = "C:\\Users\\bitloop\\Documents\\GitHub\\learning\\C_projects.d\\Challenges and Puzzles\\MIME TYPE\\_fname.txt";
    char mt[STR_SIZE][MAX_SIZE] = { 0 };
    char ext[STR_SIZE][MAX_SIZE] = { 0 };
    char fname[STR_SIZE][MAX_SIZE] = { 0 };
    int mtNlCount = 0;
    int extNlCount = 0;
    int fnameNlCount = 0;
    //
    N = mtNlCount = parseFile(&mt_f, mtPath, mt);
    extNlCount = parseFile(&ext_f, extPath, ext);
    Q = fnameNlCount = parseFile(&fname_f, fnamePath, fname);
    //
    initBuckets(); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

 

    //bucketsStorage = (bucket_ts*)malloc(sizeof(*buckets));
    for (int i = 0; i < TABLE_SIZE; ++i){ // populate the array
        bucketsStorage[i] = (bucket_ts*)malloc(sizeof(bucket_ts));
 
    }

 
    for(int i = 0; i <= Q; ++i) {
        initBucket(bucketsStorage[i], &fname[i], "");
        htIns(&bucketsStorage[i]);
    }
    printAllBuckets();


    return 0;
}