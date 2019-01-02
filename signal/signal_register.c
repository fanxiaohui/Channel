#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signum){
    printf("Received a signal %d\n", signum);
}


int main(int argc, const char *argv[])
{
    signal(SIGINT,sig_handler);
    sleep(10); //this your chance to press CTRL +C
    return 0;
}
