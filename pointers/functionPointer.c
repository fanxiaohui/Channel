#include <stdio.h>


int max(int a, int b){
    return a > b ?a:b;
}

int main(int argc, char const *argv[])
{
    /* code */
    int a, b;
    printf("enter two numbers: ");
    scanf("%d %d",&a, &b);
    int(*p)(int , int) = max;
    printf("max: %d\n",p(a ,b));
    return 0;
}
