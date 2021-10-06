#include <stdio.h>
#ifndef MAIN_H 
#define MAIN_
#ifdef __cplusplus //check if using a C++ compiler, if true put code in extern c block
extern "C" { // if true ^ then use C naming rules for C++ compilation
#endif

    #define STR_AMNT 50
    #define EXT_MT_TABLE_SIZE 20
    #define STR_CHAR_COUNT 100
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
    char fnameTempChar = '\0';
    int  tempCharCount = 0;
    int Q, N; // Codingame challenge provided VARs

	//boiler - plate bottom part below.
#ifdef __cplusplus // if true exit the extern c block
}
#endif
#endif // HASHTABLE_H end