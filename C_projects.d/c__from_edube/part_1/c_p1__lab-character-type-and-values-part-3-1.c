// my solution to
// https://edube.org/learn/c-essentials-part-1/lab-character-type-and-values-part-3-1
// itj aug/18/21
#include <stdio.h>

int main()
{
	char zero = '0';
	int result = 0;
	// for( char counter = 0; counter <= 9; ++counter){
	// is very diffrent than
	for( char counter = '0'; counter <='9'; ++counter){
	    
	printf("'%c' - '%c' is: %d \n", counter, zero, counter - zero);
	}

	return 0;
}