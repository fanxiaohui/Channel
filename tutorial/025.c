# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>

void getCharInfo(){
    char theChar;
    while((theChar ==getchar()) != '\n'){
        putchar(theChar);
        printf("Letter or Number %d\n",isalnum(theChar));
        printf("Alphabetic Char %d\n",isalpha(theChar));
        printf("Standard blank %d\n",isblank(theChar));
        printf("Ctrl Char %d\n",iscntrl(theChar));
        printf("Number Char %d\n",isdigit(theChar));
        printf("Anything but space %d\n\n",isgraph(theChar));
        printf("is Lower case %d\n\n",islower(theChar));
    }

}
int main(){

    getCharInfo();

}
 
