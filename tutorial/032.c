#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(){
    FILE *pFile;
    char * buffer;
    size_t dataInFile;
    long fileSize;


    pFile = fopen("./tmp/name.bin","rb+");
    if(pFile ==NULL) {
        perror("Error occured");
        printf("Error code %d\n",errno);

        printf("File is Being created \n\n");

        pFile = fopen("./tmp/name.bin","wb+");// 该方法不能创造目录
        
        if(pFile ==NULL){
            perror("Error occured");
            printf("Error code %d\n",errno);
            exit(1);
        }

    }

    char name[] = "Awesome name";
    fwrite(name,sizeof(name[0]),sizeof(name)/sizeof(name[0]),pFile);

    fseek(pFile,0,SEEK_END);
    fileSize = ftell(pFile);

    rewind(pFile);

    buffer = (char *) malloc(sizeof(char)*fileSize);

    if(buffer==NULL){
        perror("Error occured");
        printf("Error code %d\n",errno);
        exit(2);
    }
    dataInFile = fread(buffer,1,fileSize,pFile);
    
    if(dataInFile != fileSize) {
         perror("Error occured");
        printf("Error code %d\n",errno);
        exit(3);
    }

    printf("%s\n",buffer);
    printf("\n");

    fclose(pFile);
    free(buffer);

    return 0;
}
