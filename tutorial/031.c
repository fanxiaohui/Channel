#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int randomNumber;

    char buffer[1024];
    FILE *pFile;
    pFile = fopen("./tmp/randomFile.txt","w+");

    // a- Append
    // r - Read
    // a+ open or create , append
    // r+ 允许读写

    if(!pFile){
        printf("Error opening the file! ");
        return 1;
    }

    // for(int i=0 ; i< 100 ; i++ ){
    //     randomNumber = rand() %100;
    //     fprintf(pFile,"%d\n",randomNumber);// 将内容写入文件
    //      fputs("Messing with Strings",pFile);
    // }
     fputs("Messing with Strings",pFile);
      fputs("Messing with Strings",pFile);
       fputs("Messing with Strings",pFile);
       fputs("Messing with Strings",pFile);
       fputs("Messing with Strings",pFile);
    fseek(pFile,0,SEEK_SET); //指针挪到文件开头


    while(fgets(buffer,1024,pFile)!=NULL){
        printf("%s",buffer);
    }

    puts("=============");
    putchar('\n');
    
    // fseek(pFile,-99,SEEK_END);
    while(fscanf(pFile,"%s",buffer) == 1){
        puts(buffer);//自动在尾部添加换行符
    }
    long numberOfBytes = ftell(pFile);//查询当前读取进度
    

    printf("Success reading %d bytes from file! \n", numberOfBytes);
    return 0;


}


 
