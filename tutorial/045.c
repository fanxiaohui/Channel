#include <stdio.h>
#include <math.h>

#include <stdlib.h>
int main()
{
//    char str[180];
   char *str = (char *) malloc(40*sizeof(char));

  int a =  sprintf(str, "Pi equals = %f", M_PI);
   puts(str);

   printf("\nwrite number %d",a);
   free(str);
   if(str == NULL) {
       printf("it's empty now\n ");
   } else {
       printf("\n not empty %s\n",str);
   }
   
   return(0);
}
