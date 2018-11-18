#include <stdio.h>

#include<time.h>

int main(void) {

	time_t timep;

	time(&timep);

	printf("%s\n",ctime(&timep)); // Sun Sep  2 11:14:01 2018

	return 0;

}