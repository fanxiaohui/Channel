# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>

int main(){
  char theChar;
  while((theChar ==getchar())!= '~'){
      putchar(theChar);
  }
}