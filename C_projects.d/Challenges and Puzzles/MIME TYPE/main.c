// ITJ 09/07/2021, Last change: 10/06/21
// codingame challege Mime Types
// Limit: 0 < N < 10000
// Limit: 0 < Q < 10000

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "hashtable.h"
#include "testdata.h"
#include "main.h"


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

int main() {
    Q = N = 0;
    //
    N = mtNlCount = parseFile(&mt_f, mtPath, mt);
    extNlCount = parseFile(&ext_f, extPath, ext);
    Q = fnameNlCount = parseFile(&fname_f, fnamePath, fname);
    //
    initBuckets(); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    bucket_ts* bucketsStorage = (bucket_ts*)malloc(sizeof(bucket_ts) * 10001);
    extMt_ts* extList = (extMt_ts*)malloc(sizeof(extMt_ts[10001]));
    for (int i = 0; i < 10000; ++i) {
        strcpy(bucketsStorage[i].key, "\0");
        strcpy(bucketsStorage[i].ext_pair, "\0");
        bucketsStorage[i].extNum = 0;
    }
    for (int i = 0; i < Q; ++i) {
        memset(fExtTempString, 0, strlen(fExtTempString));
        tempCharCount = 0;
        for (int j = 0; j < 257; ++j) {
            fnameTempChar = fname[i][j];
            if (fnameTempChar == '\0') break;
            if ((fnameTempChar == '.') && (fnameTempChar != NULL)) {
                memset(fExtTempString, 0, strlen(fExtTempString));
                tempCharCount = 0;
            }
            else if ((fnameTempChar != '.') && (fnameTempChar != "\0")) {
                fExtTempString[tempCharCount] = fnameTempChar;
                ++tempCharCount;
            }
        }
        strcpy(bucketsStorage[i].key, fname[i]);
        for (int k = 0; k <= strlen(fExtTempString); ++k) {
            fExtTempString[k] = tolower((unsigned char)fExtTempString[k]);
        }
        for (int l = 0; l <= N; ++l) {
           // for (int o = 0; o <= strlen(extList[l].extension); ++o) extList[l].extension[o] = tolower((unsigned char)extList[l].extension[o]);
            if (strcmp(extList[l].extension, fExtTempString) == 0) {
                bucketsStorage[i].extNum = l;
                break;
            }
        }
            strcpy(bucketsStorage[i].ext_pair, fExtTempString);
            memset(fExtTempString, 0, strlen(fExtTempString));
            //
            printf("insertFN: ");
            htIns(&bucketsStorage[i]);
            printf("\nhashFN: ");
            hash(fname[i]);
            printf("\nprintBuckt()  ");
            htLookUp(fname[i]);
            printf("\n\n\n");
        }
        for (int i = 0; i <= 10000; ++i) {
            strcpy(extList[i].extension, "\0");
            strcpy(extList[i].mimeType, "\0");
        }
        printAllBuckets();
        free(bucketsStorage);
        return 0;
    
}