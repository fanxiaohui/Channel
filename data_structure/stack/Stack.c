#include <stdio.h>
#include <stdlib.h>
#include "myStack.h"


typedef struct a{
    int i;
    char c;
} A;

int main(int argc, char const *argv[])
{
    const int S = 10;
    A * data = malloc(sizeof(A)*S);

    
    for(size_t i = 0; i < S; i++)
    {
        data[i].i = i;
        data[i].c = (char)('A'+i);
    }

    MyStack * stack = createMyStack();

    myStackAdd(stack,&data[0]);
    myStackAdd(stack,&data[2]);
    myStackAdd(stack,&data[3]);
    
    while(myListGetSize(stack)){
        A * pp = myStackRemove(stack);
        printf("hey %d there %c \n",pp->i,pp->c);
    }
    puts("");

    freeMyStack(stack);
    free(data);

    printf("end %s\n","of program");
    return 0;
}
