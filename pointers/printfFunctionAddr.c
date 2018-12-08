#include <stdio.h>
#include <stdlib.h>

void func1(void){}
void func2(void){}
void func3(void){}


int main(int argc, char const *argv[])
{
   printf("func1: %p, func2: %p, func3: %p\n",func1,func2,func3);
    return 0;
}
