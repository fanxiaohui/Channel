#include <stdio.h>
#include <string.h>

// write contents to a file ,create if non exists
int file_write_string_to_file(char *file_path,char * contents);

//read contents from a file ,won't check if exists
char* file_read_content_from_file(char *file_path);

//append contents to a file
int append_contents_to_a_file(char *file_path,char * contents);

//check if a file exists
int file_exits(char * file_path);

const char *readLine(FILE *file);

int file_rename(char *old_path,char* new_path);

//return the file pointer
int file_create_empty_file(char *filepath);

