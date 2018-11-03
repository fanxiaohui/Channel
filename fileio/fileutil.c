#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

// write contents to a file ,won't check if exists
int file_write_string_to_file(char *file_path,char * contents){
   FILE *fp = NULL;
   fp = fopen(file_path, "w+");
   if(fp < 0 ){
        perror("error fopen file ");
	    exit(1);
   }
   int res = fprintf(fp, "%s",contents);
   fclose(fp);
   if(res!=EOF){
        return 1;
   }else {
       return 0;
   }
}

int append_contents_to_a_file(char *file_path,char * contents)
{
   FILE *fp = NULL;
   fp = fopen(file_path, "a");
   if(fp < 0 ){
        perror("error fopen file ");
	    exit(1);
   }
   int res = fprintf(fp, "%s",contents);
   fclose(fp);
   if(res!=EOF){
        return 1;
   }else {
       return 0;
   } 
}



//read contents from a file,remember to free the result
char* file_read_content_from_file(char *file_path){
    char *source = NULL;
    FILE *fp = fopen(file_path, "r");
    if (fp != NULL) {
        /* Go to the end of the file. */
        if (fseek(fp, 0L, SEEK_END) == 0) {
            /* Get the size of the file. */
            long bufsize = ftell(fp);
            if (bufsize == -1) { /* Error */ }

            /* Allocate our buffer to that size. */
            source = malloc(sizeof(char) * (bufsize + 1));

            /* Go back to the start of the file. */
            if (fseek(fp, 0L, SEEK_SET) != 0) { /* Handle error here */ }

            /* Read the entire file into memory. */
            size_t newLen = fread(source, sizeof(char), bufsize, fp);
            if (newLen == 0) {
                fputs("Error reading file", stderr);
            } else {
                source[newLen] = '\0'; /* Just to be safe. */
            }
        }
        fclose(fp);
    }

    // free(source); /* Don't forget to call free() later! */
    return source;
}

//check if a file exists
int file_exits(char * fname){
    if( access(fname, F_OK ) != -1 ) {
        // file exists
        return 1;
    } else {
        // file doesn't exist
        return 0;
    }
}

// read file line by line，this is how you use it
// while (!feof(myFile)) {
//     const char *line = readLine(myFile);
//     printf("%s\n", line);
// }
const char *readLine(FILE *file) {
    if (file == NULL) {
        printf("Error: file pointer is null.");
        exit(1);
    }

    int maximumLineLength = 128;
    char *lineBuffer = (char *)malloc(sizeof(char) * maximumLineLength);

    if (lineBuffer == NULL) {
        printf("Error allocating memory for line buffer.");
        exit(1);
    }

    char ch = getc(file);
    int count = 0;

    while ((ch != '\n') && (ch != EOF)) {
        if (count == maximumLineLength) {
            maximumLineLength += 128;
            lineBuffer = realloc(lineBuffer, maximumLineLength);
            if (lineBuffer == NULL) {
                printf("Error reallocating space for line buffer.");
                exit(1);
            }
        }
        lineBuffer[count] = ch;
        count++;

        ch = getc(file);
    }

    lineBuffer[count] = '\0';
    char line[count + 1];
    strncpy(line, lineBuffer, (count + 1));
    free(lineBuffer);
    const char *constLine = line;
    return constLine;
}


int file_rename(char *old_path,char* new_path){
    /* rename example */
  int result;
  if(!file_exits(old_path)){
    perror( "old file does't exists!" );
    return -1;
  }
  result= rename( old_path , new_path );
  if ( result == 0 ){
    printf("successfully rename %s to %s \n",old_path,new_path);
    return 1;
  }
  else{
    perror( "Error renaming file" );
    return 1;
  }
}

int file_create_empty_file(char *filepath){
   FILE *fp = fopen(filepath ,"a");
   if(fp!=NULL){
       fclose(fp);
       return 1;
   }else {
       return 0;
   }
}

