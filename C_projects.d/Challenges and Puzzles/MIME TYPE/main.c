// ITJ 09/07/2021, Last change: 09/22/21
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

int main() {
    //printAllBuckets();
    printf("test!\t%d\n", returnBucket(20));
    // Number of elements which make up the association table.
    int N = 10;
    //scanf("%d", &N);
    // Number Q of file names to be analyzed.
    int Q = 0;
    //scanf("%d", &Q);


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

    initBuckets(); // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    bucket_ts entry = { .key =  "", .ext_pair = "foo"};
    for (int i = 0; i < Q; ++i) {
       strcpy(entry.key, fname[i]);
       printf("Entry.key, %s\n", entry.key);
       htIns(&entry);
       strcpy(entry.key, ""); // fname in bucket is stored as this for some reason
    }

    puts("start");
    bucket_ts testDrip = { .key = "foo", .ext_pair = "bar" };
    printBucket(hash(&testDrip));
    puts("Attempt Insert bucket value to hash table.");
    htIns(&testDrip); //pass by refrence
    puts("Attempt to reinsert the same value to to hash table.");
    htIns(&testDrip); //pass by refrence
    puts("end");
    puts("print all buckets (that are not null)");
    printAllBuckets();




    return 0;
}