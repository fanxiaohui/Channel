#include <stdio.h>

int main() {
    printf("\n");

    int customerAge = 25;

    if(customerAge>21&& customerAge <35) {
        printf("you are welcome to shop!");
    }


    char* legaleAge = "string";
    printf(legaleAge);
    printf("\n");

    printf("A char takes up %d bytes\n\n",sizeof(char));
    printf("A int takes up %d bytes\n\n",sizeof(int));
    printf("A long takes up %d bytes\n\n",sizeof(long));
    printf("A float takes up %d bytes\n\n",sizeof(float));
    printf("A double takes up %d bytes\n\n",sizeof(double));
    

    
}