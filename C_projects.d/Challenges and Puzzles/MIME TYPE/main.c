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

#define EXT_MT_TABLE_SIZE 20
#define STR_AMNT 50
#define STR_CHAR_COUNT 100
int main() {
    /* Code from the codingame challenge
    for (int i = 0; i < N; i++) {
        fprintf(stderr, "n %i\n", i + 1);
        scanf("%s%s", extMt_s[i].ext, extMt_s[i].mt); fgetc(stdin);
        fprintf(stderr, "EXT %s \t MT %s\n", extMt_s[i].ext, extMt_s[i].mt);
    }
    for (int i = 0; i <= N; ++i) {
        printf("#%d\t%s\t%s\n", i, extMt_s[i].ext, extMt_s[i].mt);
    }
    for (int i = 0; i < Q; i++) {
        char FNAME[257];
       // scanf("%[^\n]", FNAME); fgetc(stdin);
    }
  */  // One file name per line.
      

    FILE* mt_f;
    FILE* ext_f;
    FILE* fname_f;
    char* mtPath = "C:\\Users\\bitloop\\Documents\\GitHub\\learning\\C_projects.d\\Challenges and Puzzles\\MIME TYPE\\_mt.txt";
    char* extPath = "C:\\Users\\bitloop\\Documents\\GitHub\\learning\\C_projects.d\\Challenges and Puzzles\\MIME TYPE\\_ext.txt";
    char* fnamePath = "C:\\Users\\bitloop\\Documents\\GitHub\\learning\\C_projects.d\\Challenges and Puzzles\\MIME TYPE\\_fname.txt";
    char mt[STR_CHAR_COUNT][STR_AMNT] = { 0 };
    char ext[STR_CHAR_COUNT][STR_AMNT] = { 0 };
    char fname[STR_CHAR_COUNT][STR_AMNT] = { 0 };
    int mtNlCount = 0;
    int extNlCount = 0;
    int fnameNlCount = 0;
    char fnameTempString[257] = "\0";
    char fnameTempChar = "\0";
    int  tempCharCount = 0;
    int Q, N;
    Q = N = 0;
    //
    N = mtNlCount = parseFile(&mt_f, mtPath, mt);
    extNlCount = parseFile(&ext_f, extPath, ext);
    Q = fnameNlCount = parseFile(&fname_f, fnamePath, fname);
    //
    initBuckets(); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    bucket_ts* bucketsStorage = (bucket_ts*)malloc(sizeof(bucket_ts[10000]));
    for (int i = 0; i < 10000; ++i) {
        strcpy(bucketsStorage[i].key, "\0");
        strcpy(bucketsStorage[i].ext_pair, "\0");
    }
    for (int i = 0; i < Q; ++i) {
        memset(fnameTempString, 0, strlen(fnameTempString));
        tempCharCount = 0;
        for (int j = 0; j < 257; ++j) {
            fnameTempChar = fname[i][j];
            if (fnameTempChar == '\0') break;
            if ((fnameTempChar == '.') && (fnameTempChar != NULL)) {
                memset(fnameTempString, 0, strlen(fnameTempString));
                tempCharCount = 0;
            }
            else if ((fnameTempChar != '.') && (fnameTempChar != "\0")) {
                fnameTempString[tempCharCount] = fnameTempChar;
                ++tempCharCount;
            }
        }
        strcpy(bucketsStorage[i].key, fname[i]);
        strcpy(bucketsStorage[i].ext_pair, fnameTempString);
        memset(fnameTempString, 0, strlen(fnameTempString));
        htIns(&bucketsStorage[i]);
    }
    printAllBuckets();
    free(bucketsStorage);
    free(buckets);
    return 0;
}