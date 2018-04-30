# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <ctype.h>
# include <string.h>

int main(){
    _Bool isANumber; // 1 或者0 
    int number;
    int sumOfNumbers = 0 ;
    printf("Enter a Number : \n");

    isANumber = (scanf("%d",&number)==1);

    while (isANumber){
        sumOfNumbers = sumOfNumbers + number;
        printf("Enter a number");
        isANumber = (scanf("%d",&number)==1); 
    }

    printf("The sum is %d\n\n",sumOfNumbers);
}