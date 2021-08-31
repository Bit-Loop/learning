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
	int maxBytes = 16;
        uint8_t* buffer = (uint16_t*)malloc(maxBytes); 
	int numBytes = fread(buffer, sizeof(uint16_t), maxBytes, file);
	printf("%i", numBytes);
	fclose(file);
return 0;
}
