#include <stdio.h>
#include <unistd.h>

int main(int arg,char **args)
{
    //char *name="/usr/bin/ls";

    char *argv[]={"ls","-al","/usr/include/linux",NULL};//传递给执行文件的参数数组，这里包含执行文件的参数 

    char *envp[]={0,NULL};//传递给执行文件新的环境变量数组

    // execve("/bin/ls",argv,envp);
    execlp("echo", "echo", "hey there", NULL);
 
}