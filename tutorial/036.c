#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    char *ptr_string = "hello";
    char str_array3[10] = {"hello"};
    // printf(str_array3);
    printf("pointer version size of is %d \n",sizeof(ptr_string));
    printf("\n");
    // printf(ptr_string);
    //获得数组的大小
    printf("array version size of is %d: \n",sizeof(str_array3));
    printf("\n");
    strncpy(str_array3,ptr_string,7);//将ptr_str的前7位拷贝进去
    printf("str_array3:%s\n",str_array3);
}