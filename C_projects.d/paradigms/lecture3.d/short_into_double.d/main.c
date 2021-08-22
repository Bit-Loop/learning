// itj 08-21-21
// a simple program that shows what happens when you take a
// short(2bytes) and copy it into a double(8 bytes).
#include <stdio.h>

int main(void){

        short  numS = 0xFF;
        double noInitNumD = *(double*)&numS;
        double initNumD = 0;
        initNumD = *(double*)&numS;
        //
        printf("HEX:   numS = %x \t noInitNumD = %x  \t", numS, noInitNumD);
        printf("initNumD = %x \n\n", initNumD);      
        // if printf  has a 3rd arg in this context it will only output a random 0x val
        // the other data (print) typtes will show 0xFF
        // assuming overloading of something somewhere
        // double noInitNumD_ = noInitNumD AFTER  initNumD = *(double*)&numS;
        // makes noInitNumD printf 0xFF and initNumD will print 0x00

        printf("OCTAL: numS = %o \t noInitNumD = %o \t", numS, noInitNumD);             
        printf("initNumD = %o \n\n", initNumD);      
        printf("DEC:   numS = %d \t noInitNumD = %d \t", numS, noInitNumD);      
        printf("initNumD = %d \n\n", initNumD);      
        printf("FLOAT: numS = %2.2f \t noInitNumD = %2.2f \t" , numS, noInitNumD);      
        printf("initNumD = %2.2f \n\n", initNumD);      
        return 0;
}
