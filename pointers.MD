### 指针
指针的sizeof和指针指向的数据类型没什么太大关系，事实上，这取决于你的计算机。
[What is the size of a pointer in C?](https://stackoverflow.com/questions/916051/are-there-any-platforms-where-pointers-to-different-types-have-different-sizes)
另外，指针的类型一旦确定就不能再更改。


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


