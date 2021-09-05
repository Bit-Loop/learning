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

int divBy8(int n) {
  // REF: https://www.geeksforgeeks.org/check-number-divisible-8-using-bitwise-operators/
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
  unsigned short byteCount[0x101] = {0};
  unsigned short byteCountCopy[0x101] = {0}; 
  unsigned long totalByteAmount = 0;
  if (file == NULL) {
    fprintf(stderr, "Error: cannot open the file '%s'.\n", fileDir);
    exit(1);
  }
  fseek(file, 0, SEEK_END);  // uncertain if this is needed, points to EOF
  long maxBytes = ftell(file);
  buffer = (uint8_t*)calloc(maxBytes,sizeof(CHUNK_SIZE));  // make an array big enough to hopefully hold the file.
  fseek(file, 0, SEEK_SET);  // set pos to read from, undoing SEEK_END
  if (buffer == NULL) {
    printf("Memory not allocated.\n");
    exit(-1);
  } else {
    // fseek(file, 0, SEEK_SET);  // set pos to read from
    fread(buffer, sizeof(CHUNK_SIZE), maxBytes,
          file);  // Read in the entire file
    printf("Memory successfully allocated using calloc.\n");
    printf("The elements of the array are: \n\n");
    int row = 0;
    for (unsigned long int i = 0; i < maxBytes; ++i) {
      printf("%02x ", buffer[i]);  // outputs text to cli
      if (divBy8(i + 1) == 1) {
        printf("\n");
      }
      for (unsigned short x = 0; x <= 0xFF; ++x) {
        if (x == buffer[i]) {
         // sortedThing[byteCount[0]]  
         // //
         // prob will need new for loop
         // do not itrate values of 0s
         // probably make a list of of value that are itratable
         // brb going to do a round
         // sortedThing[buffer[0]] = 
         ++byteCount[x];
         byteCountCopy[x] = byteCount[x];
          ++totalByteAmount;
        }
      }
    }
  }
  // display information about counted bytes
  int maxByteCount = 0, maxByteRef = 0;  // sv  d <= x; then q <= d;
  printf("\n\nTotal Amount of Bytes: %i\n", totalByteAmount);
  for (int x = 0; x <= 0xFF; ++x) {
    printf("%02X: %i\t|| ", x, byteCount[x]);
    if (maxByteCount < byteCount[x]) {
      maxByteCount = byteCount[x];
      maxByteRef = x;
    }
    if (divBy8(x + 1)) {
      printf("\n");
    }
  }
  //This code block should be moved or merged
  unsigned int tmpLargestCount = 0;
  int iteratePos = 0; // iterate postion
  uint16_t sortedByteList[sizeof(byteCount)] = {0};
  bool allZeroFlag = false;
  int z = 0;
  int tmp;
  int zeroCounter = 0;
  while(!allZeroFlag) {
    tmpLargestCount = 0;
    for (int i = 0; i <= 255; ++i) {// for i in range of 255
      if ((byteCountCopy[i] != 0) & (byteCountCopy[i] > tmpLargestCount)) {
        tmpLargestCount = byteCountCopy[i];
        iteratePos = i;
      } //go through the list to find the biggest number (that is left over)
      sortedByteList[z] = iteratePos;
      byteCountCopy[iteratePos] = 0;
    } 
    tmp = 0;
    zeroCounter = 0;
    ++z;
    for (int zeroCheck = 0; zeroCheck <= 0xFF; zeroCheck++) {  // move up into the for loop above
      tmp = byteCountCopy[zeroCheck];
      if (!tmp)  // if it is false ( or equal to zero )
        zeroCounter++; // then add to the counting of zeros
      else if (zeroCounter == 0xFF) //if count of zeros = 255 break loop
        allZeroFlag = true;
    } 
  }
  printf("\n\n\n\n\n");
  for (int i = 0; i <= 255; ++i) {
    printf("#%i  :  byteSym %02x  : byteCount %i \n", i, sortedByteList[i],byteCount[sortedByteList[i]]);
  }
  unsigned int tmpLargestByte = 0;
  printf(
      "\n\nFile size is\t%i Bytes\n"
      "Largest byte probabi]ity: Byte %02x, Char is '%c'\ntByte occurance "
      "count is: %i\n\n",
      maxBytes, maxByteRef, maxByteRef, maxByteCount);
  fileOut = fopen(fileOutDir, "wb");     // w for write, b for biinary
  fwrite(buffer, maxBytes, 1, fileOut); 
  fclose(file);
  fclose(fileOut);
  free(buffer);
  getchar(NULL);  // Using this as a hack to keep the program from ending
              //
  return 0;
}
