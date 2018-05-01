#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(){
    FILE *pFile;
   


    pFile = fopen("./tmp/random.bin","rb+");
    if(pFile ==NULL) {
        perror("Error occured");
        printf("Error code %d\n",errno);

        printf("File is Being created \n\n");

        pFile = fopen("./tmp/random.bin","wb+");// 该方法不能创造目录
        
        if(pFile ==NULL){
            perror("Error occured");
            printf("Error code %d\n",errno);
            exit(1);
        }

    }

    int randomNumbers[20];

    for(int i=0;i<20;++i){
        randomNumbers[i] =rand()%100;
        printf("Number %d is %d \n",i,randomNumbers[i]);
    }

    fwrite(randomNumbers,sizeof(int),20,pFile);
    long randomIndexNumber ;
    int numberAtIndex;

    printf("Which random number do you want? \n");

    scanf("%d",&randomIndexNumber);

    fseek(pFile,randomIndexNumber*sizeof(int),SEEK_SET);

    fread(&numberAtIndex,sizeof(int),1,pFile);
    printf("the random number at index %d is %d \n",
    randomIndexNumber,numberAtIndex);

    fclose(pFile);

    return 0;
}
