#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void write_string_to_file(FILE *fp,char * contents);

main(int argc, char const *argv[])
{

    char *str = malloc(256);

    puts("say something");
    gets(str);
    printf("that length is %d\n",strlen(str));

    FILE *fp;
    fp = fopen("sample1.txt","w");


    write_string_to_file(fp,str);



    return 0;
}

void write_string_to_file(FILE *fp,char * contents){
    if(fp==NULL)
    {
        printf("error while writing some file\n");
        exit(1);
    }
    fprintf(fp,contents);
    fprintf(fp,"\n");
    fprintf(fp,"some junk file content and some others\0\n");
    fputs("this is time travel \n",fp);
    fprintf(fp,"some junk file content and some others\n");
    fclose(fp);
}


