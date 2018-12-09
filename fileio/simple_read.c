#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp = fopen("sample.txt", "r");
    if(fp == NULL){
        printf("IO ERROR!\n");
        exit(1);
    }
    char ch;
    while((ch = fgetc(fp)) != EOF){
        printf("%c", ch);
    }
    fclose(fp);
    return 0;
}

