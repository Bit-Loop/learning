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
#include <unistd.h>
#include <fcntl.h>
#define CHUNK_SIZE uint8_t

int main(void){

	// REF: http://www.dmulholl.com/lets-build/a-hexdump-utility.html
	// REF: https://www.cplusplus.com/reference/cstdio/FILE/
	// REF: 
	FILE* file;
	char* filePath = "./";
        uint8_t* buffer;
	uint8_t br;
        file = fopen("file", "r");
        if (file == NULL) {
            fprintf(stderr, "Error: cannot open the file '%s'.\n", filePath);
            exit(1);
	}
	fseek(file, 0, SEEK_END);
	int maxBytes = ftell(file);
        buffer = (uint8_t*)calloc(maxBytes, sizeof(CHUNK_SIZE)); 
        br = read(file, buffer, sizeof(uint8_t));
        printf("br:%02x\n", br);
        if (buffer == NULL) {
                printf("Memory not allocated.\n");
                exit(-1);
        } else {
                printf("Memory successfully allocated using calloc.\n");
                // Get the elements of the array
                //for (int i = 0; i < maxBytes; ++i) {
                //       buffer[i] = i;
                //}
                // Print the elements of the array
                printf("The elements of the array are: ");
                for (int i = 0; i < maxBytes; ++i) {
                        printf("%02x, ", buffer[i]);
                }
        }
        printf("maxBytes %i, size of the buffer %i", maxBytes, sizeof(*buffer));
        printf("%02x",br);
        fclose(file);
	free(buffer);
return 0;
}

