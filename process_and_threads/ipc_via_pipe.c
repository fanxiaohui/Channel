#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    if(argc < 3){
        fprintf(stderr, "usage: %s parent_sendmsg child_sendmsg\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int pipes[2];
    if(pipe(pipes) < 0){
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    __pid_t pid = fork();
    if(pid < 0){
        perror("fork");
        exit(EXIT_FAILURE);
    }else if(pid > 0){
        char buf[BUFSIZ + 1];
        int nbuf;
        strcpy(buf, argv[1]);
        write(pipes[1], buf, strlen(buf));

        sleep(1); 

        nbuf = read(pipes[0], buf, BUFSIZ);
        buf[nbuf] = 0;
        printf("parent_proc(%d) recv_from_child: %s\n", getpid(), buf);

        close(pipes[0]);
        close(pipes[1]);
    }else if(pid == 0){
        char buf[BUFSIZ + 1];
        int nbuf = read(pipes[0], buf, BUFSIZ);
        buf[nbuf] = 0;
        printf("child_proc(%d) recv_from_parent: %s\n", getpid(), buf);
        char msg[BUFSIZ];
        strcpy(buf, argv[2]);
        strcat(buf," ｉ hereby acknowledge your  message");
        strcat(msg,buf);
        write(pipes[1], buf, strlen(buf));

        close(pipes[0]);
        close(pipes[1]);
    }

    return 0;
}


