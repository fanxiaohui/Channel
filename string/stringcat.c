#include <string.h>
#include <stdio.h>

int main(void)
{
   char destination[25];
   char *blank = " ", *c = "C++", *Borland = "Borland";

   strcpy(destination, Borland);
   strcat(destination, blank);
   char *res =  strcat(destination, c);

   printf("%s\n", res);  // 输出：Borland C++
   return 0;
}