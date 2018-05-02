#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(int argc, char *argv[]){ //argc指的是传入的参数的个数，argv是一个指针数组，指向传递给程序的每一个参数
    printf("\n");
    // if(argc ==2) {
    //     printf("the first argument supplied is %s\n",argv[0]);// argv[0]指向的是可执行文件的据对路径
    //     printf("the first argument supplied is %s\n",argv[1]); //argv[1] 指向的是传入的第一个参数
    // } else {
    //     printf("the number of arguments supplied: %d\n",argc);
    // }
    int i = 0;
    for( i=0; i<argc;i++){
        printf("the %d th argument supplied is %s \n",i,argv[i]);
    }

    i = 0 ;
    while(argv[i]!=NULL){
        printf("the %d th argument is %s \n",i,argv[i]);
        i++;
    }


   
}

