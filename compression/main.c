/* ITJ - 08-31-21
 * Learning compression conecpts and FILE I/O the hardway.
 * Huffman incoding by counting occurances of 0x00 to 0xFF and displaying the occurances
 * in a histogram. 
 *
 *  REF:
 *     https://www.youtube.com/watch?v=_8-ht2AKyH4 iPointers and dynamic memory - stack vs heap
 *
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
int main(void){

	// REF: http://www.dmulholl.com/lets-build/a-hexdump-utility.html
	// REF: https://www.cplusplus.com/reference/cstdio/FILE/
	// REF: 
	FILE* file;
	char* filePath = "./";

	file = fopen("file", "r");
        if (file == NULL) {
            fprintf(stderr, "Error: cannot open the file '%s'.\n", filePath);
            exit(1);
	}
	fseek(file, 0, SEEK_END);
	int maxBytes = ftell(file);
        uint8_t* buffer = (uint8_t*)calloc(maxBytes, sizeof(uint8_t)); 
	int numBytes = fread(buffer, sizeof(uint8_t), maxBytes, file);
	printf("maxBytes %i, numBytes %i", maxBytes, numBytes);
	fclose(file);
	free(buffer);
return 0;
}
