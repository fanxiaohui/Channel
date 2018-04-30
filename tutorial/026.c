# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>


int main(){

    int amtOfNumbersToStore;

    printf("How many numbers do you want to store: \n");
    scanf("%d",&amtOfNumbersToStore);
    int *pRandomNumbers;
    pRandomNumbers = (int *) malloc(amtOfNumbersToStore*sizeof(int));
    if(pRandomNumbers != NULL){
        int i =0 ;
        printf("Enter a Number or Quit\n");
        while((i < amtOfNumbersToStore && scanf("%d",&pRandomNumbers[i])==1)){
            printf("Enter a Number or Quit\n");
            i++;
        }
        printf("\n you entered the following numbers\n");
        for(int j=0; j<i; j++){
            printf("%d",pRandomNumbers[j]);
        }
        free(pRandomNumbers);
    }
   return 0;

}
 
