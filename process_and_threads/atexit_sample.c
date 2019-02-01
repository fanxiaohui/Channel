#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void func1(void){
    printf("<atexit> func1 getpid = %d \n",getpid());
}

void func2(void){
    printf("<atexit> func2 getpid = %d \n",getpid());
}

void func3(void){
    printf("<atexit> func3 getpid = %d \n",getpid());
}

void func(int status, void *str){
    printf("<on_exit> exit_code: %d, arg: %s getpid = %d \n", status, (char *)str,getpid());
}

int main(void){
    signal(SIGCHLD, SIG_IGN);

    on_exit(func, "on_exit3");
    on_exit(func, "on_exit2");
    on_exit(func, "on_exit1");

    atexit(func3);
    atexit(func2);
    atexit(func1);

    pid_t pid;
    pid = fork();
    if(pid < 0){
        perror("fork error");
        exit(EXIT_FAILURE);
    }else if(pid == 0){
        exit(0);
    }else{
        sleep(3);
    }

    return 0;
}