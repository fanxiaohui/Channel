#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 1024

int main(){
	FILE *fp = fopen("sample16.txt", "a+");
	if(fp == NULL){
		printf("IO ERROR!\n");
		exit(1);
	}
	char str[N];
	printf("say something: \n");
	scanf("%[^\n]",str);
	strcat(str,"\n");
	fputs(str,fp);

	printf("finishing writing into file\n\n");
	printf("the contents of the file is : \n\n");

	memset(str, 0, sizeof(str));
	rewind(fp);
	while(fgets(str, N, fp) != NULL){
		printf("%s", str);
	}
	fclose(fp);
	return 0;
}

