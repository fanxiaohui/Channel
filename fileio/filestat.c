#include <event2/event.h>
#include <event2/buffer.h>
#include <event2/http.h>
#include <sys/stat.h>
#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_FILE "sample.txt"

char *filedata;
time_t lasttime = 0;
char filename[80];
int counter = 0;

struct event *loadfile_event;
struct timeval tv;

void read_file()
{
    unsigned long size = 0;
    char *data;
    struct stat buf;

    memset(filename, 0, sizeof(filename));
    strcpy(filename, &DEFAULT_FILE);

    if (stat(filename, &buf) < 0)
    {
        printf("Read file error! \n");
        return;
    }

    FILE *f = fopen(DEFAULT_FILE, "rb");
    if (f == NULL)
    {
        fprintf(stderr, "Couldn't open file\n");
        return;
    }

    size = buf.st_size;
    printf("size of the file in bytes %lld \n", buf.st_size);
    printf("time of creation of the file: %ld \n", buf.st_ctime);
    printf("time of last modification of the file:: %ld\n", buf.st_mtime);
    printf("time of last access of the file:  %ld \n", buf.st_atime);


    filedata = (char *)malloc((int)size + 1);
    memset(filedata, 0, size + 1);
    fread(filedata, sizeof(char), size, f);
    fclose(f);

    fprintf(stderr, " file size is (%lu bytes)\n", size);
    lasttime = buf.st_mtime;
}

int main(int argc, char const *argv[])
{
    /* code */
    read_file();
    return 0;
}
