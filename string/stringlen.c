#include <stdio.h>
#include <stdlib.h>

main(int argc, char const *argv[])
{
    char str[5] = "abcdefg";
    printf("content of str is %s\n",str);
    printf("strlen(str)=%d ,sizeof(str)=%d\n",strlen(str),sizeof(str));
    return 0;
}
