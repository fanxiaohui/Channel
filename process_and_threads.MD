## 进程和线程
***进程是资源分配的最小单位，线程是CPU调度的最小单位***

### 进程
多进程之间内存不共享，挂了一个其他没影响

### 线程
多线程之间共享内存，一个线程挂了整个进程就挂掉

进程有独立的地址空间，一个进程崩溃后，在保护模式下不会对其它进程产生影响；
而线程只是一个进程中的不同执行路径线程有自己的堆栈和局部变量，但线程没有单独的地址空间，一个线程死掉就等于整个进程死掉；
所以多进程的程序要比多线程的程序健壮，但在进程切换时，耗费资源较大，效率要差一些，但对于一些要求同时进行并且又要共享某些变量的并发操作，只能用线程，不能用进程



## 1.进程
 linux上查看当前系统运行的进程
 - ps -eo pid,ppid,comm,cmd | head //查看所有进程
 - pstree 
 - ps -ef | grep 'defunct' | grep -v 'grep' //查看僵尸进程


 signal.h头文件中提供了signal()函数，简单来讲，就是注册一个接收到特定信号的回调

 可以通过kill pid发出信号,通过kill -l查看所有的signal信号
 HUP INT QUIT ILL TRAP ABRT EMT FPE KILL BUS SEGV SYS PIPE ALRM TERM URG STOP TSTP CONT CHLD TTIN TTOU IO XCPU XFSZ VTALRM PROF WINCH INFO USR1 USR2
 常用的有SIGTERM（15） ，SIGKILL（9），SIGSTOP（19进程停止），SIGCONT（18进程继续）

 ## 2.线程
 头文件：pthread.h，gcc链接时参数：-lpthread；

创建线程
```c
pthread_t tid1
errno = pthread_create(&tid2, NULL, job2, NULL);
if(errno){
        perror("pthread_create");
        exit(EXIT_FAILURE);
}
```

 ## 3. 互斥锁
 [Why you need a mutex to protect an int](http://www.alexonlinux.com/why-you-need-a-mutex-to-protect-an-int) mutex(Mutual exclusion)互斥锁。
 wiki上这样描述硬件的实现原理，在多核系统中就是cas操作
 >单核心系统上最常见的方式就是关闭尽可能多的可能对共享数据段进行读写的指令中断。这样一来就可以避免在临界区域中暂停程序执行，或是来自硬件的要求修改目标共享数据段的中断请求。多核心系统上则通过检查并置位（获取原始值并指定新值）机制达成，当一个核心需要另一个核心占用的资源的时候，该核心将不断的查询所有核心间共享的占用旗标，直到另一个核心将占用旗标复位为未使用为止。


 ### 参考
 [c语言-多线程编程](https://www.zfl9.com/c-pthread.html)
