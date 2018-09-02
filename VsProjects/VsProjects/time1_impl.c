#include "time1.h"


void simply_print_time() {

	time_t timep;

	long seconds = time(&timep);

	printf("%ld\n", seconds);

	printf("%ld\n", timep);


	time(&timep);

	printf("%s\n", ctime(&timep));

	printf("asctime %s\n", asctime(gmtime(&timep)));

}

void more_complex_time() {

	char *wday[] = { "Sun","Mon","Tue","Wed","Thu","Fri","周六" };

	time_t timep;

	struct tm *p;

	time(&timep);

	p = gmtime(&timep);

	printf("%d/%d/%d \n", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday); // 2018 9 1

	printf("%s %d:%d:%d\n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec); //周六 14 36 44 UTC时间
}

void show_local_time() {
	char *wday[] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

	time_t timep;

	struct tm *p;

	time(&timep);

	p = localtime(&timep);

	printf("%d/%d/%d ", (1900 + p->tm_year), (1 + p->tm_mon), p->tm_mday);

	printf("%s %d:%d:%d\n", wday[p->tm_wday], p->tm_hour, p->tm_min, p->tm_sec);

}

void with_mk_time() {
	time_t timep;

	struct tm *p;

	time(&timep);

	printf("time():%ld\n", timep);

	p = localtime(&timep);

	timep = mktime(p);

	printf("time()->localtime()->mktime():%ld\n", timep);
}

