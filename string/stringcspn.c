#include<stdio.h>
#include<string.h>

int main()
{
    char* s1 = "c++";
    char* s2 = "c++";

    printf("strcmp result is %d\n",strcmp(s1,s2));

    if(strlen(s1) == strcspn(s1,s2)){
        printf("s1 is diffrent from s2!\n");  // 输出：s1 is diffrent from s2!
    }else{
        printf("There is at least one same character in s1 and s2!\n");
    }
    return 0;
}
