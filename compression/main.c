/* ITJ - 08-31-21
 * Learning compression conecpts and FILE I/O the hardway.
 * Huffman incoding by counting occurances of 0x00 to 0xFF and displaying the
 * occurances in a histogram.
 *
 *  REF:
 *     https://www.youtube.com/watch?v=_8-ht2AKyH4 iPointers and dynamic memory
 * - stack vs heap
 *
 *
 */
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define CHUNK_SIZE uint8_t

int divBy8(int n)
{ // https://www.geeksforgeeks.org/check-number-divisible-8-using-bitwise-operators/
    return (((n >> 3) << 3) == n);
}
 

int main(void) {
  // REF: http://www.dmulholl.com/lets-build/a-hexdump-utility.html
  // REF: https://www.cplusplus.com/reference/cstdio/FILE/
  // REF: https://stackoverflow.com/questions/3357939/fread-returns-zero
  FILE* file;
  FILE* fileOut;
  char* fileDir =
      "C:\\Users\\bitloop\\source\\repos\\Bit-"
      "Loop\\learning\\compression\\file";
  char* fileOutDir =
      "C:\\Users\\bitloop\\source\\repos\\Bit-"
      "Loop\\learning\\compression\\file_output";
  char* fileCryptDir =
      "C:\\Users\\bitloop\\source\\repos\\Bit-"
      "Loop\\learning\\compression\\crypt";
  uint8_t* buffer;
  file = fopen(fileDir, "rb");
  if (file == NULL) {
    fprintf(stderr, "Error: cannot open the file '%s'.\n", fileDir);
    exit(1);
  }
  fseek(file, 0, SEEK_END); // uncertain if this is needed, points to EOF
  long maxBytes = ftell(file);
  buffer = (uint8_t*)calloc( maxBytes, sizeof(CHUNK_SIZE));  // make an array big enough to hopefully hold the file.
  fseek(file, 0, SEEK_SET);  // set pos to read from, undoing SEEK_END
  if (buffer == NULL) {
    printf("Memory not allocated.\n");
    exit(-1);
  } else {
   // fseek(file, 0, SEEK_SET);  // set pos to read from
    fread(buffer, sizeof(CHUNK_SIZE), maxBytes,file);  // Read in the entire file
    printf("Memory successfully allocated using calloc.\n");
    printf("The elements of the array are: \n\n");
    int row = 0;
    for (unsigned long int i = 0; i < maxBytes; ++i) {
      printf("%02x ", buffer[i]); //outputs text to cli
      if (divBy8(i+1) == 1) {
        printf("\n");
      }
    }
  }
 
  printf("\n\nFile size was\t%i Bytes", maxBytes);
   fileOut = fopen(fileOutDir, "wb");           // w for write, b for biinary
  fwrite(buffer, maxBytes, 1, fileOut);  // write 10 bytes from our buffer
  fclose(file);
  fclose(fileOut);
  free(buffer);
  getchar(); // Using this as a hack to keep the program from
             //
  return 0;
}
