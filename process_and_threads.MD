## 进程和线程
进程是资源分配的最小单位，线程是CPU调度的最小单位

### 进程
多进程之间内存不共享，挂了一个其他没影响

### 线程
多线程之间共享内存，一个线程挂了整个进程就挂掉



## 1.进程
 linux上查看当前系统运行的进程
 - ps -eo pid,ppid,comm,cmd | head //查看所有进程
 - pstree 
 - ps -ef | grep 'defunct' | grep -v 'grep' //查看僵尸进程


 signal.h头文件中提供了signal()函数，简单来讲，就是注册一个接收到特定信号的回调

 可以通过kill pid发出信号,通过kill -l查看所有的signal信号
 HUP INT QUIT ILL TRAP ABRT EMT FPE KILL BUS SEGV SYS PIPE ALRM TERM URG STOP TSTP CONT CHLD TTIN TTOU IO XCPU XFSZ VTALRM PROF WINCH INFO USR1 USR2
 常用的有SIGTERM（15） ，SIGKILL（9），SIGSTOP（19进程停止），SIGCONT（18进程继续）

 
 