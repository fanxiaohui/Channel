#include<stdio.h>
#include<string.h>
int main(){
    char *str = "HelloWorldHelloWorld";
    char *substr = "World";
    char *s = strstr(str, substr);  
    printf("%s\n", s);  // 输出：WorldHelloWorld
    return 0;
}