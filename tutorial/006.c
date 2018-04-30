# include <stdio.h>
# include <stdlib.h>

void main () {

    int whatToDo = 0;

    do {
        printf("\n");
        scanf(" %d",&whatToDo);
    } while (whatToDo <1  || whatToDo >4);
    printf(" %s %d","the number is ", whatToDo);
    exit(0);
}