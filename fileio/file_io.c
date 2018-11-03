#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileutil.h"



int main(int argc, char const *argv[])
{
    if(argc<2){
        printf("you need supply what goes into the file \n");
        exit(1);
    }
    char *filename = "hashes2.txt";
    char const *contents = argv[1];

    int res ;
    if(file_exits(filename)){
        printf("file %s exists \n",filename);
    }else {
        res = file_write_string_to_file(filename,contents);
    }

    if(res) {
        printf("successfully write contents to file\n");
    }else {
        printf("error writing contents to file \n");
    }
    contents = strcat(contents,"\n");
    res = append_contents_to_a_file(filename,contents);
    if(res) {
        printf("successfully append contents to file\n");
    }else {
        printf("error append contents to file \n");
    }

    char *filecontent = file_read_content_from_file(filename);
    printf("contents in that file : \n %s\n",filecontent);
    free(filecontent);
    printf("now we are free\n");


    FILE *myFile = fopen(filename,"r");
    while (!feof(myFile)) {
        const char *line = readLine(myFile);
        printf("line %s\n", line);
    }
    fclose(myFile);
    return 0;
}






