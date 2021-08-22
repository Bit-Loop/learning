/* ITJ - 08-21-21
 *
 * Count blanks and new lines
 *
 * 
 * */
#include <stdio.h> 

int main(void){
        int c; 
        int blank, nl;
        nl = blank = 0;
        while ((c = getchar()) != EOF){
               
                printf("%c", c);
                if (c == ' ')  { ++blank; };
                if (c == '\n' ) { ++nl; };
        }   
        printf("blank lines: %d\n NewLines: %d", blank, nl);
return 0;
}
