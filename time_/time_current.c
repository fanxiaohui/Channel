#include<stdio.h>

#include<time.h>

int main(){
	time_t timep;

	long seconds = time(&timep);

	printf("%ld\n",seconds); //time_t其实就是个long ,打印出来的是1535857354这种

	printf("%ld\n",timep); //这里打印出来的是当前的时间戳(UTC,北京时间的话还得+8)，以秒为单位

	return 0;
}