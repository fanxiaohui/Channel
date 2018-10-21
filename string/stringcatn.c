#include<stdio.h>
#include<string.h>

int main()
{
    char url[100] = "http://blog.csdn.net";
    char path[30] = "/cpp/u/string/";
    strncat(url, path, 1000);  // 1000远远超过path的长度
    printf("%s\n", url);  // 输出；http://blog.csdn.net/cpp/u/string/
    return  0;
}