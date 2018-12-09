## 错误处理

errno：头文件errno.h定义的一个全局变量，记录了函数调用发生错误时的错误码，int类型，0表示没有错误
void perror(char *msg)：头文件stdio.h中定义的函数，用于抛出最近的一次系统错误信息
char *strerror(int errnum)：头文件string.h中定义的函数，用来依参数errnum的错误代码来查询其错误原因的描述字符串, 然后将该字符串指针返回
```c
#include <stdio.h>
#include <string.h>
#include <errno.h>

int main(void){
    FILE *fp = fopen("unexist.file", "rb");
    if(fp == NULL){
        fprintf(stderr, "error code: %d\n", errno);
        fprintf(stderr, "error code detail: %s\n", strerror(errno));
        perror("error detail");
    }else{
        fclose(fp);
    }
    return 0;
}
```

[参考](https://www.zfl9.com/c-errno.html)