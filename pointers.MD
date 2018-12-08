### 指针
指针的sizeof和指针指向的数据类型没什么太大关系，事实上，这取决于你的计算机。
[What is the size of a pointer in C?](https://stackoverflow.com/questions/916051/are-there-any-platforms-where-pointers-to-different-types-have-different-sizes)
另外，指针的类型一旦确定就不能再更改。

有没有那种类似于 a!=null的判断，不然每次都segmentfault很烦人啊。
这个涉及到野指针和迷途指针（悬垂指针），前者是指刚创建的指针变量不会被自动设为NULL指针，默认值是瞎分配的。后者是指指针指向的对象呗收回，但是对这个指针却没有做任何修改，所以这个指针指向的地方是已经被回收的地址。通常，程序往迷途指针指向的内存地址写入数据，会导致不可预料的程序错误。在linux上通常导致段错误，在Windows上导致一般保护错误。

防止野指针：
- 指针变量在定义的时候应该初始化为合法的内存或者NULL
- malloc/free、 new/delete应该成对出现，不要混用
- 申请堆内存之后，应该用if判断指针是否为NULL
- 使用完指针之后，应该立即将指针置为NULL


本质上讲，变量名、数组名，函数名这些都是地址的助记符，编译器会把这些东西以及他们对应的数据类型、地址、作用域等信息存到一个叫做符号表的数据结构中。变量名只存在于源代码中，在完成编译、链接之后，都会被替换为响应的地址，所以在内存中并不存在所谓的变量名。

```c
#include <stdio.h>
#include <stdlib.h>

void func1(void){}
void func2(void){}
void func3(void){}


int main(int argc, char const *argv[])
{
   printf("func1: %p, func2: %p, func3: %p\n",func1,func2,func3);
    return 0;
}
```
输出
// func1: 0x10d74fef0, func2: 0x10d74ff00, func3: 0x10d74ff10


### 数组
数组中的数据类型只能有一种


### 动态分配内存
malloc和用于运行期动态分配内存，需要stdlib.h文件声明
> note: include '<stdlib.h>' or provide a declaration of 'malloc'

```c
buffer = (char *) malloc(sizeof(char)*fileSize); //接受一个参数，表示需要申请的内存大小
description = realloc(description,50*sizeof(char)); //接受两个参数，原指针和新的内存大小
```
realloc用于重新为指针分配内存
calloc会在分配内存的同时帮忙初始化为0

```c
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DEFAULT_FILE "sample.txt"
char filename[80];

memset(filename, 0, sizeof(filename));
strcpy(filename, DEFAULT_FILE); //这样会segmentfalut的（从一个不存在的src去读）
strcpy(filename, &DEFAULT_FILE); //如果没有初始化filename的话，这也会崩(写进一个不存在的dst)
//因为strcpy的第二个参数是字符串的指针，"sample.txt"这个字符串的实际值被拿来当指针，指向了一段不存在的内存，自然会崩。 Crash or “segmentation fault” when data is copied/scanned/read to an uninitialized pointer 
strcpy(filename, &DEFAULT_FILE);//这样就不会崩了

```
