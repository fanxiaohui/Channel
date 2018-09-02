#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	printf("starting creating a directory\n");
	int status;
	status = mkdir("stuff",0755);
	if(status!=0){
		printf("bad stuff\n");
	}	else
	{
		printf("that file exits");
	}
	
	return 0;
}
