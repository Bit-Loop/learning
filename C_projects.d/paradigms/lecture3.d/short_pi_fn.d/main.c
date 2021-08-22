
#include <stdio.h>
#include "myFunction.c"
int main (void){
       int val1, val2; 
       short pi = &myFunction;
       pi.num = 22;
       pi.denum = 7;
       val2 = &(pi.denum)
       ((myFunction*))&(pi.denum)->val1 = 12;
       printf("val2: %f, val1: %f", val2, val1);
       return 0;
}
