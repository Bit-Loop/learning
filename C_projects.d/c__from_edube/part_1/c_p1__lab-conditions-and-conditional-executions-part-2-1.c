//100% overkill 
// itj aug/18/21
#include <stdio.h>

int absolute(int number){ 
    
    if (number < 0) return -number;
    else return number;
}

int main(void) {
    
	int n = -3;
	printf("The absolute value of %d is %d\n", n, absolute(n));
	printf("The value of n is %d", n);
	return 0;
}