#include <string.h>
#include <stdio.h>

int main(void)
{
   char destination[25];
   char *blank = " ", *c = "C++", *Borland = "Borland";

   strcpy(destination, Borland);
   strcat(destination, blank);
   strcat(destination, c);

   printf("%s\n", destination);  // 输出：Borland C++
   return 0;
}