#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

extern int errno ;

int main ()
{
   FILE * pf;
   int errnum;
   pf = fopen ("unexist.txt", "rb");
   if( access( "stringatio.c", F_OK ) != -1 ) {
    // file exists
        puts("that file exists!");
    } else {
        // file doesn't exist
        puts("file doesn't exist");
    }
   if (pf == NULL)
   {
      errnum = errno;
      fprintf(stderr, "Value of errno: %d\n", errno);
      perror("Error printed by perror");
      fprintf(stderr, "Error opening file: %s\n", strerror( errnum ));
   }
   else
   {
      fclose (pf);
   }
   return 0;
}