#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    const char  firstname[] = "bobby";
   const char* lastname = "eraserhead";
   printf("firstname size is: %d and lastname size is : %d \n", 
   sizeof(firstname) ,
   sizeof(lastname));
   printf("length of first str is %d and the second is %d \n",
   strlen(firstname),strlen(lastname));
}