# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>

int main(){
 char name[50];
 printf("Wwhat is your name? ");

 fgets(name,50,stdin); //三个参数分别是
 fputs("Hi",stdout);
 fputs(name,stdout);
}