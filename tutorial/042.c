#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    char name[5];
    char *description;

   description = malloc(5*sizeof(char));

   if( description == NULL )
   {
      fprintf(stderr, "Error - unable to allocate required memory\n");
   }
   else
   {
    //    strcpy(description,"this will cause an Segment fault cause we need more room");
       strcpy(description,"this");
    //    free(description);
   }

    description = realloc(description,50*sizeof(char)); //重新调整内存的大小
    strcpy(description,"this will work just fine now that we have more memory\n");
    printf(description);
    printf("every thing works fine! \n");
    free(description);

   
}

