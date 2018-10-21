[参考](http://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/)

假设有这么三份文件
hellomake.c	
```c
#include <hellomake.h>

int main() {
  // call a function in another file
  myPrintHelloMake();

  return(0);
}
```

hellofunc.c
```c
#include <stdio.h>
#include <hellomake.h>

void myPrintHelloMake(void) {

  printf("Hello makefiles!\n");

  return;
}
```

hellomake.h
```c
/*
example include file
*/
void myPrintHelloMake(void);
```
很简单是吧，下面的命令能够生成名为hellomake的可执行文件
> gcc -o hellomake hellomake.c hellofunc.c -I. ##-I .的意思是告诉gcc在当前目录下自己去找hellomake.h文件

- 下面开始写MakeFile

###  第一种:
```
hellomake: hellomake.c hellofunc.c
    gcc -o hellomake hellomake.c hellofunc.c -I.
```
只要hellomake.c或者hellofunc.c中的任一文件有改动,make就知道需要重新编译。

### 第二种：
```
CC=gcc
CFLAGS=-I.

hellomake: hellomake.o hellofunc.o
     $(CC) -o hellomake hellomake.o hellofunc.o
```
这种写法指定了gcc为编译器，并在执行命令的时候传入了命令行参数。编译器会看到.o文件，自己去找对应的.c文件生成.o文件。
但是这样写还是有问题，因为如果你修改了.h文件，make不会重新编译.c文件。所以看下面的改进版

### 第三种:
```
CC=gcc
CFLAGS=-I.
DEPS = hellomake.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: hellomake.o hellofunc.o 
	$(CC) -o hellomake hellomake.o hellofunc.o 
```
很明显可以看到多了一个DEPS，就是告诉编译器，哪些.h文件是我们需要依赖的。这么写就等于说,hellomake里面的.o文件除了依赖对应的.c文件之外，还依赖于DEPS里面的.h文件
-c的意思是让编译器生成.o文件
-o $@的意思是让生成的.o文件名为:左边的名字
$< 是依赖链中的第一个(the $< is the first item in the dependencies list，不是很懂)

### 第四种：
```
CC=gcc
CFLAGS=-I.
DEPS = hellomake.h ##所有的依赖都定义在macro DEPS里面
OBJ = hellomake.o hellofunc.o  ## 所有的object files都定义在macro OBJ里面

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
```
$@就是:左边的名字，$^就是:右边的名字
%.o: %.c $(DEPS)就是定义了一条规则，所有的.o文件依赖于对应的.c文件和DEPS里面的文件（后者改了前面就得重新编译）
所以下面这段
hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
就等同于
hellomake: hellomake.o hellofunc.o
    gcc -o hellomake hellomake.o hellofunc.o -I.
   
对不对？        

### 第五种，也就是实际项目中用到的
```
IDIR =../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =../lib

LIBS=-lm ## 这个是math library

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = hellomake.o hellofunc.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
```

.
|____include
| |____hellomake.h
|____lib
|____src
| |____hellofunc.c
| |____hellomake
| |____hellomake.c
| |____Makefile
| |____obj
| | |____hellofunc.o
| | |____hellomake.o


Makefile放在src文件夹里面，所有的include文件放在include文件夹里，目录结构大致长上面这样
make clean会把obj文件夹下的所有.o文件删掉
PHONY的意思是碰到一个叫做clean的文件不要管

cd 到src文件，去make吧



