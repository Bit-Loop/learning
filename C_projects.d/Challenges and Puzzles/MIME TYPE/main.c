// ITJ 09/07/2021, Last change: 09/22/21
// codingame challege Mime Types
// Limit: 0 < N < 10000
// Limit: 0 < Q < 10000

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "hashtable.h"
//#include "hashtable.c"
/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

#define EXT_MT_TABLE_SIZE 20

int main() {
    humanTest();
    //printAllBuckets();
    printf("test!\t%d\n", returnBucket(20));
    // Number of elements which make up the association table.
    int N = 10;
    //scanf("%d", &N);
    // Number Q of file names to be analyzed.
    int Q = 0;
    //scanf("%d", &Q);
    struct extMt {
        char mt[51];
        char ext[11];
    };
    struct extMt fileExt[20] = { 0 };
    for (int i = 0; i < N; i++) {
        fprintf(stderr, "n %i\n", i + 1);
        scanf("%s%s", fileExt[i].ext, fileExt[i].mt); fgetc(stdin);
        fprintf(stderr, "EXT %s \t MT %s\n", fileExt[i].ext, fileExt[i].mt);
    }
    for (int i = 0; i <= N; ++i) {
        printf("#%d\t%s\t%s\n", i, fileExt[i].ext, fileExt[i].mt);
    }
    for (int i = 0; i < Q; i++) {
        // One file name per line.
        char FNAME[257];
       // scanf("%[^\n]", FNAME); fgetc(stdin);
    }
  
     // Write an answer using printf(). DON'T FORGET THE TRAILING \n
     // To debug: fprintf(stderr, "Debug messages...\n")
     // For each of the Q filenames, display on a line the corresponding MIME type. If there is no corresponding type, then display UNKNOWN.
    printf("UNKNOWN\n");
    return 0;
}