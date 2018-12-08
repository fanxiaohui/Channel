#include <stdio.h>


#define PTR1 int *
typedef int * PTR2;

int main(int argc, char const *argv[])
{
    /* code */
    int a = 10, b = 20;
    PTR1 p1, p2;
    p1 = &a, p2 = &b;
    PTR2 p3, p4;
    p3 = &a, p4 = &b;
    printf("%d, %d, %d, %d\n", *p1, *p2, *p3, *p4);
    return 0;
}
