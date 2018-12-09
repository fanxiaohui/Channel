#include <stdio.h>
#include <stdlib.h>

#define N 1024+1

int main(){
    FILE *fp = fopen("sample.txt", "r");
    if(fp == NULL){
        printf("IO ERROR!\n");
        exit(1);
    }
    char str[N];
    int i = 1;
    while(fgets(str, N, fp) != NULL){
        printf("%d: %s", i, str);
        i++;
    }
    fclose(fp);
    return 0;
}

