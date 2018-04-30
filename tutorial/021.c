# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>

int main(){
  char name[50];
  printf("What is your name? ");
  gets(name);
  puts("Hi");
  puts(name);
// $ ./021.exe
// What is your name? john Doe
// Hi
// john Doe
}