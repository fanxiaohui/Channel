#include <stdio.h>
#include "fileutil.h"

int main(int argc, char const *argv[])
{
    char *file_path = "awesome.txt";
    char *new_file_path = "stuff.txt";

    // first create file
    if(!file_create_empty_file(file_path)){
        printf("error creating file\n");
        return -1;
    }
    if(file_rename(file_path,new_file_path)){
        printf("successfully rename file\n");
        return -1;
    }
    return 0;
}
