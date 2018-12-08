#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int nextRand(int begin, int end  ) {
    return (rand() % (end -begin)) + begin;
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    srand(rand() * rand() );

    //随机一位数
    for(int i=0 ; i< 10 ; i ++){
        printf("%d, ", nextRand(0,10));
    }
    printf("\b\b\n");
    

    //随机两位数
    for(int i=0 ; i< 10 ; i ++){
        printf("%d, ", nextRand(10,100));
    }
    printf("\b\b\n");

    //随机月份
    for(int i=0 ; i< 10 ; i ++){
        printf("%d, ", nextRand(1,13));
    }
    printf("\b\b\n");
    return 0;
}
