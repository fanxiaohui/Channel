#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    if(argc < 3){
        fprintf(stderr, "usage: %s fifo_file filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int fifo = open(argv[1], O_WRONLY);
    if(fifo < 0){
        perror("open");
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[2], "rb");
    if(fp == NULL){
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    char buf[BUFSIZ];
    int nbuf;
    while((nbuf = fread(buf, 1, BUFSIZ, fp)) > 0){
        write(fifo, buf, nbuf);
    }

    fclose(fp);
    close(fifo);
    return 0;
}
