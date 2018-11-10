#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int main(int argc, char const *argv[])
{
    /* code */

    int n =0;
    printf("before fork: n = %d\n",n);

    __pid_t fpid =fork();

    if(fpid <0 )
    {
        perror("fork error");
        exit(EXIT_FAILURE);
    }else if (fpid == 0)
    {
        n++;
        printf("child_proc(%d, ppid=%d): n= %d\n",getpid(),getppid(),n);
    } else
    {
        n--;
        printf("parent_proc(%d): n= %d\n",getpid(),n);
    }
    printf("quit_proc(%d) ...\n",getpid());


    return 0;
}
