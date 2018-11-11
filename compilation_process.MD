## 编译链接过程的一些注意事项：

[compiling-c-code-an-exploration-of-the-process](https://medium.com/@mirandarevans/compiling-c-code-an-exploration-of-the-process-63be7b02c30e)
[what-happens-when-you-type-gcc-main-c](https://medium.com/@LeeJulija/what-happens-when-you-type-gcc-main-c-8938da55f722)
[stages-of-compilation-process](https://medium.com/@minas_anton/stages-of-compilation-process-8ac4ead4a21)

编译过程可以传一些flag(无论是gcc还是clang都是一样的)
preprocessor -E  ##handle #include define
compiler -S ##translate C to assembly(生成.s文件)
assembler -c ## translate assembly to object file(.o，文件是针对特定cpu,platform的,.o文件是不可执行的)
linker bring together object file to produce executable

如果没有-E -S或者-c的话，就goes all the way down to executable
-O 是指定最终生成的executable的名称的

1. 链接过程中缺少了相关目标文件(.o)
测试代码:
```c
//main.c

int main()
{
    test();
}

//test.c
#include <stdio.h>
void test()
{
    printf("test\n");
}

//test.h
void test();
```

首先生成两个.o文件: 
gcc -c test.c //生成test.o
gcc -c main.c //生成main.o

然后试着链接两个.o文件
gcc -o main main.o

出错了！
main.o: In function `main':
main.c:(.text+0x15): undefined reference to `test'
collect2: error: ld returned 1 exit status

这就是典型的undefined reference错误，因为在链接的时候发现找不到test函数的实现。
改成下面这种就好了
gcc -o main main.o test.o

上面的过程其实是编译和链接两部分开了:
gcc -o main main.c // 其实是生成.o文件直接链接，然后在链接阶段还是会出现上面的错误
gcc -o main main.c test.c //这样就可以了

2. 链接时缺少相关的库文件(.a/.so文件)
以静态库为例
测试代码:
```c
//main.c

int main()
{
    test();
}

//test.c
#include <stdio.h>
void test()
{
    printf("test\n");
}
//test.h
void test();
```

先把test.c编译成静态库文件(.a)
gcc -c test.c
ar -rc test.a test.o //生成test.a文件

接下来开始编译main.c
gcc -c main.c

链接
gcc -o main main.o
报错！
➜  test (master) ✗ gcc -o main main.o
main.o: In function `main':
main.c:(.text+0x15): undefined reference to `test'
collect2: error: ld returned 1 exit status

原因也是找不到test函数的实现
改成下面这种就可以了
gcc -o main main.o ./test.a //其实就是告诉了它test.a的路径

也可以把两部分为一步： gcc -o main main.c ./test.a //加上test.a是为了告诉它test.a的路径

3. 链接的库文件中又使用了另一个库文件
还是上面的例子
```c
//main.c

int main()
{
    test();
}

//test.c
#include <stdio.h>
void test()
{
    printf("test\n");
}

//test.h
void test();

// func.h
void func();

//func.c
#include <stdio.h>
void func()
{
    printf("executing func!\n");
}
```

首先是生成.o文件
gcc -c func.c
gcc -c test.c
gcc -c main.c

然后打包静态库文件
ar -rc func.a func.o
ar -rc test.a test.o

接下里准备将main.o链接为可执行程序
gcc -o main main.o ./test.a
test.a(test.o): In function `test':  
test.c:(.text+0x13): undefined reference to `func'  
collect2: ld returned 1 exit status 

正确的做法是需要把func.a的路径也给添加进来
gcc -o main main.o test.a func.a 
所以如果我们的库或者在程序中引用到了第三方库，那么同样需要在链接的时候给出第三方库的路径和库文件，否则会得到undefined reference的错误

4. 多个库文件链接的顺序问题
依赖其他库的库一定要放到被依赖库的前面，这样才能真正避免undefined reference的错误
越是基础的库越要写在后面,无论是静态还动态

5.  在c++代码中链接c语言的库
```c
//test.c
#include <stdio.h>
void test()
{
    printf("hey there!\n");
}
//test.h
void test();
```
打包成静态库:
gcc -c test.c
ar -rc test.a test.o

接下来在c++里写main.cpp
```c++
// main.cpp
#include "test.h"
int main()
{
    test();
    return 1;
}
```
编译main.cpp生成可执行程序
g++ -o main main.cpp test.a
/tmp/ccJjiCoS.o: In function `main': 
main.cpp:(.text+0x7): undefined reference to `test()' 
collect2: ld returned 1 exit status 

原因是cpp代码调用C语言的函数时需要把include c相关的头文件用extern "C"包起来:
```c++
extern "C"
{
    #include "test.h"    
}

int main()
{
    test();
    return 1;
}
```
g++ -o main main.cpp test.a //就没有问题了

