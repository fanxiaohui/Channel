#include<stdio.h>
#include<string.h>


int main(int argc,char *argv[]){
    char string[10];
    char *str1 = "abcdefghiabcdefghi";
    strncpy(string, str1, 3);
    string[3] = '\0';
    printf("%s\n", string);  // 输出：abc
    return 0;
}