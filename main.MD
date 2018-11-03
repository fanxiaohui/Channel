
[<stdlib.h>中定义了两个有用的宏](https://www.gnu.org/software/libc/manual/html_node/Exit-Status.html)
Macro: int EXIT_SUCCESS
This macro can be used with the exit function to indicate successful program completion.
On POSIX systems, the value of this macro is 0. On other systems, the value might be some other (possibly non-constant) integer expression.

Macro: int EXIT_FAILURE
This macro can be used with the exit function to indicate unsuccessful program completion in a general sense.

On POSIX systems, the value of this macro is 1. On other systems, the value might be some other (possibly non-constant) integer expression. Other nonzero status values also indicate failures. Certain programs use different nonzero status values to indicate particular kinds of "non-success". For example, diff uses status value 1 to mean that the files are different, and 2 or more to mean that there was difficulty in opening the files.

Don’t confuse a program’s exit status with a process’ termination status. There are lots of ways a process can terminate besides having its program finish. In the event that the process termination is caused by program termination (i.e., exit), though, the program’s exit status becomes part of the process’ termination status.

 can be used as the argument to the exit function to return unsuccessful or successful termination status, respectively, to the host environment;
这两个macro(宏)是程序调用exit函数时传入的参数，是给host environment看的



编译方式
> gcc 002.c -o 002

或者使用
> gcc -std=c99 002.c -o 002 

运行方式
./002

main函数里面是有参数的，
```c
int main(int argc,char *argv[ ]){
        for(int i=0; i<argc;i++)
        {
            printf(" ==== the args in postion %d is %s\n",i,argv[i]);
        }
    return 0    
}
```

./bin/server 8909 1902 misssyou ##参数之间用空格分开
==== the args in postion 0 is ./bin/server ## (第一个参数是当前文件的文件路径)
==== the args in postion 1 is 8909 () ## 依次如下，参数是存放在一个数组里面的
==== the args in postion 2 is 1902
==== the args in postion 3 is misssyou