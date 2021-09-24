/* itj, created 09/23/21, last change 09/23/21
* Emulating the codingame test input for the challenge "MIME TYPE"
* 
* It is a seprate C file inorder to
* abstract it away for the sake of simplicity.
*
* 
* REF: Passing file pointer to FN https://stackoverflow.com/questions/33378000/passing-file-pointer-to-a-function
* 
*/

#include <stdlib.h>
#include <stdio.h>

int parseFile();

void testData() {
	#define MAX_SIZE 50
	#define STR_SIZE 50
	FILE* mt_f;
	FILE* ext_f;
	FILE* fname_f;
	char* mtPath = "C:\\Users\\bitloop\\Documents\\GitHub\\learning\\C_projects.d\\Challenges and Puzzles\\MIME TYPE\\_mt.txt";
	char* extPath = "C:\\Users\\bitloop\\Documents\\GitHub\\learning\\C_projects.d\\Challenges and Puzzles\\MIME TYPE\\_ext.txt";
	char* fnamePath = "C:\\Users\\bitloop\\Documents\\GitHub\\learning\\C_projects.d\\Challenges and Puzzles\\MIME TYPE\\_fname.txt";
	char mt[STR_SIZE][MAX_SIZE] =    {0};
	char ext[STR_SIZE][MAX_SIZE] =   {0};
	char fname[STR_SIZE][MAX_SIZE] = {0};
	int mtNlCount = 0;
	int extNlCount = 0;
	int fnameNlCount = 0;
	//
	mtNlCount = parseFile(&mt_f,mtPath, mt);
	extNlCount = parseFile(&ext_f, extPath, ext);
	fnameNlCount = parseFile(&fname_f, fnamePath, fname);
	
}


int parseFile(FILE** f, char* filename, char (* string)[MAX_SIZE]) {
	if ((f = fopen(filename, "r") == NULL)) {
		printf("NULL!\n\"%s\"", filename);
	}
	else {
		f = fopen(filename, "r");
		char readChar = 0;
		char* tempString;
		tempString = (char*)calloc(STR_SIZE, sizeof(char));
		unsigned int charCount = 0;
		unsigned int stringCount = 0;
		while (readChar != EOF) {
			readChar = fgetc(f);
			if (readChar == EOF) break;
			if (readChar == '\n') {
				strncpy(&string[stringCount], tempString, STR_SIZE);
				++stringCount;
				charCount = 0;	
				free(tempString);
				tempString = (char*)calloc(STR_SIZE, sizeof(char));
			}
			else {
				if (charCount > STR_SIZE) break;
				tempString[charCount]= readChar;
				++charCount;
			}
		}
		//for (int i = 0; i < stringCount; ++i) printf("Text\t%s\n", string[i]);
		free(tempString);
		fclose(f);
		return stringCount;
	}
}