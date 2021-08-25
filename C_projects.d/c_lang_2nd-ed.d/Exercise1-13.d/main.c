/*  ITJ aug - 22 - 2021
*		Exercise 1-13 "Write a program to print a histogram of the lengths of words in its input.
*		It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging."
*/
#include <stdio.h>
int main(void) {
	
	char d, d2, q; // q <= d
	d, q = 0;
	while ((q = getchar()) != EOF) {
		d = 0;	
		
		

	}
	printf("%c%c", d, d2);
	return 0;
}

/*
* words
	100 | *
	... | #
	  4 | #   *
	  3 | # * # * *
	  2 | # # # # # * 
	  1 | # # # # # # #
 	    %------------------------------|
	  0  1  2  3  4  5  6  7  8  9  10 | word length
*/