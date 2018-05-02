#include <stdio.h>  
#include <time.h>  
#include <unistd.h>  

//关于时间的一些函数
int timeFrom1970();


void elapsed_time() 
{ 
printf("Elapsed time:%u secs.\n",clock()/CLOCKS_PER_SEC); 
}

void timediff();

void usingClock();

int main(int argc, char *argv[]){ //argc指的是传入的参数的个数，argv是一个指针数组，指向传递给程序的每一个参数
//    timediff();
    // elapsed_time();
    // usingClock();

    struct tm *ptr; 
    time_t lt; 
    lt =time(NULL); 
    ptr=gmtime(&lt); 
    printf(asctime(ptr)); 
    printf(ctime(&lt)); 
    return 0; 

}

void timediff(){
      time_t start_t, end_t;  
   double diff_t;  
  
  
   printf("program started...\n");  
   time(&start_t);  
  
  
   printf("sleep 1 seconds...\n");  
   sleep(1);  
  
  
   time(&end_t);  
   diff_t = difftime(end_t, start_t);  
  
  
   printf("the difference of time = %f\n", diff_t);  
   printf("program exiting...\n");  
}

int timeFrom1970(){
  time_t seconds;  
  seconds = time(NULL);  
  printf("自 1970-01-01 起的小时数 = %ld\n", seconds/3600);  
}

void usingClock(){
    clock_t start,end;
    printf("using clock began----\n");
    start = clock();
    sleep(3);  
    end = clock();
    printf("using clock end----\n");
    double duration = (double)(end-start)/CLOCKS_PER_SEC;
    printf("this program has cost me %f seconds\n",duration);
}

