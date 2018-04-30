#include <stdio.h>

int main() {
    printf("\n");

    int num1 =1, num2 = 2;

    if(num1>num2){
        printf("%d is greater than %d \n\n",num1,num2);
    }
    else if(num1<num2){
        printf("%d is less than %d \n\n",num1,num2);
    } else {
        printf("%d is equal to %d \n\n ",num1,num2);
    }

    return 1;
}