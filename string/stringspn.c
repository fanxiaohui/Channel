#include <stdio.h>
#include <stdlib.h>

main(int argc, char const *argv[])
{
    int i;
    char str[] = "129th";
    char accept[] = "1234567890";

    i = strspn(str, accept);
    printf("str 前 %d 个字符都属于 accept\n",i);  // 输出：str 前 3 个字符都属于 accept
    return 0;
}
