# include <stdio.h>
# include <stdlib.h> 

int main() {
    int primeNumbers[] = {2,3,5,7};

    printf("First Index : %d \n\n",primeNumbers[0]);// 2

    printf("FirstIndex: %d \n\n",*primeNumbers); // 2

    printf("FirstIndex: %d \n\n",*(primeNumbers+1));     // 3

    
}