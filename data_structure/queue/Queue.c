#include <stdio.h>
#include <stdlib.h>
#include "myQueue.h"


typedef struct a
{
    int i;
    char c;
}A;


void test_my_queue()
{
    const int S = 10;

    A * data = malloc(sizeof(A)*S);
    for (int i=0 ; i<S ; i++){
        data[i].i=i;
        data[i].c=(char)('A'+i);
    }

    MyQueue * queue = createMyQueue();


    //插入数据

    myQueueAdd(queue,&data[0]);
    myQueueAdd(queue,&data[2]);
    myQueueAdd(queue,&data[6]);

    //测试删除

    while(myListGetSize(queue))
    {
        A * pp = myQueueRemove(queue);
        printf("hey %d [%c] \n",pp->i,pp->c);
    }
    puts("");
    freeMyQueue(queue);
}

int main(int argc, char const *argv[])
{
    printf("starting test  %s\n","myQueue");
    test_my_queue();
    return 0;
}
