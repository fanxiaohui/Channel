#include <stdio.h>
#include <string.h>

main(int argc, char const *argv[])
{
    char hex[] = "6A";  //英文字母j的ascii码，只要一个字节                        // here is the hex string
    int num = (int)strtol(hex, NULL, 16);       // number base 16
    printf("%c\n", num);                        // print it as a char
    printf("%d\n", num);                        // print it as decimal
    printf("%X\n", num);                        // print it back as hex
   
    char hex2[3] = {'66','25','\0'}; //汉字“春”，用两个字节
    char hex4[4] = {'e4','bd','a0','\0'};
    printf("\n%s\n",hex2);

    printf("\n%s\n",hex4);


    char *hex3 = "春";
    printf("\n%s\n",hex3);

    printf("\n\n");
   

   
    return 0;
}
