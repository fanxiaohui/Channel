#include <stdio.h>
#include <stdlib.h>
#define N 1024
long fsize(FILE *fp){
    fseek(fp, 0, SEEK_END);
    return ftell(fp);
}

int main(){
    printf("enter the file absolute path: \n ");
    char str[N];
    scanf("%s",str);
    printf("\n the file name you choose is: %s\n ",str);
    FILE *fp = fopen(str, "rb");
    if(fp == NULL ){
    	printf("error opening file \n");
	exit(-1);
    }
    printf("len: %ld bytes\n", fsize(fp));
    fclose(fp);
    return 0;
}
