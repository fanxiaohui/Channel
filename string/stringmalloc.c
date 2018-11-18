#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    char * src = "awesome";
    printf("sizeof src = %ld\n",sizeof(src)); //8
    printf("strlen of src = %ld\n",strlen(src)); //7

    char * copy_of = (char *)malloc(sizeof(src)*sizeof(char));
    memset(copy_of,0,sizeof(char) * sizeof(copy_of));
    strcpy(copy_of,src);
    printf("copied result is %s\n",copy_of);

    char *test = malloc(15 * sizeof(char));
    for(int i = 0;i < 15 ;i  ++ )
        printf("test is %i\n",test[i]);

    memset(test,0,sizeof(int) * 15);

    for(int i = 0 ; i < 15; i ++ )
        printf("test after memset is %i\n",test[i]);

    return 0;
}