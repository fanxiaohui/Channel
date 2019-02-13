## C语言中如何使用创建和使用第三方库

pkg-config使用方式

## static library和shared(dynamic) library(关于.so和.a文件)
library是在C程序编译的最后一步被link的，有两种链接方式：static和dynamic.
static library通常运行速度要比shared libiary要快一点（因为一些常用的object已经被打进可执行文件了）

### 创建和使用一个静态库很简单
> ar -rc liball.a *.o //linux上 打一个静态库很简单 
gcc -g -o prog prog.o liball.a //在linux上用一个static库也还算简单

唯一的缺点在于static library比较大，而且，改了之后得重新编译并且链接

### 创建和使用shared library就头疼了
shared library是动态链接的(也就是说只是包含了library的address，真正的链接是在run-time发生的，所有的函数都在一个特定的位置，所有的程序都能共用，也就省了空间)

[接下来是关于创建使用链接so文件的教程](https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html)
示例代码
```C
// foo.h:
#ifndef foo_h__
#define foo_h__
 
extern void foo(void);
 
#endif  // foo_h__

// foo.c
#include <stdio.h>
 
 
void foo(void)
{
    puts("Hello, I'm a shared library");
}

// main.c
#include <stdio.h>
#include "foo.h"
 
int main(void)
{
    puts("This is a shared library test...");
    foo();
    return 0;
}
```
>gcc -c -Wall -Werror -fpic foo.c //Compiling with Position Independent Code
gcc -shared -o libfoo.so foo.o // Creating a shared library from an object file，到这里，一个so文件(shared library就创建好了)

那么使用呢？
gcc -Wall -o test main.c -lfoo //链接，不出意外的话，这里会报错
/usr/bin/x86_64-linux-gnu-ld: cannot find -lfoo
collect2: error: ld returned 1 exit status

看来是在链接的阶段报错了，那么告诉gcc去哪找shared library（libfoo.so，lfoo就是libfoo.so）吧
gcc -L/home/username/foo -Wall -o test main.c -lfoo //假设当前的工作目录是/home/username/foo的话
这下生成了一个test的可执行文件
./test
./test: error while loading shared libraries: libfoo.so: cannot open shared object file: No such file or directory

这就是在运行期找不到这个library了，有两种解决方案，LD_LIBRARY_PATH和rpath
export LD_LIBRARY_PATH=/home/username/foo:$LD_LIBRARY_PATH
// 其实这样也行是吧export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
./test就没有问题了
This is a shared library test...
Hello, I'm a shared library

但这么干等于破坏了环境变量（unset LD_LIBRARY_PATH可以恢复的），接下来使用rpath(run path)
rpath在链接的时候设置library的位置
gcc -L/home/username/foo -Wl,-rpath=/home/username/foo -Wall -o test main.c -lfoo
./test
This is a shared library test...
Hello, I'm a shared library

-Wl… 是 gcc 傳給 static linker 的參數，參閱 [man ld](http://man7.org/linux/man-pages/man1/ld.1.html)。

以上就是创建，链接，使用.so库的方式，如果想要让系统上的所有人都能使用我们的库怎么办呢？首先这需要admin权限
接下来把我们刚才的.so文件复制到特定的文件夹里(/usr/lib或者/usr/local/lib。这俩文件夹一般都需要管理员权限的)
cp /home/username/foo/libfoo.so /usr/lib
chmod 0755 /usr/lib/libfoo.so
ldconfig //让ldconfig刷新一下缓存
ldconfig -p | grep foo
libfoo.so (libc6) => /usr/lib/libfoo.so

>原来:Linux是通过 /etc/ld.so.cache 文件搜寻要链接的动态库的。
而 /etc/ld.so.cache 是 ldconfig 程序读取 /etc/ld.so.conf 文件生成的。
（注意， /etc/ld.so.conf 中并不必包含 /lib 和 /usr/lib，ldconfig程序会自动搜索这两个目录）

如果我们把 libmax.so 所在的路径添加到 /etc/ld.so.conf 中，再以root权限运行ldconfig 程序，更新/etc/ld.so.cache ，test运行时，就可以找到libmax.so。


以上完成之后
gcc -Wall -o test main.c -lfoo //因为现在在/usr/lib里面已经有我们之前复制过去的so文件了。
$ ldd test | grep foo //ldd类似于查看二进制文件，就是确认下这个可执行文件用的是不是我们刚才复制过去的libfoo.so
libfoo.so => /usr/lib/libfoo.so (0x00a42000) //看上去没问题

$ ./test
This is a shared library test...
Hello, I'm a shared library
到此一切OK！

[上述内容出自](https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html)



Linux gcc链接规则：


链接的时候查找顺序是:
1. -L 指定的路径, 从左到右依次查找
2. 由 环境变量 LIBRARY_PATH 指定的路径,使用":"分割从左到右依次查找
3. /etc/ld.so.conf 指定的路径顺序
4. /lib 和 /usr/lib (64位下是/lib64和/usr/lib64)

动态库调用的查找顺序:
1. ld的-rpath参数指定的路径, 这是写死在代码中的
2. ld脚本指定的路径
3. LD_LIBRARY_PATH 指定的路径
4. /etc/ld.so.conf 指定的路径(这里面指定了/usr/local/bin)
5. /lib和/usr/lib(64位下是/lib64和/usr/lib64)

一般情况链接的时候我们采用-L的方式指定查找路径, 调用动态链接库的时候采用LD_LIBRARY_PATH的方式指定链接路径


比方说json-c就指出了如何使用的方式:
先把json-c这个库安装上
Makefile里面
如果有pkg-config的话
```
CFLAGS += $(shell pkg-config --cflags json-c)
LDFLAGS += $(shell pkg-config --libs json-c)
```
如果没有pkg-config的话
```
JSON_C_DIR=/path/to/json_c/install
CFLAGS += -I$(JSON_C_DIR)/include/json-c
LDFLAGS+= -L$(JSON_C_DIR)/lib -ljson-c
```

