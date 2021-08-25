/* ITJ - 08-21-21
 *
 * Count blanks and new lines
 *
 * 
 * */
#include <stdio.h> 

int main(void){
        int c, blank, nl;
        c = nl = blank = 0;
        puts("to exit use ctrl^z & enter in windows");
        while ((c = getchar()) != EOF){
               
                if (c == ' ')  { ++blank; };
                if (c == '\n' ) { ++nl; };
        }   
        printf("blank lines:\t%d\nNewLines:\t%d", blank, nl);
return 0;
}
