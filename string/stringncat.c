#include<stdio.h>
#include<string.h>

int main()
{
    char url[100] = "http://www.baidu.com";
    char path[30] = "/cpp/u/string/";
    int char_length = sizeof(path)/sizeof(char);
    printf("size of path is %ld and length is %ld \n ",sizeof(path),strlen(path));
    printf("size of char is %ld\n",sizeof(char));
    printf("size of char_length is %d\n",char_length);
    strncat(url, path, strlen(path)/sizeof(char));  // 1000远远超过path的长度
    printf("%s\n", url);  
    return  0;
}