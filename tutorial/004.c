#include <stdio.h>


int main() {
    printf("\n");

    int secretNumber = 10, numberGuessed = 0;

    while(1){
        printf("Guess my secret number");

        scanf(" %d",&numberGuessed);

        if(numberGuessed == secretNumber){
            printf("you got it ");
            return 1;
         }
        else {
            printf("sorry try again \n");
        }

    }

}