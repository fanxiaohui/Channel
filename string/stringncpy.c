#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    char string[10];
    char *str1 = "123456789";
    strncpy(string,str1,3);
    string[3] = '\0'; //因为strncpy不会往尾部追加'\0'，所以不加这一行的话会打印出123FP�这种乱七八糟的东西
    printf("%s\n",string);
    return 0;
}
