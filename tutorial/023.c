# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>

int main(){
 char * randomString = "Just some random stuff";
//  while(*randomString) { //只要指针指向的值不是NULL,也就是0，就一直把指针往后移动
//      putchar(*randomString++);
//      printf("\n");
//  }

 int i = 0 ;
 while(randomString[i] != '\0'){
     putchar(randomString[i++]);
 }
}