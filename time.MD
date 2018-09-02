C语言时间函数


1. time(time_t *t)函数用于获取当前时间戳
```c
#include<stdio.h>

#include<time.h>

int main(){
	time_t timep;

	long seconds = time(&timep);

	printf("%ld\n",seconds); //time_t其实就是个long ,打印出来的是1535857354这种

	printf("%ld\n",timep); //这里打印出来的是当前的时间戳(UTC,北京时间的话还得+8)，以秒为单位

	return 0;
}
```

2.ctime(const time_t *timep)函数，用于获取本地时间(返回的是一个字符串形式的本地时间表示)
```c
#include <stdio.h>

#include<time.h>

int main(void) {

	time_t timep;

	time(&timep);

	printf("%s\n",ctime(&timep)); // Sun Sep  2 11:14:01 2018

	return 0;

}
```

3. 结构体的方式struct tm *gmtime(const time_t *timep)(给一个long的时间戳转化成tm的结构体)
```c
#include <stdio.h>

#include<time.h>

int main(void) {
	char *wday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};

	time_t timep;

	struct tm *p;

	time(&timep);

	p = gmtime(&timep);

	printf("%d/%d/%d ",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);

	printf("%s %d:%d:%d\n",wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec); //还是UTC时间

	return 0;

}
```

4.asctime() char *asctime(const struct tm *timeptr)
```c
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
int main(void) {

time_t timep;

time(&timep);
printf("%s\n",asctime(gmtime(&timep))); // Sun Sep  2 07:18:52 2018 还是UTC时间

return EXIT_SUCCESS;

}

```

5. 本地时间localtime
```c
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

int main(void) {
	char *wday[] = {"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
	time_t timep;
	struct tm *p;
	time(&timep);
	p = localtime(&timep);
	printf("%d/%d/%d ",(1900+p->tm_year),(1+p->tm_mon),p->tm_mday);
	printf("%s %d:%d:%d\n",wday[p->tm_wday],p->tm_hour,p->tm_min,p->tm_sec);  
	// 2018/9/2 Sun 15:23:29 这回输出的就是本地时间了
	return EXIT_SUCCESS;
}
```

6. mktime函数 （给一个tm的结构体，转化成时间戳long）
time_t mktime(struct tm *timeptr);
```c
#include <stdio.h>

#include <stdlib.h>

#include<time.h>



int main(void) {

	time_t timep;//还记得这个time_t其实就是一个long

	struct tm *p;

	time(&timep);

	printf("time():%ld\n",timep);
	// time():1535873350
	p = localtime(&timep);

	timep = mktime(p);

	printf("time()->localtime()->mktime():%ld\n",timep);//mktime的意思
	// time()->localtime()->mktime():1535873350

	return EXIT_SUCCESS;

}
```

7. gettimeofday函数
这里引入两个linux下的结构体
```c
struct timeval{
	long tv_sec; /*秒*/
	long tv_usec; /*微秒*/
};
struct timezone{
	int tz_minuteswest; /*和greenwich时间差了多少分钟*/
	int tz_dsttime; /*日光节约时间的状态*/
}
```

总结一下，时间戳用time_t(long)的类型表示，都是以秒为单位。
时间对应的结构体是tm
tm这个结构体的定义是:
```c
struct tm
{
    int tm_sec;   // seconds after the minute - [0, 60] including leap second
    int tm_min;   // minutes after the hour - [0, 59]
    int tm_hour;  // hours since midnight - [0, 23]
    int tm_mday;  // day of the month - [1, 31]
    int tm_mon;   // months since January - [0, 11]
    int tm_year;  // years since 1900
    int tm_wday;  // days since Sunday - [0, 6]
    int tm_yday;  // days since January 1 - [0, 365]
    int tm_isdst; // daylight savings time flag
};
```

time_t -> tm (gmtime函数)
tm -> time_t (mktime函数)

[c语言时间函数](http://blog.51cto.com/chenqiangjsj/536705)


