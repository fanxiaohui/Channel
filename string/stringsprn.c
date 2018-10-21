#include <stdio.h>
#include <string.h>

int main ()
{
    int i;
    char str[] = "129th";
    char accept[] = "1234567890";

    i = strspn(str, accept);
    printf("str 前 %d 个字符都属于 accept\n",i);  // 输出：str 前 3 个字符都属于 accept
    
    char* s1 = "http://c.biancheng.net/cpp/xitong/";
    char* s2 = "z -+*";

    if(strlen(s1) == strcspn(s1,s2)){
        printf("s1 is diffrent from s2!\n");  // 输出：s1 is diffrent from s2!
    }else{
        printf("There is at least one same character in s1 and s2!\n");
    }
    return 0;
}
